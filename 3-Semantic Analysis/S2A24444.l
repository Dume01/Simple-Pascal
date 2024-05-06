%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "y.tab.h"

int linenum = 1;
%}

digitx      [0-9]
letter     [a-zA-Z]
alphanumeric    [A-Za-z0-9]
identifier {letter}({letter}|{digitx}|_)*
integer    {digitx}+
real       {digitx}*\.{digitx}+
character  \'(\\\.|[^\\\'])*\'
string     \"(\\\.|[^\\\"])*\"
whitespace [ ]+
tab        [\t]
newline    \n

%%

(p|P)(r|R)(o|O)(g|G)(r|R)(a|A)(m|M)    {  return PROGRAM; }
(i|I)(n|N)(t|T)(e|E)(g|G)(e|E)(r|R)    {  yylval.str = "INT"; return INT; }
(r|R)(e|E)(a|A)(l|L)                   {  yylval.str = "REAL"; return REAL; }
(b|B)(o|O)(o|O)(l|L)(e|E)(a|A)(n|N)    {  yylval.str = "BOOLEAN"; return BOOLEAN; }
(c|C)(h|H)(a|A)(r|R)                   {  yylval.str = "CHAR"; return CHAR; }
(v|V)(a|A)(r|R)                        {   return VAR; }
(f|F)(o|O)(r|R)                        {  return FOR; }
(d|D)(o|O)                             {  return DO; }
(w|W)(h|H)(i|I)(l|L)(e|E)              {  return WHILE; }
(a|A)(r|R)(r|R)(a|A)(y|Y)              {  return ARRAY; }
(o|O)(f|F)                             {  return OF; }
(b|B)(e|E)(g|G)(i|I)(n|N)              {  return BEG; }
(e|E)(n|N)(d|D)                        {  return END; }
(r|R)(e|E)(a|A)(d|D)                   {  return READ; }
(w|W)(r|R)(i|I)(t|T)(e|E)              {  return WRITE; }
(i|I)(f|F)                             {  return IF; }
(t|T)(h|H)(e|E)(n|N)                   {  return THEN; }
(e|E)(l|L)(s|S)(e|E)                   {  return ELSE; }
(d|D)(o|O)(w|W)(n|N)(t|T)(o|O)         {  return TO; }
(t|T)(o|O)                             {  return TO; }

(a|A)(n|N)(d|D)                        {  return AND; }
(o|O)(r|R)                             {  return OR; }
(n|N)(o|O)(t|T)                        {  return NOT; }

(t|T)(r|R)(u|U)(e|E)                   { yylval.str=strdup(yytext); return TRU;}
(f|F)(a|A)(l|L)(s|S)(e|E)              { yylval.str=strdup(yytext); return FAL;}


{identifier}                    {  yylval.str=strdup(yytext); return IDENTIFIER; }
{integer}                       {  yylval.str=strdup(yytext); return INTEGER; }
{real}                          {  yylval.str=strdup(yytext); return REALX; }
[']{alphanumeric}[']            {  yylval.str=strdup(yytext); return CHARACTER; }
{string}                        {  yylval.str=strdup(yytext); return STRING; }


"+"         {  return PLUS; }
"-"         {  return MINUS; }
"*"         {  return MULT; }
"/"         {  return DIV; }
"%"         {  return MOD; }
"="         {  return EQUALS; }
"<>"        {  return NOTEQUAL; }
"<"         {  return LESS; }
">"         {  return GREATER; }
"<="        {  return LESSEQUAL; }
">="        {  return GREATEREQUAL; }
":="        {  return ASSIGN; }

".."        {  return RANGE; }
"."         {  return DOT; }
";"         {  return SEMICOLON; }
":"         {  return COLON; }
","         {  return COMMA; }
"("         {  return LPAREN; }
")"         {  return RPAREN; }
"["         {  return LBRACKET; }
"]"         {  return RBRACKET; }

{identifier}({letter}|{digitx})*(\[[0-9]+\])* {  return IDENTIFIER; }

{whitespace}* { /* Skip whitespace */ }
{tab}*         { /* Skip tab */ }
{newline}     { linenum++; }

"//".*         { /* Skip single-line comments */ }

.              {  }

%%

int yywrap() {
    return 1;
}

