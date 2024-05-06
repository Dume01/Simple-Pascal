%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int linenum;
extern FILE *yyin;
int yylex();
void yyerror(const char *s);

#include "table.h"
int flag_array=0;
int upl=0;
int f=0;
int charToInt(const char*);
int re=0;
%}

%union {
    char *str;
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

%type <str> type variable_declaration assignment_statement expression primary_expression

//keywords
%token PROGRAM VAR FOR DO WHILE ARRAY AND OR NOT END READ WRITE

//operators
%token PLUS MINUS MULT DIV MOD ASSIGN NOTEQUAL LESS GREATER LESSEQUAL GREATEREQUAL

//punctuation
%token SEMICOLON COLON COMMA LPAREN RPAREN LBRACKET RBRACKET

%token DOT IF THEN ELSE TO BEG RANGE OF EQUALS


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
                        yyerror("multiple declartion of variable");
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
                        yyerror("multiple declartion of variable");
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
        upl=charToInt($5);
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
                            yyerror("undeclared variable");
                        }
                        else
                        {   

                            if(strcmp(dtm,dataType($3))==0) 
                            {
                                assign_val_done($1);
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
                    assign_val_done($4);
                    re=0;
                }
                ;

write_statement: WRITE LPAREN write_argument_list RPAREN;

write_argument_list: write_argument
                   | write_argument_list COMMA write_argument;

write_argument: STRING
              | primary_expression;

conditional_statement: IF expression THEN block maybe_else
                       {
                          if(strcmp($2,"BOOLEAN")!=0)
                            yyerror("conditional_statement statement require a boolean type");
                       }
                     ;

maybe_else: /* empty */
          | ELSE block
        ;

loop_statement: FOR assignment_statement TO expression DO block
              | WHILE expression DO block;

expression: primary_expression
            {
              $$=$1;
            }
          | expression PLUS expression 
          { 
            if(strcmp(dataType($1),dataType($3))!=0) 
            yyerror("Incompatible datatypes");
            else
            $$=$1;
          }
          | expression MINUS expression 
          {
            if(strcmp(dataType($1),dataType($3))!=0)
            yyerror("Incompatible datatypes");
            else
            $$=$1;
          }
          | expression MULT expression  
          {
            if(strcmp(dataType($1),dataType($3))!=0)
            yyerror("Incompatible datatypes");
            else
            $$=$1;
          }
          | expression DIV expression 
          {
            if(strcmp(dataType($1),dataType($3))!=0)
            yyerror("Incompatible datatypes");
            else
            $$=$1;
          }
          | expression MOD expression
          {
            if(strcmp(dataType($1),dataType($3))!=0)
            yyerror("Incompatible datatypes");
            else
            $$=$1;
          }
          | expression EQUALS expression
          {
            if(strcmp(dataType($1),dataType($3))!=0)
            yyerror("Incompatible datatypes");
            else
            $$="BOOLEAN";
          }
          | expression NOTEQUAL expression
          {
            if(strcmp(dataType($1),dataType($3))!=0)
            yyerror("Incompatible datatypes");
            else
            $$="BOOLEAN";
          }
          | expression LESS expression
          {
            if(strcmp(dataType($1),dataType($3))!=0)
            yyerror("Incompatible datatypes");
            else
            $$="BOOLEAN";
          }
          | expression LESSEQUAL expression
          {
            if(strcmp(dataType($1),dataType($3))!=0)
            yyerror("Incompatible datatypes");
            else
            $$="BOOLEAN";
          }
          | expression GREATER expression
          {
            if(strcmp(dataType($1),dataType($3))!=0)
            yyerror("Incompatible datatypes");
            else
            $$="BOOLEAN";
          }
          | expression GREATEREQUAL expression
          {
            if(strcmp(dataType($1),dataType($3))!=0)
            yyerror("Incompatible datatypes");
            else
            $$="BOOLEAN";
          }
          | expression AND expression
          {
            if(strcmp(dataType($1),dataType($3))!=0)
            yyerror("Incompatible datatypes");
            else
            $$="BOOLEAN";
          }
          | expression OR expression
          {
            if(strcmp(dataType($1),dataType($3))!=0)
            yyerror("Incompatible datatypes");
            else
            $$="BOOLEAN";
          }
        | NOT expression
          {
            if(strcmp(dataType($2),"BOOLEAN")!=0)
              yyerror("Incompatible datatype");
            else
              $$="BOOLEAN";
          }
        ;

primary_expression: IDENTIFIER
                    {   
                        if(re==1)
                            assign_val_done($1);
                        char* dtm=dataType($1);
                        char* er="SEND ERROR";
                        if(strcmp(dtm,er)==0 && re==0)
                        {
                            yyerror("undeclared variable");
                        }
                        else if(re==0)
                        {   
                            if(is_Assigned($1)==1)
                              $$=dtm;
                            else
                              yyerror("Variable not assigned a value");
                        }

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
                        else if(re==0)
                        {
                            if(is_This_Array($1)==0)
                            {
                                yyerror("The variable is not an array and the operation is of an array");
                            }
                            else
                            {   
                                if(strcmp($3,"INT")==0)
                                $$=dtm;        
                                else
                                yyerror("Expected Integer in array index");                      
                            }
                        }   
           
                    }
                  | INTEGER
                    {   
                        $$=dataType_constant("INTEGER");
                    }
                  | REALX
                    {
                        $$=dataType_constant("REALX");
                    }
                  | CHARACTER
                    {
                        $$=dataType_constant("CHARACTER");
                    }
                  | TRU
                    {
                        $$=dataType_constant("TRU");
                    }
                  | FAL
                    {
                        $$=dataType_constant("FAL");
                    }
                 | LPAREN expression RPAREN
                    {
                        $$=$2;
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
    printf("Valid Input\n");
    //print();
    return 0;
}

int charToInt(const char *str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // Handle negative sign
    if (str[0] == '-') {
        sign = -1;
        i = 1;
    }

    // Iterate through each character in the string
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            // Convert character to integer and update result
            result = result * 10 + (str[i] - '0');
        } else {
            // If a non-digit character is encountered, return 0
            return 0;
        }
        i++;
    }

    // Apply sign to the result
    result *= sign;

    return result;
}