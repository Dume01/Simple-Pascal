%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int linenum = 1;

struct SymbolTableEntry {
    char *lexeme;
    char *tokenType;
    struct SymbolTableEntry *next;
};

struct SymbolTableEntry *symbolTable = NULL;

void addToSymbolTable(char *lexeme, char *tokenType) {
    struct SymbolTableEntry *newEntry = (struct SymbolTableEntry *)malloc(sizeof(struct SymbolTableEntry));
    newEntry->lexeme = strdup(lexeme);
    newEntry->tokenType = strdup(tokenType);
    newEntry->next = symbolTable;
    symbolTable = newEntry;
}
%}

digitx      [0-9]
letter     [a-zA-Z]
identifier {letter}({letter}|{digitx}|_)*
integer    {digitx}+
real       {digitx}*\.{digitx}+
character  \'(\\\.|[^\\\'])*\'
string     \"(\\\.|[^\\\"])*\"
whitespace [ ]+
tab        [\t]
newline    \n

%%


(p|P)(r|R)(o|O)(g|G)(r|R)(a|A)(m|M)    { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t KEYWORD\n", linenum, yytext); }
(i|I)(n|N)(t|T)(e|E)(g|G)(e|E)(r|R)    { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t KEYWORD\n", linenum, yytext); }
(r|R)(e|E)(a|A)(l|L)                   { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t KEYWORD\n", linenum, yytext); }
(b|B)(o|O)(o|O)(l|L)(e|E)(a|A)(n|N)    { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t KEYWORD\n", linenum, yytext); }
(c|C)(h|H)(a|A)(r|R)                   { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t KEYWORD\n", linenum, yytext); }
(v|V)(a|A)(r|R)                        { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t KEYWORD\n", linenum, yytext); }
(f|F)(o|O)(r|R)                        { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t KEYWORD\n", linenum, yytext); }
(d|D)(o|O)                             { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t KEYWORD\n", linenum, yytext); }
(w|W)(h|H)(i|I)(l|L)(e|E)              { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t KEYWORD\n", linenum, yytext); }
(a|A)(r|R)(r|R)(a|A)(y|Y)              { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t KEYWORD\n", linenum, yytext); }
(o|O)(f|F)                             { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t KEYWORD\n", linenum, yytext); }
(b|B)(e|E)(g|G)(i|I)(n|N)              { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t KEYWORD\n", linenum, yytext); }
(e|E)(n|N)(d|D)                        { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t KEYWORD\n", linenum, yytext); }
(r|R)(e|E)(a|A)(d|D)                   { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t KEYWORD\n", linenum, yytext); }
(w|W)(r|R)(i|I)(t|T)(e|E)              { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t KEYWORD\n", linenum, yytext); }
(i|I)(f|F)                             { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t KEYWORD\n", linenum, yytext); }
(t|T)(h|H)(e|E)(n|N)                   { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t KEYWORD\n", linenum, yytext); }
(e|E)(l|L)(s|S)(e|E)                   { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t KEYWORD\n", linenum, yytext); }
(d|D)(o|O)(w|W)(n|N)(t|T)(o|O)    { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t OPERATOR\n", linenum, yytext); }
(t|T)(o|O)    { addToSymbolTable(yytext, "KEYWORD"); printf("%d \t %s \t OPERATOR\n", linenum, yytext); }

(a|A)(n|N)(d|D)                        { addToSymbolTable(yytext, "BOOLEAN OPERATOR"); printf("%d \t %s \t BOOLEAN OPERATOR\n", linenum, yytext); }
(o|O)(r|R)                             { addToSymbolTable(yytext, "BOOLEAN OPERATOR"); printf("%d \t %s \t BOOLEAN OPERATOR\n", linenum, yytext); }
(n|N)(o|O)(t|T)                        { addToSymbolTable(yytext, "BOOLEAN OPERATOR"); printf("%d \t %s \t BOOLEAN OPERATOR\n", linenum, yytext); }

(t|T)(r|R)(u|U)(e|E)                   {addToSymbolTable(yytext, "BOOLEAN"); printf("%d \t %s \t CONSTANT\n", linenum, yytext);}
(f|F)(a|A)(l|L)(s|S)(e|E)              {addToSymbolTable(yytext, "BOOLEAN"); printf("%d \t %s \t CONSTANT\n", linenum, yytext);}

{identifier} { addToSymbolTable(yytext, "IDENTIFIER"); printf("%d \t %s \t IDENTIFIER\n", linenum, yytext); }
{integer}   { addToSymbolTable(yytext, "INTEGER"); printf("%d \t %s \t CONSTANT\n", linenum, yytext); }
{real}      { addToSymbolTable(yytext, "REAL"); printf("%d \t %s \t CONSTANT\n", linenum, yytext); }
{character} { addToSymbolTable(yytext, "CHARACTER"); printf("%d \t %s \t CONSTANT\n", linenum, yytext); }
{string}    {  }

"+"         { addToSymbolTable(yytext, "ARITHMATIC OPERATOR"); printf("%d \t %s \t ARITHMATIC OPERATOR\n", linenum, yytext); }
"-"         { addToSymbolTable(yytext, "ARITHMATIC OPERATOR"); printf("%d \t %s \t ARITHMATIC OPERATOR\n", linenum, yytext); }
"*"         { addToSymbolTable(yytext, "ARITHMATIC OPERATOR"); printf("%d \t %s \t ARITHMATIC OPERATOR\n", linenum, yytext); }
"/"         { addToSymbolTable(yytext, "ARITHMATIC OPERATOR"); printf("%d \t %s \t ARITHMATIC OPERATOR\n", linenum, yytext); }
"%"         { addToSymbolTable(yytext, "ARITHMATIC OPERATOR"); printf("%d \t %s \t ARITHMATIC OPERATOR\n", linenum, yytext); }
"="         { addToSymbolTable(yytext, "RELATIONAL OPERATOR"); printf("%d \t %s \t RELATIONAL OPERATOR\n", linenum, yytext); }
"<>"        { addToSymbolTable(yytext, "RELATIONAL OPERATOR"); printf("%d \t %s \t RELATIONAL OPERATOR\n", linenum, yytext); }
"<"         { addToSymbolTable(yytext, "RELATIONAL OPERATOR"); printf("%d \t %s \t RELATIONAL OPERATOR\n", linenum, yytext); }
">"         { addToSymbolTable(yytext, "RELATIONAL OPERATOR"); printf("%d \t %s \t RELATIONAL OPERATOR\n", linenum, yytext); }
"<="        { addToSymbolTable(yytext, "RELATIONAL OPERATOR"); printf("%d \t %s \t RELATIONALOPERATOR\n", linenum, yytext); }
">="        { addToSymbolTable(yytext, "RELATIONAL OPERATOR"); printf("%d \t %s \t RELATIONAL OPERATOR\n", linenum, yytext); }
":="        { addToSymbolTable(yytext, "ASSIGNMENT OPERATOR"); printf("%d \t %s \t ASSIGNMENT OPERATOR\n", linenum, yytext); }

".."        { addToSymbolTable(yytext, "PUNCTUATOR"); printf("%d \t %s \t PUNCTUATOR\n", linenum, yytext); }
"."         { addToSymbolTable(yytext, "PUNCTUATOR"); printf("%d \t %s \t PUNCTUATOR\n", linenum, yytext); }
";"         { addToSymbolTable(yytext, "PUNCTUATOR"); printf("%d \t %s \t PUNCTUATOR\n", linenum, yytext); }
":"         { addToSymbolTable(yytext, "PUNCTUATOR"); printf("%d \t %s \t PUNCTUATOR\n", linenum, yytext); }
","         { addToSymbolTable(yytext, "PUNCTUATOR"); printf("%d \t %s \t PUNCTUATOR\n", linenum, yytext); }
"("         { addToSymbolTable(yytext, "PUNCTUATOR"); printf("%d \t %s \t PUNCTUATOR\n", linenum, yytext); }
")"         { addToSymbolTable(yytext, "PUNCTUATOR"); printf("%d \t %s \t PUNCTUATOR\n", linenum, yytext); }
"["         { addToSymbolTable(yytext, "PUNCTUATOR"); printf("%d \t %s \t PUNCTUATOR\n", linenum, yytext); }
"]"         { addToSymbolTable(yytext, "PUNCTUATOR"); printf("%d \t %s \t PUNCTUATOR\n", linenum, yytext); }

{identifier}({letter}|{digitx})*(\[[0-9]+\])* { addToSymbolTable(yytext, "IDENTIFIER"); printf("%d \t %s \t IDENTIFIER\n", linenum, yytext); }

{whitespace}* { /* Skip whitespace */ }
{tab}*         { /* Skip tab */ }
"\n"           { linenum++; }

"//".*         { /* Skip single-line comments */ }

.              {  }

%%

int yywrap() {
    return 1;
}

void printSymbolTable() {
    struct SymbolTableEntry *temp = symbolTable;
    printf("\nSymbol Table:\n");
    printf("%-20s%-20s\n", "Lexeme", "Token Type");
    while (temp != NULL) {
        printf("%-20s%-20s\n", temp->lexeme, temp->tokenType);
        temp = temp->next;
    }
}
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    // Set input file as the stream for lex
    yyin = input_file;

    // Call the lexer
    yylex();

    // Print the symbol table
    //printSymbolTable();

    fclose(input_file);
    return 0;
}
