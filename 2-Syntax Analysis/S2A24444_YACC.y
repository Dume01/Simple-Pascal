%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int linenum;
extern FILE *yyin;
int yylex();
void yyerror(const char *s);
%}

%union {
    char *str;
}

%token PROGRAM INT REAL BOOLEAN CHAR VAR FOR DO WHILE ARRAY AND OR NOT END READ WRITE
%token <str> IDENTIFIER INTEGER CHARACTER STRING
%token PLUS MINUS MULT DIV MOD ASSIGN NOTEQUAL LESS GREATER LESSEQUAL GREATEREQUAL
%token SEMICOLON COLON COMMA LPAREN RPAREN LBRACKET RBRACKET
%token DOT IF THEN ELSE TO BEG RANGE OF TRU FAL EQUALS

%start program

%%

program: PROGRAM IDENTIFIER SEMICOLON variable_declarations block DOT;

variable_declarations: /* empty */
                     | VAR variable_list SEMICOLON;

variable_list: variable_declaration
             | variable_list SEMICOLON variable_declaration;

variable_declaration: IDENTIFIER_list COLON type;

IDENTIFIER_list: IDENTIFIER
               | IDENTIFIER_list COMMA IDENTIFIER;

type: INT
    | REAL
    | BOOLEAN
    | CHAR
    | ARRAY LBRACKET INTEGER RANGE INTEGER RBRACKET OF type;

block: BEG statement_list END;

statement_list: /* empty */
              | statement SEMICOLON statement_list
              | block SEMICOLON;

statement: assignment_statement
         | read_statement
         | write_statement
         | conditional_statement
         | loop_statement;

assignment_statement: IDENTIFIER ASSIGN expression;

read_statement: READ LPAREN primary_expression RPAREN;

write_statement: WRITE LPAREN write_argument_list RPAREN;

write_argument_list: write_argument
                   | write_argument_list COMMA write_argument;

write_argument: STRING
              | primary_expression;

conditional_statement: IF expression THEN block
                     | IF expression THEN block ELSE block
                     | IF expression THEN conditional_statement ELSE conditional_statement;

loop_statement: FOR IDENTIFIER ASSIGN expression TO expression DO block
              | WHILE expression DO block;

expression: primary_expression
          | expression PLUS expression
          | expression MINUS expression
          | expression MULT expression
          | expression DIV expression
          | expression MOD expression
          | expression EQUALS expression
          | expression NOTEQUAL expression
          | expression LESS expression
          | expression LESSEQUAL expression
          | expression GREATER expression
          | expression GREATEREQUAL expression
          | expression AND expression
          | expression OR expression
          | NOT expression;

primary_expression: IDENTIFIER
                  | IDENTIFIER LBRACKET expression RBRACKET
                  | INTEGER
                  | REAL
                  | CHARACTER
                  | TRU
                  | FAL
                  | LPAREN expression RPAREN;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error\n");
    exit(0);
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
    printf("Valid input\n");
    return 0;
}