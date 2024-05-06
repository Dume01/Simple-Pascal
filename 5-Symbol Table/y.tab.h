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
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INT = 259,                     /* INT  */
    REAL = 260,                    /* REAL  */
    BOOLEAN = 261,                 /* BOOLEAN  */
    CHAR = 262,                    /* CHAR  */
    INTEGER = 263,                 /* INTEGER  */
    REALX = 264,                   /* REALX  */
    STRING = 265,                  /* STRING  */
    CHARACTER = 266,               /* CHARACTER  */
    TRU = 267,                     /* TRU  */
    FAL = 268,                     /* FAL  */
    PROGRAM = 269,                 /* PROGRAM  */
    VAR = 270,                     /* VAR  */
    FOR = 271,                     /* FOR  */
    DO = 272,                      /* DO  */
    WHILE = 273,                   /* WHILE  */
    ARRAY = 274,                   /* ARRAY  */
    AND = 275,                     /* AND  */
    OR = 276,                      /* OR  */
    NOT = 277,                     /* NOT  */
    END = 278,                     /* END  */
    READ = 279,                    /* READ  */
    WRITE = 280,                   /* WRITE  */
    PLUS = 281,                    /* PLUS  */
    MINUS = 282,                   /* MINUS  */
    MULT = 283,                    /* MULT  */
    DIV = 284,                     /* DIV  */
    MOD = 285,                     /* MOD  */
    ASSIGN = 286,                  /* ASSIGN  */
    NOTEQUAL = 287,                /* NOTEQUAL  */
    LESS = 288,                    /* LESS  */
    GREATER = 289,                 /* GREATER  */
    LESSEQUAL = 290,               /* LESSEQUAL  */
    GREATEREQUAL = 291,            /* GREATEREQUAL  */
    SEMICOLON = 292,               /* SEMICOLON  */
    COLON = 293,                   /* COLON  */
    COMMA = 294,                   /* COMMA  */
    LPAREN = 295,                  /* LPAREN  */
    RPAREN = 296,                  /* RPAREN  */
    LBRACKET = 297,                /* LBRACKET  */
    RBRACKET = 298,                /* RBRACKET  */
    TO = 299,                      /* TO  */
    DOT = 300,                     /* DOT  */
    IF = 301,                      /* IF  */
    THEN = 302,                    /* THEN  */
    ELSE = 303,                    /* ELSE  */
    BEG = 304,                     /* BEG  */
    RANGE = 305,                   /* RANGE  */
    OF = 306,                      /* OF  */
    EQUALS = 307                   /* EQUALS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define INT 259
#define REAL 260
#define BOOLEAN 261
#define CHAR 262
#define INTEGER 263
#define REALX 264
#define STRING 265
#define CHARACTER 266
#define TRU 267
#define FAL 268
#define PROGRAM 269
#define VAR 270
#define FOR 271
#define DO 272
#define WHILE 273
#define ARRAY 274
#define AND 275
#define OR 276
#define NOT 277
#define END 278
#define READ 279
#define WRITE 280
#define PLUS 281
#define MINUS 282
#define MULT 283
#define DIV 284
#define MOD 285
#define ASSIGN 286
#define NOTEQUAL 287
#define LESS 288
#define GREATER 289
#define LESSEQUAL 290
#define GREATEREQUAL 291
#define SEMICOLON 292
#define COLON 293
#define COMMA 294
#define LPAREN 295
#define RPAREN 296
#define LBRACKET 297
#define RBRACKET 298
#define TO 299
#define DOT 300
#define IF 301
#define THEN 302
#define ELSE 303
#define BEG 304
#define RANGE 305
#define OF 306
#define EQUALS 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "S2A24444.y"

    char *str;
    struct temp {
        char* tp;
        char* cd;
        char* typ;
    } t;

#line 180 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
