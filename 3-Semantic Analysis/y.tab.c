/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "S2A24444.y"

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

#line 88 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    DOT = 299,                     /* DOT  */
    IF = 300,                      /* IF  */
    THEN = 301,                    /* THEN  */
    ELSE = 302,                    /* ELSE  */
    TO = 303,                      /* TO  */
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
#define DOT 299
#define IF 300
#define THEN 301
#define ELSE 302
#define TO 303
#define BEG 304
#define RANGE 305
#define OF 306
#define EQUALS 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "S2A24444.y"

    char *str;

#line 249 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_REAL = 5,                       /* REAL  */
  YYSYMBOL_BOOLEAN = 6,                    /* BOOLEAN  */
  YYSYMBOL_CHAR = 7,                       /* CHAR  */
  YYSYMBOL_INTEGER = 8,                    /* INTEGER  */
  YYSYMBOL_REALX = 9,                      /* REALX  */
  YYSYMBOL_STRING = 10,                    /* STRING  */
  YYSYMBOL_CHARACTER = 11,                 /* CHARACTER  */
  YYSYMBOL_TRU = 12,                       /* TRU  */
  YYSYMBOL_FAL = 13,                       /* FAL  */
  YYSYMBOL_PROGRAM = 14,                   /* PROGRAM  */
  YYSYMBOL_VAR = 15,                       /* VAR  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_DO = 17,                        /* DO  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_ARRAY = 19,                     /* ARRAY  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_END = 23,                       /* END  */
  YYSYMBOL_READ = 24,                      /* READ  */
  YYSYMBOL_WRITE = 25,                     /* WRITE  */
  YYSYMBOL_PLUS = 26,                      /* PLUS  */
  YYSYMBOL_MINUS = 27,                     /* MINUS  */
  YYSYMBOL_MULT = 28,                      /* MULT  */
  YYSYMBOL_DIV = 29,                       /* DIV  */
  YYSYMBOL_MOD = 30,                       /* MOD  */
  YYSYMBOL_ASSIGN = 31,                    /* ASSIGN  */
  YYSYMBOL_NOTEQUAL = 32,                  /* NOTEQUAL  */
  YYSYMBOL_LESS = 33,                      /* LESS  */
  YYSYMBOL_GREATER = 34,                   /* GREATER  */
  YYSYMBOL_LESSEQUAL = 35,                 /* LESSEQUAL  */
  YYSYMBOL_GREATEREQUAL = 36,              /* GREATEREQUAL  */
  YYSYMBOL_SEMICOLON = 37,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 38,                     /* COLON  */
  YYSYMBOL_COMMA = 39,                     /* COMMA  */
  YYSYMBOL_LPAREN = 40,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 41,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 42,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 43,                  /* RBRACKET  */
  YYSYMBOL_DOT = 44,                       /* DOT  */
  YYSYMBOL_IF = 45,                        /* IF  */
  YYSYMBOL_THEN = 46,                      /* THEN  */
  YYSYMBOL_ELSE = 47,                      /* ELSE  */
  YYSYMBOL_TO = 48,                        /* TO  */
  YYSYMBOL_BEG = 49,                       /* BEG  */
  YYSYMBOL_RANGE = 50,                     /* RANGE  */
  YYSYMBOL_OF = 51,                        /* OF  */
  YYSYMBOL_EQUALS = 52,                    /* EQUALS  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_program = 54,                   /* program  */
  YYSYMBOL_variable_declarations = 55,     /* variable_declarations  */
  YYSYMBOL_variable_list = 56,             /* variable_list  */
  YYSYMBOL_variable_declaration = 57,      /* variable_declaration  */
  YYSYMBOL_IDENTIFIER_list = 58,           /* IDENTIFIER_list  */
  YYSYMBOL_type = 59,                      /* type  */
  YYSYMBOL_block = 60,                     /* block  */
  YYSYMBOL_statement_list = 61,            /* statement_list  */
  YYSYMBOL_statement = 62,                 /* statement  */
  YYSYMBOL_assignment_statement = 63,      /* assignment_statement  */
  YYSYMBOL_read_statement = 64,            /* read_statement  */
  YYSYMBOL_65_1 = 65,                      /* $@1  */
  YYSYMBOL_write_statement = 66,           /* write_statement  */
  YYSYMBOL_write_argument_list = 67,       /* write_argument_list  */
  YYSYMBOL_write_argument = 68,            /* write_argument  */
  YYSYMBOL_conditional_statement = 69,     /* conditional_statement  */
  YYSYMBOL_maybe_else = 70,                /* maybe_else  */
  YYSYMBOL_loop_statement = 71,            /* loop_statement  */
  YYSYMBOL_expression = 72,                /* expression  */
  YYSYMBOL_primary_expression = 73         /* primary_expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   249

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    59,    59,    61,    62,    65,    66,    68,    81,    92,
     105,   106,   107,   108,   109,   117,   119,   120,   121,   123,
     124,   125,   126,   127,   129,   152,   152,   159,   161,   162,
     164,   165,   167,   174,   175,   178,   179,   181,   185,   192,
     199,   206,   213,   220,   227,   234,   241,   248,   255,   262,
     269,   276,   285,   304,   332,   336,   340,   344,   348,   352
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER", "INT",
  "REAL", "BOOLEAN", "CHAR", "INTEGER", "REALX", "STRING", "CHARACTER",
  "TRU", "FAL", "PROGRAM", "VAR", "FOR", "DO", "WHILE", "ARRAY", "AND",
  "OR", "NOT", "END", "READ", "WRITE", "PLUS", "MINUS", "MULT", "DIV",
  "MOD", "ASSIGN", "NOTEQUAL", "LESS", "GREATER", "LESSEQUAL",
  "GREATEREQUAL", "SEMICOLON", "COLON", "COMMA", "LPAREN", "RPAREN",
  "LBRACKET", "RBRACKET", "DOT", "IF", "THEN", "ELSE", "TO", "BEG",
  "RANGE", "OF", "EQUALS", "$accept", "program", "variable_declarations",
  "variable_list", "variable_declaration", "IDENTIFIER_list", "type",
  "block", "statement_list", "statement", "assignment_statement",
  "read_statement", "$@1", "write_statement", "write_argument_list",
  "write_argument", "conditional_statement", "maybe_else",
  "loop_statement", "expression", "primary_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-47)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,     7,    14,   -16,   -47,    15,    26,   -18,   -47,    -3,
     -47,   -33,    17,    -8,    26,    19,    34,    12,    56,     0,
     -47,    20,     0,    24,    41,    28,   -47,   -47,   -47,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,   -47,    25,   -47,   -47,
       0,    27,    39,   -47,   -47,   -47,   -47,   -47,     0,     0,
      86,   -47,    48,    60,   128,   -47,   -47,    17,    87,   176,
       0,    71,   -47,   149,   -18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    71,   -47,
     -37,   -47,   -47,   -18,   -47,    44,   107,    53,   -47,   -47,
      76,   -47,    57,    57,   197,   197,   197,    -4,    -4,    -4,
      -4,    -4,    -4,    58,    60,   -47,    51,    94,   -18,   -47,
     -47,   -47,   -18,   -47,    61,   -47,   -47,    59,    19,   -47
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     3,     0,     0,     8,     0,
       5,     0,    16,     0,     4,     0,     0,     0,     0,     0,
      25,     0,     0,     0,     0,     0,    19,    20,    21,    22,
      23,     2,     6,    10,    11,    12,    13,     0,     7,     9,
       0,     0,    52,    54,    55,    56,    57,    58,     0,     0,
       0,    37,     0,     0,     0,    18,    15,    16,     0,    24,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
       0,    28,    31,     0,    17,     0,     0,     0,    59,    36,
      49,    50,    38,    39,    40,    41,    42,    44,    45,    47,
      46,    48,    43,     0,     0,    27,    33,     0,     0,    53,
      26,    29,     0,    32,     0,    35,    34,     0,     0,    14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -47,   -47,   -47,   -47,   103,   -47,   -10,    -7,    66,   -47,
     108,   -47,   -47,   -47,   -47,    21,   -47,   -47,   -47,   -21,
     -46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     7,     9,    10,    11,    38,    23,    24,    25,
      26,    27,    52,    28,    80,    81,    29,   113,    30,    50,
      51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      13,    54,   104,    42,   105,    15,    16,    82,    43,    44,
       3,    45,    46,    47,     4,    87,    65,    66,     1,    59,
      17,     5,    48,    33,    34,    35,    36,    62,    63,     8,
       6,    12,   103,    18,    14,    19,    31,    39,    37,    86,
      49,    20,    21,    40,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    89,    82,    17,
      53,    55,    22,    42,    56,    57,    12,    58,    43,    44,
      79,    45,    46,    47,    42,    60,   106,    65,    66,    43,
      44,    61,    45,    46,    47,    69,    70,    71,    78,    72,
      73,    74,    75,    76,   107,    85,   109,    66,   112,   110,
      49,   115,   114,    64,   117,   116,    65,    66,   119,    77,
     118,    49,    67,    68,    69,    70,    71,    32,    72,    73,
      74,    75,    76,    84,   108,   111,    41,    65,    66,     0,
       0,     0,     0,    67,    68,    69,    70,    71,    77,    72,
      73,    74,    75,    76,     0,     0,     0,     0,    65,    66,
       0,     0,     0,     0,    67,    68,    69,    70,    71,    77,
      72,    73,    74,    75,    76,     0,     0,     0,     0,    65,
      66,     0,     0,     0,    83,    67,    68,    69,    70,    71,
      77,    72,    73,    74,    75,    76,     0,     0,     0,     0,
      88,     0,     0,     0,     0,     0,    65,    66,     0,     0,
       0,    77,    67,    68,    69,    70,    71,     0,    72,    73,
      74,    75,    76,     0,     0,     0,     0,    65,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    72,
      73,    74,    75,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77
};

static const yytype_int8 yycheck[] =
{
       7,    22,    39,     3,    41,    38,    39,    53,     8,     9,
       3,    11,    12,    13,     0,    61,    20,    21,    14,    40,
       3,    37,    22,     4,     5,     6,     7,    48,    49,     3,
      15,    49,    78,    16,    37,    18,    44,     3,    19,    60,
      40,    24,    25,    31,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    64,   104,     3,
      40,    37,    45,     3,    23,    37,    49,    42,     8,     9,
      10,    11,    12,    13,     3,    48,    83,    20,    21,     8,
       9,    42,    11,    12,    13,    28,    29,    30,    40,    32,
      33,    34,    35,    36,    50,     8,    43,    21,    47,    41,
      40,   108,     8,    17,    43,   112,    20,    21,   118,    52,
      51,    40,    26,    27,    28,    29,    30,    14,    32,    33,
      34,    35,    36,    57,    17,   104,    18,    20,    21,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    52,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    20,    21,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    52,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    20,
      21,    -1,    -1,    -1,    46,    26,    27,    28,    29,    30,
      52,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    20,    21,    -1,    -1,
      -1,    52,    26,    27,    28,    29,    30,    -1,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    54,     3,     0,    37,    15,    55,     3,    56,
      57,    58,    49,    60,    37,    38,    39,     3,    16,    18,
      24,    25,    45,    60,    61,    62,    63,    64,    66,    69,
      71,    44,    57,     4,     5,     6,     7,    19,    59,     3,
      31,    63,     3,     8,     9,    11,    12,    13,    22,    40,
      72,    73,    65,    40,    72,    37,    23,    37,    42,    72,
      48,    42,    72,    72,    17,    20,    21,    26,    27,    28,
      29,    30,    32,    33,    34,    35,    36,    52,    40,    10,
      67,    68,    73,    46,    61,     8,    72,    73,    41,    60,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    73,    39,    41,    60,    50,    17,    43,
      41,    68,    47,    70,     8,    60,    60,    43,    51,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    57,    58,    58,
      59,    59,    59,    59,    59,    60,    61,    61,    61,    62,
      62,    62,    62,    62,    63,    65,    64,    66,    67,    67,
      68,    68,    69,    70,    70,    71,    71,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    73,    73,    73,    73,    73,    73,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     0,     3,     1,     3,     3,     1,     3,
       1,     1,     1,     1,     8,     3,     0,     3,     2,     1,
       1,     1,     1,     1,     3,     0,     5,     4,     1,     3,
       1,     1,     5,     0,     2,     6,     4,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     4,     1,     1,     1,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 7: /* variable_declaration: IDENTIFIER_list COLON type  */
#line 69 "S2A24444.y"
                      {   
                          if(flag_array==0)
                          add_variable_data_type((yyvsp[0].str),0);
                          else
                          {
                            flag_array=0;
                            add_variable_data_type((yyvsp[0].str),upl);
                            upl=0;
                          }
                      }
#line 1412 "y.tab.c"
    break;

  case 8: /* IDENTIFIER_list: IDENTIFIER  */
#line 82 "S2A24444.y"
                 {  
                    if(isPresent((yyvsp[0].str))==0)
                    {   
                        add_variable_name((yyvsp[0].str));
                    }
                    else
                    {
                        yyerror("multiple declartion of variable");
                    }
                 }
#line 1427 "y.tab.c"
    break;

  case 9: /* IDENTIFIER_list: IDENTIFIER_list COMMA IDENTIFIER  */
#line 93 "S2A24444.y"
                  {
                    if(isPresent((yyvsp[0].str))==0)
                    {
                        add_variable_name((yyvsp[0].str));
                    }
                    else
                    {
                        yyerror("multiple declartion of variable");
                    }
                  }
#line 1442 "y.tab.c"
    break;

  case 10: /* type: INT  */
#line 105 "S2A24444.y"
          {(yyval.str) = "INT";}
#line 1448 "y.tab.c"
    break;

  case 11: /* type: REAL  */
#line 106 "S2A24444.y"
           {(yyval.str) = "REAL";}
#line 1454 "y.tab.c"
    break;

  case 12: /* type: BOOLEAN  */
#line 107 "S2A24444.y"
              {(yyval.str) = "BOOLEAN";}
#line 1460 "y.tab.c"
    break;

  case 13: /* type: CHAR  */
#line 108 "S2A24444.y"
           {(yyval.str) = "CHAR";}
#line 1466 "y.tab.c"
    break;

  case 14: /* type: ARRAY LBRACKET INTEGER RANGE INTEGER RBRACKET OF type  */
#line 110 "S2A24444.y"
      {
        flag_array=1; 
        upl=charToInt((yyvsp[-3].str));
        (yyval.str)=(yyvsp[0].str);
      }
#line 1476 "y.tab.c"
    break;

  case 24: /* assignment_statement: IDENTIFIER ASSIGN expression  */
#line 130 "S2A24444.y"
                      {
                        char* dtm=dataType((yyvsp[-2].str));
                        char* er="SEND ERROR";
                        if(strcmp(dtm,er)==0)
                        {
                            yyerror("undeclared variable");
                        }
                        else
                        {   

                            if(strcmp(dtm,dataType((yyvsp[0].str)))==0) 
                            {
                                assign_val_done((yyvsp[-2].str));
                            }
                            else
                            {
                                yyerror("Incompatible datatype");
                            }
                        }
                      }
#line 1501 "y.tab.c"
    break;

  case 25: /* $@1: %empty  */
#line 152 "S2A24444.y"
                     {re=1;}
#line 1507 "y.tab.c"
    break;

  case 26: /* read_statement: READ $@1 LPAREN primary_expression RPAREN  */
#line 153 "S2A24444.y"
                {   
                    assign_val_done((yyvsp[-1].str));
                    re=0;
                }
#line 1516 "y.tab.c"
    break;

  case 32: /* conditional_statement: IF expression THEN block maybe_else  */
#line 168 "S2A24444.y"
                       {
                          if(strcmp((yyvsp[-3].str),"BOOLEAN")!=0)
                            yyerror("conditional_statement statement require a boolean type");
                       }
#line 1525 "y.tab.c"
    break;

  case 37: /* expression: primary_expression  */
#line 182 "S2A24444.y"
            {
              (yyval.str)=(yyvsp[0].str);
            }
#line 1533 "y.tab.c"
    break;

  case 38: /* expression: expression PLUS expression  */
#line 186 "S2A24444.y"
          { 
            if(strcmp(dataType((yyvsp[-2].str)),dataType((yyvsp[0].str)))!=0) 
            yyerror("Incompatible datatypes");
            else
            (yyval.str)=(yyvsp[-2].str);
          }
#line 1544 "y.tab.c"
    break;

  case 39: /* expression: expression MINUS expression  */
#line 193 "S2A24444.y"
          {
            if(strcmp(dataType((yyvsp[-2].str)),dataType((yyvsp[0].str)))!=0)
            yyerror("Incompatible datatypes");
            else
            (yyval.str)=(yyvsp[-2].str);
          }
#line 1555 "y.tab.c"
    break;

  case 40: /* expression: expression MULT expression  */
#line 200 "S2A24444.y"
          {
            if(strcmp(dataType((yyvsp[-2].str)),dataType((yyvsp[0].str)))!=0)
            yyerror("Incompatible datatypes");
            else
            (yyval.str)=(yyvsp[-2].str);
          }
#line 1566 "y.tab.c"
    break;

  case 41: /* expression: expression DIV expression  */
#line 207 "S2A24444.y"
          {
            if(strcmp(dataType((yyvsp[-2].str)),dataType((yyvsp[0].str)))!=0)
            yyerror("Incompatible datatypes");
            else
            (yyval.str)=(yyvsp[-2].str);
          }
#line 1577 "y.tab.c"
    break;

  case 42: /* expression: expression MOD expression  */
#line 214 "S2A24444.y"
          {
            if(strcmp(dataType((yyvsp[-2].str)),dataType((yyvsp[0].str)))!=0)
            yyerror("Incompatible datatypes");
            else
            (yyval.str)=(yyvsp[-2].str);
          }
#line 1588 "y.tab.c"
    break;

  case 43: /* expression: expression EQUALS expression  */
#line 221 "S2A24444.y"
          {
            if(strcmp(dataType((yyvsp[-2].str)),dataType((yyvsp[0].str)))!=0)
            yyerror("Incompatible datatypes");
            else
            (yyval.str)="BOOLEAN";
          }
#line 1599 "y.tab.c"
    break;

  case 44: /* expression: expression NOTEQUAL expression  */
#line 228 "S2A24444.y"
          {
            if(strcmp(dataType((yyvsp[-2].str)),dataType((yyvsp[0].str)))!=0)
            yyerror("Incompatible datatypes");
            else
            (yyval.str)="BOOLEAN";
          }
#line 1610 "y.tab.c"
    break;

  case 45: /* expression: expression LESS expression  */
#line 235 "S2A24444.y"
          {
            if(strcmp(dataType((yyvsp[-2].str)),dataType((yyvsp[0].str)))!=0)
            yyerror("Incompatible datatypes");
            else
            (yyval.str)="BOOLEAN";
          }
#line 1621 "y.tab.c"
    break;

  case 46: /* expression: expression LESSEQUAL expression  */
#line 242 "S2A24444.y"
          {
            if(strcmp(dataType((yyvsp[-2].str)),dataType((yyvsp[0].str)))!=0)
            yyerror("Incompatible datatypes");
            else
            (yyval.str)="BOOLEAN";
          }
#line 1632 "y.tab.c"
    break;

  case 47: /* expression: expression GREATER expression  */
#line 249 "S2A24444.y"
          {
            if(strcmp(dataType((yyvsp[-2].str)),dataType((yyvsp[0].str)))!=0)
            yyerror("Incompatible datatypes");
            else
            (yyval.str)="BOOLEAN";
          }
#line 1643 "y.tab.c"
    break;

  case 48: /* expression: expression GREATEREQUAL expression  */
#line 256 "S2A24444.y"
          {
            if(strcmp(dataType((yyvsp[-2].str)),dataType((yyvsp[0].str)))!=0)
            yyerror("Incompatible datatypes");
            else
            (yyval.str)="BOOLEAN";
          }
#line 1654 "y.tab.c"
    break;

  case 49: /* expression: expression AND expression  */
#line 263 "S2A24444.y"
          {
            if(strcmp(dataType((yyvsp[-2].str)),dataType((yyvsp[0].str)))!=0)
            yyerror("Incompatible datatypes");
            else
            (yyval.str)="BOOLEAN";
          }
#line 1665 "y.tab.c"
    break;

  case 50: /* expression: expression OR expression  */
#line 270 "S2A24444.y"
          {
            if(strcmp(dataType((yyvsp[-2].str)),dataType((yyvsp[0].str)))!=0)
            yyerror("Incompatible datatypes");
            else
            (yyval.str)="BOOLEAN";
          }
#line 1676 "y.tab.c"
    break;

  case 51: /* expression: NOT expression  */
#line 277 "S2A24444.y"
          {
            if(strcmp(dataType((yyvsp[0].str)),"BOOLEAN")!=0)
              yyerror("Incompatible datatype");
            else
              (yyval.str)="BOOLEAN";
          }
#line 1687 "y.tab.c"
    break;

  case 52: /* primary_expression: IDENTIFIER  */
#line 286 "S2A24444.y"
                    {   
                        if(re==1)
                            assign_val_done((yyvsp[0].str));
                        char* dtm=dataType((yyvsp[0].str));
                        char* er="SEND ERROR";
                        if(strcmp(dtm,er)==0 && re==0)
                        {
                            yyerror("undeclared variable");
                        }
                        else if(re==0)
                        {   
                            if(is_Assigned((yyvsp[0].str))==1)
                              (yyval.str)=dtm;
                            else
                              yyerror("Variable not assigned a value");
                        }

                    }
#line 1710 "y.tab.c"
    break;

  case 53: /* primary_expression: IDENTIFIER LBRACKET primary_expression RBRACKET  */
#line 305 "S2A24444.y"
                    {    
                        if(re==1)     
                            assign_val_done((yyvsp[-3].str));  
                        char* dtm=dataType((yyvsp[-3].str));
                        if("%s\n",(yyvsp[-3].str)); 
                        char* er="SEND ERROR";

                        if(strcmp(dtm,er)==0 && re==0)
                        {   
                            yyerror("undeclared variable");
                        }
                        else if(re==0)
                        {
                            if(is_This_Array((yyvsp[-3].str))==0)
                            {
                                yyerror("The variable is not an array and the operation is of an array");
                            }
                            else
                            {   
                                if(strcmp((yyvsp[-1].str),"INT")==0)
                                (yyval.str)=dtm;        
                                else
                                yyerror("Expected Integer in array index");                      
                            }
                        }   
           
                    }
#line 1742 "y.tab.c"
    break;

  case 54: /* primary_expression: INTEGER  */
#line 333 "S2A24444.y"
                    {   
                        (yyval.str)=dataType_constant("INTEGER");
                    }
#line 1750 "y.tab.c"
    break;

  case 55: /* primary_expression: REALX  */
#line 337 "S2A24444.y"
                    {
                        (yyval.str)=dataType_constant("REALX");
                    }
#line 1758 "y.tab.c"
    break;

  case 56: /* primary_expression: CHARACTER  */
#line 341 "S2A24444.y"
                    {
                        (yyval.str)=dataType_constant("CHARACTER");
                    }
#line 1766 "y.tab.c"
    break;

  case 57: /* primary_expression: TRU  */
#line 345 "S2A24444.y"
                    {
                        (yyval.str)=dataType_constant("TRU");
                    }
#line 1774 "y.tab.c"
    break;

  case 58: /* primary_expression: FAL  */
#line 349 "S2A24444.y"
                    {
                        (yyval.str)=dataType_constant("FAL");
                    }
#line 1782 "y.tab.c"
    break;

  case 59: /* primary_expression: LPAREN expression RPAREN  */
#line 353 "S2A24444.y"
                    {
                        (yyval.str)=(yyvsp[-1].str);
                    }
#line 1790 "y.tab.c"
    break;


#line 1794 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 358 "S2A24444.y"


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
