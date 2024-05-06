/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PROGRAM = 258,                 /* PROGRAM  */
    INT = 259,                     /* INT  */
    REAL = 260,                    /* REAL  */
    BOOLEAN = 261,                 /* BOOLEAN  */
    CHAR = 262,                    /* CHAR  */
    VAR = 263,                     /* VAR  */
    FOR = 264,                     /* FOR  */
    DO = 265,                      /* DO  */
    WHILE = 266,                   /* WHILE  */
    ARRAY = 267,                   /* ARRAY  */
    AND = 268,                     /* AND  */
    OR = 269,                      /* OR  */
    NOT = 270,                     /* NOT  */
    END = 271,                     /* END  */
    READ = 272,                    /* READ  */
    WRITE = 273,                   /* WRITE  */
    IDENTIFIER = 274,              /* IDENTIFIER  */
    INTEGER = 275,                 /* INTEGER  */
    CHARACTER = 276,               /* CHARACTER  */
    STRING = 277,                  /* STRING  */
    PLUS = 278,                    /* PLUS  */
    MINUS = 279,                   /* MINUS  */
    MULT = 280,                    /* MULT  */
    DIV = 281,                     /* DIV  */
    MOD = 282,                     /* MOD  */
    ASSIGN = 283,                  /* ASSIGN  */
    NOTEQUAL = 284,                /* NOTEQUAL  */
    LESS = 285,                    /* LESS  */
    GREATER = 286,                 /* GREATER  */
    LESSEQUAL = 287,               /* LESSEQUAL  */
    GREATEREQUAL = 288,            /* GREATEREQUAL  */
    SEMICOLON = 289,               /* SEMICOLON  */
    COLON = 290,                   /* COLON  */
    COMMA = 291,                   /* COMMA  */
    LPAREN = 292,                  /* LPAREN  */
    RPAREN = 293,                  /* RPAREN  */
    LBRACKET = 294,                /* LBRACKET  */
    RBRACKET = 295,                /* RBRACKET  */
    DOT = 296,                     /* DOT  */
    IF = 297,                      /* IF  */
    THEN = 298,                    /* THEN  */
    ELSE = 299,                    /* ELSE  */
    TO = 300,                      /* TO  */
    BEG = 301,                     /* BEG  */
    RANGE = 302,                   /* RANGE  */
    OF = 303,                      /* OF  */
    TRU = 304,                     /* TRU  */
    FAL = 305,                     /* FAL  */
    EQUALS = 306                   /* EQUALS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define PROGRAM 258
#define INT 259
#define REAL 260
#define BOOLEAN 261
#define CHAR 262
#define VAR 263
#define FOR 264
#define DO 265
#define WHILE 266
#define ARRAY 267
#define AND 268
#define OR 269
#define NOT 270
#define END 271
#define READ 272
#define WRITE 273
#define IDENTIFIER 274
#define INTEGER 275
#define CHARACTER 276
#define STRING 277
#define PLUS 278
#define MINUS 279
#define MULT 280
#define DIV 281
#define MOD 282
#define ASSIGN 283
#define NOTEQUAL 284
#define LESS 285
#define GREATER 286
#define LESSEQUAL 287
#define GREATEREQUAL 288
#define SEMICOLON 289
#define COLON 290
#define COMMA 291
#define LPAREN 292
#define RPAREN 293
#define LBRACKET 294
#define RBRACKET 295
#define DOT 296
#define IF 297
#define THEN 298
#define ELSE 299
#define TO 300
#define BEG 301
#define RANGE 302
#define OF 303
#define TRU 304
#define FAL 305
#define EQUALS 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "S2A24444_YACC.y"

    char *str;

#line 173 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
