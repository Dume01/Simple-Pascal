%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int linenum;
extern FILE *yyin;
int yylex();
void yyerror(const char *s);

#include "table.h"
#include "stack.h"
int flag_array=0;
int upl=0;
int tok=0;
int lno=0;
char* newTemp();
char* newLabel();
int ff=0;
int f=0;
char* elsepart=NULL;
char* looppart=NULL;
int re=0;
int charToInt(const char*);
%}

%union {
    char *str;
    struct temp {
        char* tp;
        char* cd;
        char* typ;
    } t;
}

%token <str> IDENTIFIER
%token <str> INT
%token <str> REAL
%token <str> BOOLEAN
%token <str> CHAR
%token <str> INTEGER
%token <str> REALX
%token <str> STRING
%token <str> CHARACTER
%token <str> TRU
%token <str> FAL

%type <str> type variable_declaration

//keywords
%token PROGRAM VAR FOR DO WHILE ARRAY AND OR NOT END READ WRITE

//operators
%token PLUS MINUS MULT DIV MOD ASSIGN NOTEQUAL LESS GREATER LESSEQUAL GREATEREQUAL

//punctuation
%token SEMICOLON COLON COMMA LPAREN RPAREN LBRACKET RBRACKET  TO

%token DOT IF THEN ELSE BEG RANGE OF EQUALS

%type <t> assignment_statement expression primary_expression

%left PLUS MINUS
%left MULT DIV MOD
%left EQUALS NOTEQUAL LESS GREATER LESSEQUAL GREATEREQUAL
%left AND
%left OR
%right NOT

%start program

%%

program: PROGRAM  IDENTIFIER   SEMICOLON  variable_declarations  block  DOT;

variable_declarations:  
                      |   VAR variable_list SEMICOLON
                     ;

variable_list: variable_declaration
             | variable_list SEMICOLON variable_declaration;

variable_declaration: IDENTIFIER_list COLON type
                      {   
                          if(flag_array==0)
                          add_variable_data_type($3,0);
                          else
                          {
                            flag_array=0;
                            add_variable_data_type($3,upl);
                            upl=0;
                          }
                      }
                      ;

IDENTIFIER_list: IDENTIFIER 
                 {  
                    if(isPresent($1)==0)
                    {   
                        add_variable_name($1);
                    }
                    else
                    {
                        yyerror("Redeclaration Of variable");
                    }
                 }
               | IDENTIFIER_list COMMA IDENTIFIER
                  {
                    if(isPresent($3)==0)
                    {
                        add_variable_name($3);
                    }
                    else
                    {
                        yyerror("Redeclaration Of variable");
                    }
                  }
                  ;

type: INT {$$ = "INT";}
    | REAL {$$ = "REAL";}
    | BOOLEAN {$$ = "BOOLEAN";}
    | CHAR {$$ = "CHAR";}
    | ARRAY LBRACKET INTEGER RANGE INTEGER RBRACKET OF type 
      {
        flag_array=1; 
        upl=1;
        $$=$8;
      }
    ;

block: BEG statement_list END;

statement_list: /* empty */
              | statement SEMICOLON statement_list
              | block SEMICOLON;

statement: assignment_statement
         | read_statement
         | write_statement
         | conditional_statement
         | loop_statement;

assignment_statement: IDENTIFIER ASSIGN expression
                      {
                        char* dtm=dataType($1);
                        char* er="SEND ERROR";
                        if(strcmp(dtm,er)==0)
                        {
                            yyerror("Variable not declared\n");
                        }
                        else
                        {   
                            if(strcmp(dtm,$<t.typ>3)==0) 
                            {
                                assign_val_done($1);
                                $<t.cd>$=$<t.cd>3;
                            }
                            else
                            {
                                yyerror("Incompatible datatype");
                            }
                        }
                      }
                      ;

read_statement: READ {re=1;} LPAREN primary_expression RPAREN
                {   
                    re=0;
                }
                ;

write_statement: WRITE LPAREN write_argument_list RPAREN;

write_argument_list: write_argument
                   | write_argument_list COMMA write_argument;

write_argument: STRING
              | primary_expression;

conditional_statement: IF {ff=1;} expression THEN block maybe_else
                       {
                          if(strcmp($<t.typ>3,"BOOLEAN")!=0)
                            yyerror("conditional_statement statement require a boolean type");
                       }
                     ;

maybe_else: { ff=0; char* pp=pop();  } /* empty */
          | ELSE { ff=0;char* pp=pop();   } block
        ;

loop_statement: FOR IDENTIFIER ASSIGN expression TO expression 
                { assign_val_done($2);
                  char* m1=strdup($2);
                  char* m2=strdup(newLabel());
                  char* m3=$<t.tp>6;
                  char* m4=strdup(newLabel());
                  char* m5=strdup(newLabel());                  
                  char* m6=strdup(newTemp());
                  char* m7=strdup(newLabel());
                  elsepart=strdup(m7);
                  if(strcmp($<str>5,"to")==0)
                  {}
                  else
                  looppart=strdup(m2);
                }
                DO block
                {
                    ff=0; 
                    char* pp=pop();
 
                }
              | WHILE {ff=1;} expression DO block {ff=0; char* pp=pop();  };

expression: primary_expression
            {
              $<t.tp>$=$<t.tp>1;
              $<t.cd>$=$<t.cd>1;
              $<t.typ>$=$<t.typ>1;
            }
          | expression PLUS expression 
          { 
            if(strcmp($<t.typ>1,$<t.typ>3)!=0) 
            yyerror("Incompatible datatypes");
            else
            {
                $<t.tp>$ = strdup(newTemp());   
                char* m1=strdup($<t.cd>3);
                if(strcmp(m1,"")!=0)
                  strcat(m1,"");
                char* m2=strdup($<t.cd>1);
                if(strcmp(m2,"")!=0)
                  strcat(m2,"");
                strcat(m2,m1);
                char* m3=strdup($<t.tp>1);
                char* m4=strdup($<t.tp>3);
                char* m6=strdup($<t.tp>$);
                strcat(m6,"=");
                strcat(m3,"+");
                strcat(m3,m4);
                strcat(m6,m3);
                strcat(m2,m6);
                strcat(m2,"\n");
                $<t.cd>$=strdup(m2);
                $<t.typ>$=$<t.typ>1;
            }
          }
          | expression MINUS expression 
          {
            if(strcmp($<t.typ>1,$<t.typ>3)!=0) 
            yyerror("Incompatible datatypes");
            else
            {
                $<t.tp>$ = strdup(newTemp());   
                char* m1=strdup($<t.cd>3);
                if(strcmp(m1,"")!=0)
                  strcat(m1,"");
                char* m2=strdup($<t.cd>1);
                if(strcmp(m2,"")!=0)
                  strcat(m2,"");
                strcat(m2,m1);
                char* m3=strdup($<t.tp>1);
                char* m4=strdup($<t.tp>3);
                char* m6=strdup($<t.tp>$);
                strcat(m6,"=");
                strcat(m3,"-");
                strcat(m3,m4);
                strcat(m6,m3);
                strcat(m2,m6);
                strcat(m2,"\n");
                $<t.cd>$=strdup(m2);
                $<t.typ>$=$<t.typ>1;
            }
          }
          | expression MULT expression  
          {
            if(strcmp($<t.typ>1,$<t.typ>3)!=0) 
            yyerror("Incompatible datatypes");
            else
            {
                $<t.tp>$ = strdup(newTemp());    
                char* m1=strdup($<t.cd>3);
                if(strcmp(m1,"")!=0)
                strcat(m1,"");
                char* m2=strdup($<t.cd>1);
                if(strcmp(m2,"")!=0)
                strcat(m2,"");
                strcat(m2,m1);
                char* m3=strdup($<t.tp>1);
                char* m4=strdup($<t.tp>3);
                char* m6=strdup($<t.tp>$);
                strcat(m6,"=");
                strcat(m3,"*");
                strcat(m3,m4);
                strcat(m6,m3);
                strcat(m2,m6);
                strcat(m2,"\n");
                int len=strlen($<t.cd>$);
                $<t.cd>$=strdup(m2);
                $<t.typ>$=$<t.typ>1;
            }
          }
          | expression DIV expression 
          {
            if(strcmp($<t.typ>1,$<t.typ>3)!=0) 
            yyerror("Incompatible datatypes");
            else
            {
                $<t.tp>$ = strdup(newTemp());     
                char* m1=strdup($<t.cd>3);
                if(strcmp(m1,"")!=0)
                  strcat(m1,"");
                char* m2=strdup($<t.cd>1);
                if(strcmp(m2,"")!=0)
                  strcat(m2,"");
                strcat(m2,m1);
                char* m3=strdup($<t.tp>1);
                char* m4=strdup($<t.tp>3);
                char* m6=strdup($<t.tp>$);
                strcat(m6,"=");
                strcat(m3,"/");
                strcat(m3,m4);
                strcat(m6,m3);
                strcat(m2,m6);
                strcat(m2,"\n");
                $<t.cd>$=strdup(m2);
                $<t.typ>$=$<t.typ>1;

            }
          }
          | expression MOD expression
          { 

            if(strcmp($<t.typ>1,$<t.typ>3)!=0) 
            yyerror("Incompatible datatypes");
            else
            {
                $<t.tp>$ = strdup(newTemp());     
                char* m1=strdup($<t.cd>3);
                if(strcmp(m1,"")!=0)
                  strcat(m1,"");
                char* m2=strdup($<t.cd>1);
                if(strcmp(m2,"")!=0)
                  strcat(m2,"");
                strcat(m2,m1);
                char* m3=strdup($<t.tp>1);
                char* m4=strdup($<t.tp>3);
                char* m6=strdup($<t.tp>$);
                strcat(m6,"=");
                strcat(m3,"%");
                strcat(m3,m4);
                strcat(m6,m3);
                strcat(m2,m6);
                strcat(m2,"\n");
                $<t.cd>$=strdup(m2);
                $<t.typ>$=$<t.typ>1;
            }
          }
          | expression EQUALS expression
          {
            if(strcmp($<t.typ>1,$<t.typ>3)!=0)  
            yyerror("Incompatible datatypes");

            else
            {
                $<t.tp>$ = strdup(newTemp());     
                
                char* m1=strdup("if ");
                strcat(m1,$<t.tp>1);
                strcat(m1," = ");
                strcat(m1,$<t.tp>3);
                strcat(m1," goto ");
                char* lab1= strdup(newLabel());
                char* lab2= strdup(newLabel());
                looppart=strdup(lab2);
                strcat(m1,lab2);
                strcat(m1,"\n");
                char* m2=strdup($<t.tp>$);
                strcat(m2,"= 0");
                strcat(m1,m2);
                strcat(m1,"\n");
                strcat(m1,"goto ");
                strcat(m1,lab1);
                strcat(m1,"\n");
                m2=strdup($<t.tp>$);
                strcat(m2,"= 1");
                strcat(lab2,": ");
                strcat(lab2,m2);
                strcat(m1,lab2);
                strcat(m1,"\n");
                strcat(lab1,": ");    
                if(ff==0)           
                  strcat(m1,lab1);
                else
                {  
                  elsepart = malloc(strlen(lab1) + 1); // Allocate memory for ff1
                  strcpy(elsepart,lab1);
                  insert(elsepart);
                }
                $<t.typ>$=strdup("BOOLEAN");

            }
          }
          | expression NOTEQUAL expression
          {
            if(strcmp($<t.typ>1,$<t.typ>3)!=0)  
            yyerror("Incompatible datatypes");
            else
            {
                $<t.tp>$ = strdup(newTemp());   
                                
                char* m1=strdup("if ");
                strcat(m1,$<t.tp>1);
                strcat(m1," != ");
                strcat(m1,$<t.tp>3);
                strcat(m1," goto ");
                char* lab1= strdup(newLabel());
                char* lab2= strdup(newLabel());
                                looppart=strdup(lab2);
                strcat(m1,lab2);
                strcat(m1,"\n");
                char* m2=strdup($<t.tp>$);
                strcat(m2,"= 0");
                strcat(m1,m2);
                strcat(m1,"\n");
                strcat(m1,"goto ");
                strcat(m1,lab1);
                strcat(m1,"\n");
                m2=strdup($<t.tp>$);
                strcat(m2,"= 1");
                strcat(lab2,": ");
                strcat(lab2,m2);
                strcat(m1,lab2);
                strcat(m1,"\n");
                strcat(lab1,": ");                
                if(ff==0)           
                strcat(m1,lab1);
                else
                {  
                  elsepart = malloc(strlen(lab1) + 1); // Allocate memory for ff1
                  strcpy(elsepart,lab1);
                                    insert(elsepart);
                }
                $<t.typ>$=strdup("BOOLEAN");

            }
          }
          | expression LESS expression
          {
            if(strcmp($<t.typ>1,$<t.typ>3)!=0)  
            yyerror("Incompatible datatypes");
            else
            {
                $<t.tp>$ = strdup(newTemp()); 
                  
                char* m1=strdup("if ");
                strcat(m1,$<t.tp>1);
                strcat(m1," < ");
                strcat(m1,$<t.tp>3);
                strcat(m1," goto ");
                char* lab1= strdup(newLabel());
                char* lab2= strdup(newLabel());
                                looppart=strdup(lab2);
                strcat(m1,lab2);
                strcat(m1,"\n");
                char* m2=strdup($<t.tp>$);
                strcat(m2,"= 0");
                strcat(m1,m2);
                strcat(m1,"\n");
                strcat(m1,"goto ");
                strcat(m1,lab1);
                strcat(m1,"\n");
                m2=strdup($<t.tp>$);
                strcat(m2,"= 1");
                strcat(lab2,": ");
                strcat(lab2,m2);
                strcat(m1,lab2);
                strcat(m1,"\n");
                strcat(lab1,": ");                
                if(ff==0)           
                strcat(m1,lab1);
                else
                {  
                  elsepart = malloc(strlen(lab1) + 1); // Allocate memory for ff1
                  strcpy(elsepart,lab1);
                                    insert(elsepart);
                }
                $<t.typ>$=strdup("BOOLEAN");

            }
          }
          | expression LESSEQUAL expression
          {
            if(strcmp($<t.typ>1,$<t.typ>3)!=0)  
            yyerror("Incompatible datatypes");
            else
            {
                $<t.tp>$ = strdup(newTemp());    
                char* m1=strdup("if ");
                strcat(m1,$<t.tp>1);
                strcat(m1," <= ");
                strcat(m1,$<t.tp>3);
                strcat(m1," goto ");
                char* lab1= strdup(newLabel());
                char* lab2= strdup(newLabel());
                                looppart=strdup(lab2);
                strcat(m1,lab2);
                strcat(m1,"\n");
                char* m2=strdup($<t.tp>$);
                strcat(m2,"= 0");
                strcat(m1,m2);
                strcat(m1,"\n");
                strcat(m1,"goto ");
                strcat(m1,lab1);
                strcat(m1,"\n");
                m2=strdup($<t.tp>$);
                strcat(m2,"= 1");
                strcat(lab2,": ");
                strcat(lab2,m2);
                strcat(m1,lab2);
                strcat(m1,"\n");
                strcat(lab1,": ");                
                if(ff==0)           
                strcat(m1,lab1);
                else
                {  
                  elsepart = malloc(strlen(lab1) + 1); // Allocate memory for ff1
                  strcpy(elsepart,lab1);
                                    insert(elsepart);
                }
                $<t.typ>$=strdup("BOOLEAN");
            }
          }
          | expression GREATER expression
          {
            if(strcmp($<t.typ>1,$<t.typ>3)!=0)  
            yyerror("Incompatible datatypes");
            else
            {
                $<t.tp>$ = strdup(newTemp());     
                char* m1=strdup("if ");
                strcat(m1,$<t.tp>1);
                strcat(m1," > ");
                strcat(m1,$<t.tp>3);
                strcat(m1," goto ");
                char* lab1= strdup(newLabel());
                char* lab2= strdup(newLabel());
                                looppart=strdup(lab2);
                strcat(m1,lab2);
                strcat(m1,"\n");
                char* m2=strdup($<t.tp>$);
                strcat(m2,"= 0");
                strcat(m1,m2);
                strcat(m1,"\n");
                strcat(m1,"goto ");
                strcat(m1,lab1);
                strcat(m1,"\n");
                m2=strdup($<t.tp>$);
                strcat(m2,"= 1");
                strcat(lab2,": ");
                strcat(lab2,m2);
                strcat(m1,lab2);
                strcat(m1,"\n");
                strcat(lab1,": ");                
                if(ff==0)           
                strcat(m1,lab1);
                else
                {  
                  elsepart = malloc(strlen(lab1) + 1); // Allocate memory for ff1
                  strcpy(elsepart,lab1);
                                    insert(elsepart);
                }
                $<t.typ>$=strdup("BOOLEAN");
            }
          }
          | expression GREATEREQUAL expression
          {
            if(strcmp($<t.typ>1,$<t.typ>3)!=0)  
            yyerror("Incompatible datatypes");
            else
            {
                $<t.tp>$ = strdup(newTemp());     
                char* m1=strdup("if ");
                strcat(m1,$<t.tp>1);
                strcat(m1," >= ");
                strcat(m1,$<t.tp>3);
                strcat(m1," goto ");
                char* lab1= strdup(newLabel());
                char* lab2= strdup(newLabel());
                                looppart=strdup(lab2);
                strcat(m1,lab2);
                strcat(m1,"\n");
                char* m2=strdup($<t.tp>$);
                strcat(m2,"= 0");
                strcat(m1,m2);
                strcat(m1,"\n");
                strcat(m1,"goto ");
                strcat(m1,lab1);
                strcat(m1,"\n");
                m2=strdup($<t.tp>$);
                strcat(m2,"= 1");
                strcat(lab2,": ");
                strcat(lab2,m2);
                strcat(m1,lab2);
                strcat(m1,"\n");
                strcat(lab1,": ");                
                if(ff==0)           
                strcat(m1,lab1);
                else
                {  
                  elsepart = malloc(strlen(lab1) + 1); // Allocate memory for ff1
                  strcpy(elsepart,lab1);
                                    insert(elsepart);
                }
                $<t.typ>$=strdup("BOOLEAN");
            }
          }
          | expression AND expression
          {
            if(strcmp($<t.typ>1,$<t.typ>3)!=0)  
            yyerror("Incompatible datatypes");
            else
            {
                $<t.tp>$ = strdup(newTemp());    
                char* m1=strdup($<t.cd>3);
                if(strcmp(m1,"")!=0)
                  strcat(m1,"");
                char* m2=strdup($<t.cd>1);
                if(strcmp(m2,"")!=0)
                  strcat(m2,"");
                strcat(m2,m1);
                char* m3=strdup($<t.tp>1);
                char* m4=strdup($<t.tp>3);
                char* m6=strdup($<t.tp>$);
                strcat(m6,"=");
                strcat(m3,"AND");
                strcat(m3,m4);
                strcat(m6,m3);
                strcat(m2,m6);
                strcat(m2,"\n");                
                $<t.cd>$=strdup(m2);
                $<t.typ>$="BOOLEAN";
            }
          }
          | expression OR expression
          {
            if(strcmp($<t.typ>1,$<t.typ>3)!=0)  
            yyerror("Incompatible datatypes");
            else
            {
                $<t.tp>$ = strdup(newTemp());     
                char* m1=strdup($<t.cd>3);
                if(strcmp(m1,"")!=0)
                  strcat(m1,"");
                char* m2=strdup($<t.cd>1);
                if(strcmp(m2,"")!=0)
                  strcat(m2,"");
                strcat(m2,m1);
                char* m3=strdup($<t.tp>1);
                char* m4=strdup($<t.tp>3);
                char* m6=strdup($<t.tp>$);
                strcat(m6,"=");
                strcat(m3,"OR");
                strcat(m3,m4);
                strcat(m6,m3);
                strcat(m2,m6);
                strcat(m2,"\n");
                $<t.cd>$=strdup(m2);
                $<t.typ>$="BOOLEAN";
            }
          }
        | NOT expression
          {

          }
        ;

primary_expression: IDENTIFIER
                    {   if(re==1)
                        {  assign_val_done($1);}
                        else
                        {char* dtm=dataType($1);
                        char* er="SEND ERROR";
                        if(strcmp(dtm,er)==0 && re==0)
                        {
                            yyerror("Variable not declared");
                        }
                        else if(re==0)
                        {   
                            if(is_Assigned($1)==1)
                            {  
                              $<t.typ>$=dtm;
                              $<t.tp>$=$1;
                              $<t.cd>$="";
                            }
                            else
                              yyerror("Variable not assigned a value");
                        }}
                    }
                  | IDENTIFIER LBRACKET primary_expression RBRACKET
                    {    
                        if(re==1)     
                            assign_val_done($1);  
                        char* dtm=dataType($1);
                        if("%s\n",$1); 
                        char* er="SEND ERROR";

                        if(strcmp(dtm,er)==0 && re==0)
                        {   
                            yyerror("undeclared variable");
                        }
                        else if(re!=0)
                        {
                            if(is_This_Array($1)==0)
                            {
                                yyerror("The variable is not an array and the operation is of an array");
                            }
                            else
                            {   
                                if(strcmp($<t.typ>3,"INT")==0)
                                {
                                    $<t.typ>$=dtm;
                                    $<t.tp>$=$1;
                                    $<t.cd>$="";
                                }       
                                else
                                yyerror("Expected Integer in array index");                      
                            }
                        }   
           
                    }
                  | INTEGER
                    {   
                        $<t.typ>$=dataType_constant("INTEGER");
                        $<t.tp>$=$1;
                        $<t.cd>$="";
                    }
                  | REALX
                    {
                        $<t.typ>$=dataType_constant("REALX");
                        $<t.tp>$=$1;
                        $<t.cd>$="";
                    }
                  | CHARACTER
                    {
                        $<t.typ>$=dataType_constant("CHARACTER");
                        $<t.tp>$=$1;
                        $<t.cd>$="";
                    }
                  | TRU
                    {
                        $<t.typ>$=dataType_constant("TRU");
                        $<t.tp>$=$1;
                        $<t.cd>$="";
                    }
                  | FAL
                    {
                        $<t.typ>$=dataType_constant("FAL");
                        $<t.tp>$=$1;
                        $<t.cd>$="";
                    }
                 | LPAREN expression RPAREN
                    {
                        $<t.typ>$=$<t.typ>2;
                        $<t.tp>$=$<t.tp>2;
                        $<t.cd>$=$<t.cd>2;
                    }
                  ;

%%

void yyerror(const char *s) {
    printf("ERROR: %s \nOn line number %d \n",s,linenum);
    f=1;
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (file) {
            yyin = file;
        } else {
            fprintf(stderr, "Failed to open file %s\n", argv[1]);
            return 1;
        }
    } else {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    yyparse();
    if(f==0)
    print();
    return 0;
}

char* newTemp()
{
    int length = snprintf( NULL, 0, "%d",  tok);
    char* t1 = malloc( length + 1 );
    char* t2=strdup("t");
    snprintf( t1 , length + 1, "%d", tok );
    strcat(t2,t1);
    tok++;
    return t2;
}

char* newLabel()
{
    int length = snprintf( NULL, 0, "%d",  lno);
    char* l1 = malloc( length + 1 );
    char* l2=strdup("l");
    snprintf( l1 , length + 1, "%d", lno );
    strcat(l2,l1);
    lno++;
    return l2;
}