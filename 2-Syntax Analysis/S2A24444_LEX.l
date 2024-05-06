%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"

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

(p|P)(r|R)(o|O)(g|G)(r|R)(a|A)(m|M)    { addToSymbolTable(yytext, "KEYWORD"); return PROGRAM; }
(i|I)(n|N)(t|T)(e|E)(g|G)(e|E)(r|R)    { addToSymbolTable(yytext, "KEYWORD"); return INT; }
(r|R)(e|E)(a|A)(l|L)                   { addToSymbolTable(yytext, "KEYWORD"); return REAL; }
(b|B)(o|O)(o|O)(l|L)(e|E)(a|A)(n|N)    { addToSymbolTable(yytext, "KEYWORD"); return BOOLEAN; }
(c|C)(h|H)(a|A)(r|R)                   { addToSymbolTable(yytext, "KEYWORD"); return CHAR; }
(v|V)(a|A)(r|R)                        { addToSymbolTable(yytext, "KEYWORD"); return VAR; }
(f|F)(o|O)(r|R)                        { addToSymbolTable(yytext, "KEYWORD"); return FOR; }
(d|D)(o|O)                             { addToSymbolTable(yytext, "KEYWORD"); return DO; }
(w|W)(h|H)(i|I)(l|L)(e|E)              { addToSymbolTable(yytext, "KEYWORD"); return WHILE; }
(a|A)(r|R)(r|R)(a|A)(y|Y)              { addToSymbolTable(yytext, "KEYWORD"); return ARRAY; }
(o|O)(f|F)                             { addToSymbolTable(yytext, "KEYWORD"); return OF; }
(b|B)(e|E)(g|G)(i|I)(n|N)              { addToSymbolTable(yytext, "KEYWORD"); return BEG; }
(e|E)(n|N)(d|D)                        { addToSymbolTable(yytext, "KEYWORD"); return END; }
(r|R)(e|E)(a|A)(d|D)                   { addToSymbolTable(yytext, "KEYWORD"); return READ; }
(w|W)(r|R)(i|I)(t|T)(e|E)              { addToSymbolTable(yytext, "KEYWORD"); return WRITE; }
(i|I)(f|F)                             { addToSymbolTable(yytext, "KEYWORD"); return IF; }
(t|T)(h|H)(e|E)(n|N)                   { addToSymbolTable(yytext, "KEYWORD"); return THEN; }
(e|E)(l|L)(s|S)(e|E)                   { addToSymbolTable(yytext, "KEYWORD"); return ELSE; }
(d|D)(o|O)(w|W)(n|N)(t|T)(o|O)    { addToSymbolTable(yytext, "KEYWORD"); return TO; }
(t|T)(o|O)    { addToSymbolTable(yytext, "KEYWORD"); return TO; }

(a|A)(n|N)(d|D)                        { addToSymbolTable(yytext, "OPERATOR"); return AND; }
(o|O)(r|R)                             { addToSymbolTable(yytext, "OPERATOR"); return OR; }
(n|N)(o|O)(t|T)                        { addToSymbolTable(yytext, "OPERATOR"); return NOT; }

(t|T)(r|R)(u|U)(e|E)                   {addToSymbolTable(yytext, "BOOLEAN"); return TRU;}
(f|F)(a|A)(l|L)(s|S)(e|E)              {addToSymbolTable(yytext, "BOOLEAN"); return FAL;}


{identifier} { addToSymbolTable(yytext, "IDENTIFIER"); return IDENTIFIER; }
{integer}   { addToSymbolTable(yytext, "INTEGER"); return INTEGER; }
{real}      { addToSymbolTable(yytext, "REAL"); return REAL; }
{character} { addToSymbolTable(yytext, "CHARACTER"); return CHARACTER; }
{string}    {  return STRING; }

"+"         { addToSymbolTable(yytext, "OPERATOR"); return PLUS; }
"-"         { addToSymbolTable(yytext, "OPERATOR"); return MINUS; }
"*"         { addToSymbolTable(yytext, "OPERATOR"); return MULT; }
"/"         { addToSymbolTable(yytext, "OPERATOR"); return DIV; }
"%"         { addToSymbolTable(yytext, "OPERATOR"); return MOD; }
"="         { addToSymbolTable(yytext, "OPERATOR"); return EQUALS; }
"<>"        { addToSymbolTable(yytext, "OPERATOR"); return NOTEQUAL; }
"<"         { addToSymbolTable(yytext, "OPERATOR"); return LESS; }
">"         { addToSymbolTable(yytext, "OPERATOR"); return GREATER; }
"<="        { addToSymbolTable(yytext, "OPERATOR"); return LESSEQUAL; }
">="        { addToSymbolTable(yytext, "OPERATOR"); return GREATEREQUAL; }
":="        { addToSymbolTable(yytext, "ASSIGNMENT OPERATOR"); return ASSIGN; }

".."        { addToSymbolTable(yytext, "PUNCTUATOR"); return RANGE; }
"."         { addToSymbolTable(yytext, "PUNCTUATOR"); return DOT; }
";"         { addToSymbolTable(yytext, "PUNCTUATOR"); return SEMICOLON; }
":"         { addToSymbolTable(yytext, "PUNCTUATOR"); return COLON; }
","         { addToSymbolTable(yytext, "PUNCTUATOR"); return COMMA; }
"("         { addToSymbolTable(yytext, "PUNCTUATOR"); return LPAREN; }
")"         { addToSymbolTable(yytext, "PUNCTUATOR"); return RPAREN; }
"["         { addToSymbolTable(yytext, "PUNCTUATOR"); return LBRACKET; }
"]"         { addToSymbolTable(yytext, "PUNCTUATOR"); return RBRACKET; }

{identifier}({letter}|{digitx})*(\[[0-9]+\])* { addToSymbolTable(yytext, "IDENTIFIER"); return IDENTIFIER; }

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
