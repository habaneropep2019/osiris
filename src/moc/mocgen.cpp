#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
#line 43 "moc.y"
void yyerror( char *msg );

#include "qlist.h"
#include "qdict.h"
#include "qstring.h"
#include "qdatetime.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>


static QCString rmWS( const char * );

enum AccessPerm { _PRIVATE, _PROTECTED, _PUBLIC };


struct Argument					/* single arg meta data*/
{
    Argument( char *left, char *right )
	{ leftType  = rmWS( left );
	  rightType = rmWS( right );
	  if ( leftType == "void" && rightType.isEmpty() )
	      leftType = "";
	}
    QCString leftType;
    QCString rightType;
};

class ArgList : public QList<Argument> {	/* member function arg list*/
public:
    ArgList() { setAutoDelete(TRUE); }
   ~ArgList() { clear(); }
};


struct Function					/* member function meta data*/
{						/*   used for signals and slots*/
    AccessPerm accessPerm;
    QCString    qualifier;			/* const or volatile*/
    QCString    name;
    QCString    type;
    int	       lineNo;
    ArgList   *args;
    Function() { args=0; }
   ~Function() { delete args; }
};

class FuncList : public QList<Function> {	/* list of member functions*/
public:
    FuncList() { setAutoDelete(TRUE); }
};


ArgList *addArg( Argument * );			/* add arg to tmpArgList*/
void	 addMember( char );			/* add tmpFunc to current class*/

char	*strnew( const char * );		/* returns a new string (copy)*/
char	*stradd( const char *, const char * );	/* add two strings*/
char	*stradd( const char *, const char *,	/* add three strings*/
			       const char * );
char	*straddSpc( const char *, const char * );
char	*straddSpc( const char *, const char *,
			       const char * );
char	*straddSpc( const char *, const char *,
		    const char *, const char * );

extern int yydebug;
bool	   lexDebug	   = FALSE;
bool	   grammarDebug	   = FALSE;
int	   lineNo;				/* current line number*/
bool	   errorControl	   = FALSE;		/* controlled errors*/
bool	   displayWarnings = TRUE;
bool	   skipClass;				/* don't generate for class*/
bool	   skipFunc;				/* don't generate for func*/
bool	   templateClass;			/* class is a template*/

ArgList	  *tmpArgList;				/* current argument list*/
Function  *tmpFunc;				/* current member function*/
AccessPerm tmpAccessPerm;			/* current access permission*/
AccessPerm subClassPerm;			/* current access permission*/
bool	   Q_OBJECTdetected;			/* TRUE if current class*/
						/* contains the Q_OBJECT macro*/
QCString   tmpExpression;

const int  formatRevision = 3;			/* moc output format revision*/

#line 132 "moc.y"
typedef union {
    char	char_val;
    int		int_val;
    double	double_val;
    char       *string;
    AccessPerm	access;
    Function   *function;
    ArgList    *arg_list;
    Argument   *arg;
} YYSTYPE;
#line 110 "y.tab.c"
#define CHAR_VAL 257
#define INT_VAL 258
#define DOUBLE_VAL 259
#define STRING 260
#define IDENTIFIER 261
#define FRIEND 262
#define TYPEDEF 263
#define AUTO 264
#define REGISTER 265
#define STATIC 266
#define EXTERN 267
#define INLINE 268
#define VIRTUAL 269
#define CONST 270
#define VOLATILE 271
#define CHAR 272
#define SHORT 273
#define INT 274
#define LONG 275
#define SIGNED 276
#define UNSIGNED 277
#define FLOAT 278
#define DOUBLE 279
#define VOID 280
#define ENUM 281
#define CLASS 282
#define STRUCT 283
#define UNION 284
#define ASM 285
#define PRIVATE 286
#define PROTECTED 287
#define PUBLIC 288
#define OPERATOR 289
#define DBL_COLON 290
#define TRIPLE_DOT 291
#define TEMPLATE 292
#define NAMESPACE 293
#define USING 294
#define MUTABLE 295
#define SIGNALS 296
#define SLOTS 297
#define Q_OBJECT 298
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,   36,   36,   36,   36,   36,   38,   38,   44,
   46,   42,   47,   48,   43,   45,   39,   41,   40,   40,
   50,   37,    1,    1,    2,   51,   52,   28,   28,   28,
   28,   28,   27,   29,   29,   30,   30,   53,   53,   53,
   53,   54,   54,   31,   31,   11,   11,   11,   12,   12,
   13,   13,   13,   13,   13,   13,   13,   13,   13,    3,
   55,   55,   14,   14,   15,   15,   16,   16,   17,   17,
   17,   18,   18,   20,   20,   56,   56,   19,   19,   23,
   57,   23,   23,   59,   23,   21,   21,   22,   60,   22,
   61,   22,   22,   22,   32,   32,   62,   32,   32,   58,
   63,   10,   10,   66,   10,   67,   10,   68,   65,   69,
   65,   35,   35,   34,   34,   33,   33,   24,   24,   25,
   25,   26,   26,   64,   64,   64,   71,   70,   74,   49,
   49,   49,   49,   76,   76,   76,   76,   76,   75,   75,
   72,    4,    4,   73,   73,   77,   77,   79,   79,   81,
   78,   82,   78,   78,   80,   80,   85,   80,   80,   83,
   83,   86,   86,   87,   84,   84,   89,   89,   90,   91,
   91,    5,    6,    6,    7,    7,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    9,    9,    9,   92,
   92,   92,   92,   92,   92,   92,   92,   92,   92,   92,
   92,   92,   92,   92,   92,   92,   92,   92,   92,   92,
   92,   92,   92,   92,   92,   92,   92,   92,   92,   92,
   92,   92,   92,   92,   92,   92,   92,   92,   92,   92,
   93,   93,   94,   94,   94,   94,   94,   94,   94,   94,
   94,   94,   94,   94,   88,   88,   88,   88,   88,   88,
   88,   96,   96,   98,   99,   98,  100,   98,   95,  101,
   95,  103,   97,  102,  102,
};
short yylen[] = {                                         2,
    0,    2,    1,    1,    1,    1,    1,    1,    1,    0,
    0,    7,    0,    0,    6,    1,    5,    2,    2,    2,
    0,    3,    1,    1,    4,    0,    0,    1,    1,    1,
    1,    1,    3,    0,    1,    1,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    2,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    4,
    0,    1,    2,    2,    1,    2,    3,    1,    2,    2,
    2,    2,    3,    0,    1,    0,    1,    3,    1,    2,
    0,    5,    4,    0,    7,    0,    1,    2,    0,    4,
    0,    5,    1,    3,    1,    2,    0,    5,    3,    1,
    5,    1,    2,    0,    4,    0,    5,    0,    4,    0,
    5,    0,    1,    1,    2,    2,    2,    0,    1,    1,
    2,    1,    1,    1,    1,    3,    0,    3,    0,    5,
    1,    4,    2,    1,    1,    1,    1,    1,    2,    3,
    2,    0,    1,    0,    1,    2,    1,    1,    1,    0,
    3,    0,    4,    1,    2,    3,    0,    3,    1,    0,
    1,    2,    1,    1,    0,    1,    2,    1,    1,    0,
    2,    2,    3,    1,    4,    4,    1,    3,    2,    3,
    2,    1,    3,    2,    3,    2,    1,    1,    1,    3,
    3,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    2,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    3,
    3,    2,    2,    2,    2,    1,    3,    2,    2,    2,
    0,    1,    2,    1,    3,    5,    2,    3,    4,    3,
    2,    6,    4,    5,    3,    4,    6,    3,    4,    5,
    3,    1,    3,    1,    0,    4,    0,    3,    0,    0,
    3,    0,    5,    0,    1,
};
short yydefred[] = {                                      1,
    0,    0,    0,    2,    3,    4,    5,    6,    7,    8,
    9,    0,    0,    0,   19,   20,   18,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   14,   26,  134,   38,
   39,   40,   41,   42,   43,   44,   45,   51,   52,   53,
   54,   55,   56,   57,   58,   59,  135,  136,  137,  138,
  133,    0,   68,   24,    0,   22,   63,   64,  129,    0,
    0,  141,  143,    0,    0,    0,    0,   11,    1,    0,
   26,  140,    0,    0,    0,    0,    0,  187,  188,  189,
    0,  182,  174,    0,  177,    0,   17,    1,    0,    0,
   60,    0,   67,  152,  149,  154,  148,    0,    0,  147,
  150,  132,    0,  184,    0,  179,    0,    0,  186,  181,
    0,   15,   25,    0,  130,  146,    0,    0,    0,  183,
  178,  173,  185,  180,   12,    0,  159,    0,    0,  157,
  151,  175,  176,    0,   31,   32,    0,    0,    0,    0,
    0,    0,   62,  234,    0,    0,   50,    0,   47,   46,
   36,    0,   29,   28,   30,  153,    0,  163,  164,    0,
    0,    0,  155,    0,    0,  104,  108,    0,    0,    0,
   71,    0,    0,    0,  226,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  241,
    0,    0,    0,    0,    0,    0,    0,  233,    0,  114,
    0,   49,   69,    0,    0,   37,  162,    0,    0,  260,
  170,    0,  170,  156,  169,    0,  168,  158,   27,   27,
  106,  110,  262,  215,  216,    0,  217,    0,  230,  229,
  207,  211,  222,  205,  224,  206,    0,  225,  208,  209,
  210,  212,  223,  213,  214,    0,    0,  251,    0,  170,
  240,  122,  123,  116,    0,  120,  117,    0,    0,    0,
  238,  115,   70,    0,  235,    0,    0,    0,   79,    0,
    0,   27,    0,  170,    0,    0,  167,  105,    0,   27,
   27,    0,  220,  221,  227,  190,  191,  170,    0,  121,
    0,  239,  243,    0,    0,    0,   77,   72,   89,    0,
    0,    0,   93,    0,  261,  171,    0,    0,    0,  257,
    0,   95,    0,  252,  109,  107,    0,  263,    0,  244,
    0,  236,    0,   73,   78,   27,    0,  100,   81,    0,
   91,   88,   33,  255,    0,   27,   97,   96,  170,    0,
  111,  242,  127,    0,  124,  101,  125,    0,   94,   27,
    0,   27,   27,   99,  258,   27,    0,  253,    0,    0,
   90,   82,   84,    0,  256,    0,  128,  126,   27,   92,
   98,   85,
};
short yydgoto[] = {                                      89,
   53,   54,  143,   62,   63,   81,   82,   83,   84,  144,
  145,  146,  147,  148,  149,   67,  150,  266,  267,  268,
  301,  302,  269,  254,  255,  256,  270,  151,  188,  189,
  153,  311,  200,  258,  259,    4,    5,    6,    7,    8,
    9,   10,   11,   26,   90,   88,   14,   69,   21,   12,
   70,  278,  154,  155,   22,  298,  350,  312,  369,  326,
  352,  356,  211,  346,  168,  219,  280,  220,  281,  347,
  359,   23,   98,   74,   24,   51,   99,  100,  101,  131,
  117,  114,  156,  214,  165,  157,  158,  215,  216,  217,
  273,  190,  160,  161,  212,  313,  162,  314,  353,  336,
  272,  170,  282,
};
short yysindex[] = {                                      0,
 -266, -226, -102,    0,    0,    0,    0,    0,    0,    0,
    0, -222,   12,  -28,    0,    0,    0,  106,  826, -121,
  115,  -63,  132,  168, -244,  161,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -59,    0,    0,    5,    0,    0,    0,    0,  -30,
  204,    0,    0,  262,   67,  271,    5,    0,    0,  314,
    0,    0,   67,  494,  293,  415,  213,    0,    0,    0,
  292,    0,    0,  136,    0,    5,    0,    0, -266,  267,
    0,  340,    0,    0,    0,    0,    0,  281,  494,    0,
    0,    0,  274,    0, -201,    0,  204, -201,    0,    0,
  299,    0,    0,  395,    0,    0,  -48,  435,  443,    0,
    0,    0,    0,    0,    0,  762,    0,  402,  444,    0,
    0,    0,    0,  313,    0,    0,    0,  232,  243,  419,
  246,  -66,    0,    0,  180,  911,    0,  248,    0,    0,
    0,  796,    0,    0,    0,    0,  762,    0,    0,  385,
  337,  477,    0,  762,  762,    0,    0,   52,    0,  414,
    0,  480,  272,  309,    0,  451,  547,  531,   14,  294,
  537,  539,  540,  541,    3,  566,  572,  534,  910,    0,
  514, -244,  606,  102,  419,  201,  201,    0,  252,    0,
   21,    0,    0,  410,  910,    0,    0,  454,  910,    0,
    0,   93,    0,    0,    0,  762,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  614,    0,  664,    0,    0,
    0,    0,    0,    0,    0,    0,  679,    0,    0,    0,
    0,    0,    0,    0,    0,  179,  179,    0,  670,    0,
    0,    0,    0,    0,  201,    0,    0,  179,   63,  419,
    0,    0,    0,  179,    0,  689,  712,  440,    0,  -22,
  592,    0,  703,    0,   27,  703,    0,    0,  691,    0,
    0,  663,    0,    0,    0,    0,    0,    0,  703,    0,
  419,    0,    0,   77,  201,  508,    0,    0,    0,  -22,
  -49,  108,    0,  910,    0,    0,  703,  731,  -32,    0,
  255,    0,  166,    0,    0,    0,  700,    0,  703,    0,
  419,    0,  -37,    0,    0,    0,  142,    0,    0,  -22,
    0,    0,    0,    0,  156,    0,    0,    0,    0,   27,
    0,    0,    0,  536,    0,    0,    0,  705,    0,    0,
  735,    0,    0,    0,    0,    0,  703,    0,  675,  790,
    0,    0,    0,  764,    0,  768,    0,    0,    0,    0,
    0,    0,
};
short yyrindex[] = {                                      0,
 -221,  751,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  249,  756,    0,    0,    0,    0,    0,  251,    0,
    0,    0,    0,  -40,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  109,    0,    0,  302,    0,    0,    0,    0,    0,
    0,    0,    0,   -4,    0,    0,    7,    0,    0,    0,
    0,    0,    0,  755,    0,   66,    0,    0,    0,    0,
  758,    0,    0,    0,    0,   38,    0,    0, -111,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  765,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -82,    0,    0,    0,    0,
    0,    0,    0,  118,    0,    0,  660,  766,    0,  637,
    0,    0,    0,    0,    0,   50,    0,    0,    0,    0,
    0,  249,    0,    0,    0,    0,   61,    0,    0,    0,
  426,    0,    0,  200,  200,    0,    0,  468,  169,    0,
    0,  743,  819,  860,    0,    0,    0,  909,  914,  925,
 1067, 1069, 1072, 1074, 1077, 1079, 1099,    0,  -38,    0,
    0,    0,    0, 1101,  637,   74,   74,    0,   89,    0,
    0,    0,    0,    0,  -33,    0,    0,    0,  137,    0,
    0,    0,    0,    0,    0,  242,    0,    0,    0,    0,
    0,    0,    0,    0,    0, 1104,    0, 1106,    0,    0,
    0,    0,    0,    0,    0,    0, 1109,    0,    0,    0,
    0,    0,    0,    0,    0, 1111, 1111,    0,    0,    0,
    0,    0,    0,    0,   62,    0,    0,  111,    0,  637,
    0,    0,    0,   89,    0,    0,  -10,  846,    0,  -11,
  249,    0,  297,    0,    0,  342,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  380,    0,
  637,    0,    0,    0,   13,  729,    0,    0,    0,    0,
  -12,  103,    0,   84,    0,    0,  430,  816,    0,    0,
  498,    0,    0,    0,    0,    0,    0,    0,  471,    0,
  637,    0,    0,    0,    0,    0,    0,    0,    0,   40,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   -2,    0,    0,    0,    0,    0,  554,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
short yygindex[] = {                                    891,
  157,    0,  880,    0,    0,    0,  285,  786,   80,  195,
 -137,    0,    2,  882,  778,   -7,    0,    0,    0,    0,
  565,  596,  603, -156,    0,  646,    0,  202,  -13,  640,
  883,  594,  687,  763,  231,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  858,    0,    0,    0,    0,    0,
  876,  625,  929,  936,    0,    0,    0,  655,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  861,    0,    0,
    0,    0,    0,  794,    0,    0,  805,  -19,    0,  747,
 -157, -118,    0,    0,    0,    0,    0,  624,    0,    0,
    0,    0,    0,
};
#define YYTABLESIZE 1191
short yytable[] = {                                      35,
   71,   35,   35,   35,   34,   35,  237,  309,   34,  130,
  237,  329,   55,   16,  205,  197,   64,  300,  131,  196,
   47,  345,   35,  344,  237,  237,    2,    3,   80,   86,
   75,   80,   86,   23,   13,   23,   23,   23,   83,   23,
  257,   83,  160,  231,   65,   65,   65,   65,   65,   86,
   65,  233,   35,   23,   23,  276,   23,   86,  197,   76,
   21,   21,  196,  242,   65,   65,  309,   65,  299,   18,
   21,  118,   25,  118,  232,   66,  251,   66,   66,   66,
   86,   66,  142,   86,  310,  343,   23,   48,   65,   48,
   48,   48,  289,   48,   27,   66,   66,   65,   66,  119,
   86,  119,  119,  119,  119,  119,  159,   48,   48,   23,
   48,  118,  221,  118,  118,  118,  307,  118,   23,  119,
  119,   34,  119,   34,   34,   34,  243,   34,   66,   65,
  319,  118,  118,  304,  118,  118,  275,  159,  323,   52,
   48,  293,  222,   87,   34,  197,   87,  202,   23,  196,
  113,  274,  119,   97,  113,   23,  105,  102,   15,   23,
   66,  102,  166,   87,  118,   28,   23,   23,  113,  113,
   21,   21,  320,   56,   34,  102,  102,   74,   97,  197,
   21,  357,  349,  196,  119,  161,  231,   16,   23,  247,
   17,  264,  167,  197,   64,  271,  354,  196,  331,   61,
   61,   64,  342,  160,  160,  160,   70,   60,   72,  340,
   70,  328,  127,  160,  160,  160,  197,  197,   57,   58,
  196,  196,   35,   65,  339,   61,  192,   34,  328,   93,
   75,   23,  331,   35,   35,   35,   35,   35,   35,   35,
   35,   35,   35,   35,   35,   35,  337,  128,  129,   86,
   35,   35,   35,   35,   59,   34,   23,   23,   23,   23,
   23,   23,   23,   23,   23,   23,   23,   65,   65,   65,
   65,   65,   65,   65,   65,   65,   65,   65,   80,   86,
   75,  194,  271,   68,   23,   23,   23,  308,   83,  197,
  333,  265,  197,  196,   73,   65,  196,   65,   66,   66,
   66,   66,   66,   66,   66,   66,   66,   66,   66,  260,
   48,   48,   48,   48,   48,   48,   48,   48,   48,   48,
   48,   71,  119,  194,  165,  231,   66,   64,   66,   87,
   86,  226,  225,  102,  118,  107,  235,  194,   48,  198,
   48,  139,   61,   61,   34,  337,  161,  161,  161,  112,
  119,  291,  119,  206,  234,   23,  161,  161,  161,  139,
  139,  104,  118,   87,  118,  321,  166,  231,  109,  227,
  228,  113,   71,  166,   34,   91,  209,  112,   23,   23,
   23,   23,   23,   23,   23,   23,   23,   23,   23,  120,
  206,  112,  123,   87,  210,  261,   76,   34,   23,  113,
  206,  113,  265,  167,  108,  115,   23,   23,   34,   34,
   34,   34,   34,   34,   34,   34,   34,   34,   34,   34,
   34,  245,  245,  125,  139,   65,   34,   74,   34,   70,
   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
  194,  135,  136,   30,   31,   32,   33,   34,   35,   36,
   37,  187,  126,  292,  103,  183,  179,   70,  177,  163,
  178,  180,  175,  181,   76,  182,  248,  248,  195,  259,
  252,  253,   77,   76,   71,  132,  286,  287,  173,  172,
  174,   61,   61,  133,  259,  165,  165,  165,  322,   78,
   79,   80,  169,   65,  294,  165,  165,  165,   78,   79,
   80,  164,   65,  171,  249,  249,  191,  103,  203,  176,
  208,  103,  184,  135,  136,   30,   31,   32,   33,   34,
   35,   36,   37,   61,   61,  103,  103,  166,  166,  166,
   61,   61,   62,   62,  118,  213,  223,  166,  166,  166,
  224,  254,  185,  229,  186,   38,   39,   40,   41,   42,
   43,   44,   45,   46,  246,  246,  254,  245,  245,  245,
  245,  245,  245,  245,  245,  245,  245,  245,  245,  245,
  245,  245,  245,  245,  245,  245,  245,  245,  245,  245,
  245,  238,  245,  245,  245,  245,  245,  230,  245,  245,
  245,  231,  245,  245,  245,  250,  250,  236,  237,  239,
  240,  241,  248,  248,  248,  248,  248,  248,  248,  248,
  248,  248,  248,  248,  248,  248,  248,  248,  248,  248,
  248,  248,  248,  248,  248,  248,  244,  248,  248,  248,
  248,  248,  245,  248,  248,  248,  248,  248,  248,  248,
  249,  249,  249,  249,  249,  249,  249,  249,  249,  249,
  249,  249,  249,  249,  249,  249,  249,  249,  249,  249,
  249,  249,  249,  249,  250,  249,  249,  249,  249,  249,
  263,  249,  249,  249,  283,  249,  249,  249,  247,  247,
  135,  136,   30,   31,   32,   33,   34,   35,   36,   37,
  246,  246,  246,  246,  246,  246,  246,  246,  246,  246,
  246,  246,  246,  246,  246,  246,  246,  246,  246,  246,
  246,  246,  246,  246,  194,  246,  246,  246,  246,  246,
  285,  246,  246,  246,  284,  246,  246,  246,  288,  295,
  297,  250,  250,  250,  250,  250,  250,  250,  250,  250,
  250,  250,  250,  250,  250,  250,  250,  250,  250,  250,
  250,  250,  250,  250,  250,  296,  250,  250,  250,  250,
  250,  306,  250,  250,  250,  152,  250,  250,  250,  135,
  136,   30,   31,   32,   33,   34,   35,   36,   37,   78,
   79,   80,  202,  315,  199,  232,  202,  318,  334,   94,
   95,   96,  341,  360,  246,  363,  152,  361,  324,  367,
  202,  202,   66,  152,  152,   38,   39,   40,   41,   42,
   43,   44,   45,   46,  247,  247,  247,  247,  247,  247,
  247,  247,  247,  247,  247,  247,  247,  247,  247,  247,
  247,  247,  247,  247,  247,  247,  247,  247,   85,  247,
  247,  247,  247,  247,  279,  247,  247,  247,  368,  247,
  247,  247,   64,  100,  106,  152,  370,  100,  203,  100,
  371,  110,  203,   38,   39,   40,   41,   42,   43,   44,
   45,   46,  204,   13,  100,  139,  203,  203,   10,  144,
  172,   65,  121,   18,   85,  124,   76,  262,  264,  145,
    1,   19,  122,   20,  351,  327,  305,   34,  325,  204,
  290,   48,  335,  204,  316,  317,  100,  201,   34,   34,
   34,   34,   34,   34,   34,   34,   34,  204,  204,  193,
   43,   43,   43,   43,   43,   43,   43,   43,   43,   43,
   43,   43,   43,   43,   43,   43,   43,   43,   43,   43,
   43,   43,   43,   43,  262,  111,   92,   49,  194,   43,
  348,   43,  194,  198,   50,  330,  303,  198,  218,  116,
  355,  207,  277,  358,  192,    0,  194,  194,  192,  249,
    0,  198,  198,    0,  362,    0,  364,  365,    0,    0,
  366,    0,  192,  192,    0,    0,  303,    0,  332,   34,
    0,    0,    0,  372,    0,    0,    0,  338,    0,    0,
   34,   34,   34,   34,   34,   34,   34,   34,   34,   34,
   34,   34,   34,  332,    0,    0,  303,    0,   34,    0,
   34,  338,  134,  135,  136,   30,   31,   32,   33,   34,
  137,   36,   37,   38,   39,   40,   41,   42,   43,   44,
   45,   46,  138,    0,    0,  139,    0,    0,    0,    0,
  140,   65,    0,   18,  141,  142,   64,  135,  136,   30,
   31,   32,   33,   34,   35,   36,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,  204,    0,    0,  139,
    0,    0,    0,    0,    0,   65,   29,   18,    0,   30,
   31,   32,   33,   34,   35,   36,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,  193,    0,  195,    0,
  193,  196,  195,  197,    0,  196,  199,  197,  200,    0,
  199,    0,  200,    0,  193,  193,  195,  195,    0,  196,
  196,  197,  197,    0,  199,  199,  200,  200,  201,    0,
  102,    0,  201,  218,  102,  219,    0,  218,  228,  219,
  112,    0,  228,    0,  112,    0,  201,  201,  102,  102,
    0,  218,  218,  219,  219,    0,  228,  228,  112,  112,
    0,  135,  136,   30,   31,   32,   33,   34,   35,   36,
   37,    0,   38,   39,   40,   41,   42,   43,   44,   45,
   46,
};
short yycheck[] = {                                      38,
   60,   40,   41,   42,   38,   44,   40,   40,   42,   58,
   44,   61,   20,  125,  152,   38,  261,   40,   59,   42,
   19,   59,   61,   61,   58,   59,  293,  294,   41,   41,
   41,   44,   44,   38,  261,   40,   41,   42,   41,   44,
  197,   44,  125,  126,   38,  290,   40,   41,   42,   61,
   44,   38,   91,   58,   59,  213,   61,   65,   38,  261,
  282,  283,   42,   61,   58,   59,   40,   61,   91,  292,
  292,   59,   61,   61,   61,   38,  195,   40,   41,   42,
   41,   44,  123,   44,   58,  123,   91,   38,  290,   40,
   41,   42,  250,   44,  123,   58,   59,   91,   61,   38,
   61,   40,   41,   42,  103,   44,  126,   58,   59,   44,
   61,   38,   61,   40,   41,   42,  274,   44,  123,   58,
   59,   38,   61,   40,   41,   42,  124,   44,   91,  123,
  288,   58,   59,  271,   61,  123,   44,  157,  295,  261,
   91,  260,   91,   41,   61,   38,   44,  146,   40,   42,
   40,   59,   91,   74,   44,   38,   77,   40,  261,   42,
  123,   44,   61,   61,   91,   60,   58,   59,   58,   59,
  282,  283,  291,   59,   91,   58,   59,   41,   99,   38,
  292,  339,   41,   42,  123,  125,  126,  290,  123,  188,
  293,  205,   91,   38,  261,  209,   41,   42,   91,  282,
  283,  261,  321,  286,  287,  288,   38,   40,   52,   44,
   42,  261,  261,  296,  297,  298,   38,   38,  282,  283,
   42,   42,  261,  290,   59,   58,  293,  261,  261,   73,
  261,  123,   91,  272,  273,  274,  275,  276,  277,  278,
  279,  280,  281,  282,  283,  284,   91,  296,  297,  261,
  289,  290,  291,  292,  123,  289,  261,  262,  263,  264,
  265,  266,  267,  268,  269,  270,  271,  261,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  291,  291,
  291,  261,  296,  123,  289,  290,  291,  261,  291,   38,
  304,  123,   38,   42,  290,  289,   42,  291,  261,  262,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  289,
  261,  262,  263,  264,  265,  266,  267,  268,  269,  270,
  271,   60,  261,  261,  125,  126,  289,  261,  291,   59,
  291,   60,   61,   41,  261,   44,   43,  261,  289,  145,
  291,   40,  282,  283,  261,   91,  286,  287,  288,  261,
  289,  289,  291,  152,   61,  290,  296,  297,  298,   58,
   59,   77,  289,  261,  291,  289,  125,  126,   84,   61,
   62,  261,   60,   61,  291,   62,   40,  289,  261,  262,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  105,
  189,  125,  108,  291,   58,  201,  261,  261,  290,  289,
  199,   62,  208,   91,  269,  125,  289,  290,  272,  273,
  274,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  284,  125,  126,  125,  123,  290,  290,  291,  292,  261,
  262,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  261,  262,  263,  264,  265,  266,  267,  268,  269,  270,
  271,   33,   58,  259,   40,   37,   38,  289,   40,   58,
   42,   43,   44,   45,  261,   47,  125,  126,  289,   44,
  270,  271,  269,  261,   60,   41,  246,  247,   60,   61,
   62,  282,  283,   41,   59,  286,  287,  288,  294,  286,
  287,  288,  261,  290,  264,  296,  297,  298,  286,  287,
  288,   58,  290,  261,  125,  126,  261,   40,  261,   91,
  126,   44,   94,  262,  263,  264,  265,  266,  267,  268,
  269,  270,  271,  282,  283,   58,   59,  286,  287,  288,
  282,  283,  282,  283,  261,   59,  123,  296,  297,  298,
   61,   44,  124,   93,  126,  272,  273,  274,  275,  276,
  277,  278,  279,  280,  125,  126,   59,  261,  262,  263,
  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  284,   45,  286,  287,  288,  289,  290,   41,  292,  293,
  294,   61,  296,  297,  298,  125,  126,   61,   62,   61,
   61,   61,  261,  262,  263,  264,  265,  266,  267,  268,
  269,  270,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  280,  281,  282,  283,  284,   61,  286,  287,  288,
  289,  290,   61,  292,  293,  294,  123,  296,  297,  298,
  261,  262,  263,  264,  265,  266,  267,  268,  269,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  281,  282,  283,  284,   59,  286,  287,  288,  289,  290,
  261,  292,  293,  294,   61,  296,  297,  298,  125,  126,
  262,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  261,  262,  263,  264,  265,  266,  267,  268,  269,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  281,  282,  283,  284,  261,  286,  287,  288,  289,  290,
   42,  292,  293,  294,   61,  296,  297,  298,   59,   41,
  291,  261,  262,  263,  264,  265,  266,  267,  268,  269,
  270,  271,  272,  273,  274,  275,  276,  277,  278,  279,
  280,  281,  282,  283,  284,   44,  286,  287,  288,  289,
  290,   59,  292,  293,  294,  126,  296,  297,  298,  262,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  286,
  287,  288,   40,   93,  145,  126,   44,  125,   58,  296,
  297,  298,   93,  258,  261,   61,  157,   93,  291,  125,
   58,   59,   25,  164,  165,  272,  273,  274,  275,  276,
  277,  278,  279,  280,  261,  262,  263,  264,  265,  266,
  267,  268,  269,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  280,  281,  282,  283,  284,   61,  286,
  287,  288,  289,  290,  220,  292,  293,  294,   59,  296,
  297,  298,  261,   38,   77,  216,   93,   42,   40,   44,
   93,   84,   44,  272,  273,  274,  275,  276,  277,  278,
  279,  280,  281,  123,   59,  284,   58,   59,  123,  125,
  123,  290,  105,  292,  107,  108,   41,  201,  123,  125,
    0,   12,  107,   12,  330,  300,  272,  261,  296,   40,
  255,   19,  309,   44,  280,  281,   91,  145,  272,  273,
  274,  275,  276,  277,  278,  279,  280,   58,   59,  142,
  261,  262,  263,  264,  265,  266,  267,  268,  269,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  281,  282,  283,  284,  258,   88,   71,   19,   40,  290,
  326,  292,   44,   40,   19,  301,  270,   44,  165,   99,
  336,  157,  216,  340,   40,   -1,   58,   59,   44,  192,
   -1,   58,   59,   -1,  350,   -1,  352,  353,   -1,   -1,
  356,   -1,   58,   59,   -1,   -1,  300,   -1,  302,  261,
   -1,   -1,   -1,  369,   -1,   -1,   -1,  311,   -1,   -1,
  272,  273,  274,  275,  276,  277,  278,  279,  280,  281,
  282,  283,  284,  327,   -1,   -1,  330,   -1,  290,   -1,
  292,  335,  261,  262,  263,  264,  265,  266,  267,  268,
  269,  270,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  280,  281,   -1,   -1,  284,   -1,   -1,   -1,   -1,
  289,  290,   -1,  292,  293,  294,  261,  262,  263,  264,
  265,  266,  267,  268,  269,  270,  271,  272,  273,  274,
  275,  276,  277,  278,  279,  280,  281,   -1,   -1,  284,
   -1,   -1,   -1,   -1,   -1,  290,  261,  292,   -1,  264,
  265,  266,  267,  268,  269,  270,  271,  272,  273,  274,
  275,  276,  277,  278,  279,  280,   40,   -1,   40,   -1,
   44,   40,   44,   40,   -1,   44,   40,   44,   40,   -1,
   44,   -1,   44,   -1,   58,   59,   58,   59,   -1,   58,
   59,   58,   59,   -1,   58,   59,   58,   59,   40,   -1,
   40,   -1,   44,   40,   44,   40,   -1,   44,   40,   44,
   40,   -1,   44,   -1,   44,   -1,   58,   59,   58,   59,
   -1,   58,   59,   58,   59,   -1,   58,   59,   58,   59,
   -1,  262,  263,  264,  265,  266,  267,  268,  269,  270,
  271,   -1,  272,  273,  274,  275,  276,  277,  278,  279,
  280,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 298
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,
0,0,0,0,0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"CHAR_VAL","INT_VAL",
"DOUBLE_VAL","STRING","IDENTIFIER","FRIEND","TYPEDEF","AUTO","REGISTER",
"STATIC","EXTERN","INLINE","VIRTUAL","CONST","VOLATILE","CHAR","SHORT","INT",
"LONG","SIGNED","UNSIGNED","FLOAT","DOUBLE","VOID","ENUM","CLASS","STRUCT",
"UNION","ASM","PRIVATE","PROTECTED","PUBLIC","OPERATOR","DBL_COLON",
"TRIPLE_DOT","TEMPLATE","NAMESPACE","USING","MUTABLE","SIGNALS","SLOTS",
"Q_OBJECT",
};
char *yyrule[] = {
"$accept : declaration_seq",
"declaration_seq :",
"declaration_seq : declaration_seq declaration",
"declaration : class_def",
"declaration : namespace_def",
"declaration : namespace_alias_def",
"declaration : using_declaration",
"declaration : using_directive",
"namespace_def : named_namespace_def",
"namespace_def : unnamed_namespace_def",
"$$1 :",
"$$2 :",
"named_namespace_def : NAMESPACE IDENTIFIER $$1 '{' $$2 namespace_body '}'",
"$$3 :",
"$$4 :",
"unnamed_namespace_def : NAMESPACE $$3 '{' $$4 namespace_body '}'",
"namespace_body : declaration_seq",
"namespace_alias_def : NAMESPACE IDENTIFIER '=' complete_class_name ';'",
"using_directive : USING NAMESPACE",
"using_declaration : USING IDENTIFIER",
"using_declaration : USING DBL_COLON",
"$$5 :",
"class_def : $$5 class_specifier ';'",
"class_name : IDENTIFIER",
"class_name : template_class_name",
"template_class_name : IDENTIFIER '<' template_args '>'",
"template_args :",
"const_expression :",
"decl_specifier : storage_class_specifier",
"decl_specifier : type_specifier",
"decl_specifier : fct_specifier",
"decl_specifier : FRIEND",
"decl_specifier : TYPEDEF",
"decl_specifiers : decl_specs_opt type_name decl_specs_opt",
"decl_specs_opt :",
"decl_specs_opt : decl_specs",
"decl_specs : decl_specifier",
"decl_specs : decl_specs decl_specifier",
"storage_class_specifier : AUTO",
"storage_class_specifier : REGISTER",
"storage_class_specifier : STATIC",
"storage_class_specifier : EXTERN",
"fct_specifier : INLINE",
"fct_specifier : VIRTUAL",
"type_specifier : CONST",
"type_specifier : VOLATILE",
"type_name : elaborated_type_specifier",
"type_name : complete_class_name",
"type_name : simple_type_names",
"simple_type_names : simple_type_names simple_type_name",
"simple_type_names : simple_type_name",
"simple_type_name : CHAR",
"simple_type_name : SHORT",
"simple_type_name : INT",
"simple_type_name : LONG",
"simple_type_name : SIGNED",
"simple_type_name : UNSIGNED",
"simple_type_name : FLOAT",
"simple_type_name : DOUBLE",
"simple_type_name : VOID",
"template_spec : TEMPLATE '<' template_args '>'",
"opt_template_spec :",
"opt_template_spec : template_spec",
"class_key : opt_template_spec CLASS",
"class_key : opt_template_spec STRUCT",
"complete_class_name : qualified_class_name",
"complete_class_name : DBL_COLON qualified_class_name",
"qualified_class_name : qualified_class_name DBL_COLON class_name",
"qualified_class_name : class_name",
"elaborated_type_specifier : class_key IDENTIFIER",
"elaborated_type_specifier : ENUM IDENTIFIER",
"elaborated_type_specifier : UNION IDENTIFIER",
"argument_declaration_list : arg_declaration_list_opt triple_dot_opt",
"argument_declaration_list : arg_declaration_list ',' TRIPLE_DOT",
"arg_declaration_list_opt :",
"arg_declaration_list_opt : arg_declaration_list",
"triple_dot_opt :",
"triple_dot_opt : TRIPLE_DOT",
"arg_declaration_list : arg_declaration_list ',' argument_declaration",
"arg_declaration_list : argument_declaration",
"argument_declaration : decl_specifiers abstract_decl_opt",
"$$6 :",
"argument_declaration : decl_specifiers abstract_decl_opt '=' $$6 const_expression",
"argument_declaration : decl_specifiers abstract_decl_opt dname abstract_decl_opt",
"$$7 :",
"argument_declaration : decl_specifiers abstract_decl_opt dname abstract_decl_opt '=' $$7 const_expression",
"abstract_decl_opt :",
"abstract_decl_opt : abstract_decl",
"abstract_decl : abstract_decl ptr_operator",
"$$8 :",
"abstract_decl : '[' $$8 const_expression ']'",
"$$9 :",
"abstract_decl : abstract_decl '[' $$9 const_expression ']'",
"abstract_decl : ptr_operator",
"abstract_decl : '(' abstract_decl ')'",
"declarator : dname",
"declarator : declarator ptr_operator",
"$$10 :",
"declarator : declarator '[' $$10 const_expression ']'",
"declarator : '(' declarator ')'",
"dname : IDENTIFIER",
"fct_decl : '(' argument_declaration_list ')' cv_qualifier_list_opt fct_body_or_semicolon",
"fct_name : IDENTIFIER",
"fct_name : IDENTIFIER array_decls",
"$$11 :",
"fct_name : IDENTIFIER '=' $$11 const_expression",
"$$12 :",
"fct_name : IDENTIFIER array_decls '=' $$12 const_expression",
"$$13 :",
"array_decls : '[' $$13 const_expression ']'",
"$$14 :",
"array_decls : array_decls '[' $$14 const_expression ']'",
"ptr_operators_opt :",
"ptr_operators_opt : ptr_operators",
"ptr_operators : ptr_operator",
"ptr_operators : ptr_operators ptr_operator",
"ptr_operator : '*' cv_qualifier_list_opt",
"ptr_operator : '&' cv_qualifier_list_opt",
"cv_qualifier_list_opt :",
"cv_qualifier_list_opt : cv_qualifier_list",
"cv_qualifier_list : cv_qualifier",
"cv_qualifier_list : cv_qualifier_list cv_qualifier",
"cv_qualifier : CONST",
"cv_qualifier : VOLATILE",
"fct_body_or_semicolon : ';'",
"fct_body_or_semicolon : fct_body",
"fct_body_or_semicolon : '=' INT_VAL ';'",
"$$15 :",
"fct_body : '{' $$15 '}'",
"$$16 :",
"class_specifier : full_class_head '{' $$16 opt_obj_member_list '}'",
"class_specifier : class_head",
"class_specifier : class_head '(' IDENTIFIER ')'",
"class_specifier : template_spec whatever",
"whatever : IDENTIFIER",
"whatever : simple_type_name",
"whatever : type_specifier",
"whatever : storage_class_specifier",
"whatever : fct_specifier",
"class_head : class_key qualified_class_name",
"class_head : class_key IDENTIFIER class_name",
"full_class_head : class_head opt_base_spec",
"opt_base_spec :",
"opt_base_spec : base_spec",
"opt_obj_member_list :",
"opt_obj_member_list : obj_member_list",
"obj_member_list : obj_member_list obj_member_area",
"obj_member_list : obj_member_area",
"qt_access_specifier : access_specifier",
"qt_access_specifier : SLOTS",
"$$17 :",
"obj_member_area : qt_access_specifier $$17 slot_area",
"$$18 :",
"obj_member_area : SIGNALS $$18 ':' opt_signal_declarations",
"obj_member_area : Q_OBJECT",
"slot_area : SIGNALS ':'",
"slot_area : SLOTS ':' opt_slot_declarations",
"$$19 :",
"slot_area : ':' $$19 opt_slot_declarations",
"slot_area : IDENTIFIER",
"opt_signal_declarations :",
"opt_signal_declarations : signal_declarations",
"signal_declarations : signal_declarations signal_declaration",
"signal_declarations : signal_declaration",
"signal_declaration : signal_or_slot",
"opt_slot_declarations :",
"opt_slot_declarations : slot_declarations",
"slot_declarations : slot_declarations slot_declaration",
"slot_declarations : slot_declaration",
"slot_declaration : signal_or_slot",
"opt_semicolons :",
"opt_semicolons : opt_semicolons ';'",
"base_spec : ':' base_list",
"base_list : base_list ',' base_specifier",
"base_list : base_specifier",
"qt_macro_name : IDENTIFIER '(' IDENTIFIER ')'",
"qt_macro_name : IDENTIFIER '(' simple_type_name ')'",
"base_specifier : complete_class_name",
"base_specifier : VIRTUAL access_specifier complete_class_name",
"base_specifier : VIRTUAL complete_class_name",
"base_specifier : access_specifier VIRTUAL complete_class_name",
"base_specifier : access_specifier complete_class_name",
"base_specifier : qt_macro_name",
"base_specifier : VIRTUAL access_specifier qt_macro_name",
"base_specifier : VIRTUAL qt_macro_name",
"base_specifier : access_specifier VIRTUAL qt_macro_name",
"base_specifier : access_specifier qt_macro_name",
"access_specifier : PRIVATE",
"access_specifier : PROTECTED",
"access_specifier : PUBLIC",
"operator_name : decl_specs_opt IDENTIFIER ptr_operators_opt",
"operator_name : decl_specs_opt simple_type_name ptr_operators_opt",
"operator_name : '+'",
"operator_name : '-'",
"operator_name : '*'",
"operator_name : '/'",
"operator_name : '%'",
"operator_name : '^'",
"operator_name : '&'",
"operator_name : '|'",
"operator_name : '~'",
"operator_name : '!'",
"operator_name : '='",
"operator_name : '<'",
"operator_name : '>'",
"operator_name : '+' '='",
"operator_name : '-' '='",
"operator_name : '*' '='",
"operator_name : '/' '='",
"operator_name : '%' '='",
"operator_name : '^' '='",
"operator_name : '&' '='",
"operator_name : '|' '='",
"operator_name : '~' '='",
"operator_name : '!' '='",
"operator_name : '=' '='",
"operator_name : '<' '='",
"operator_name : '>' '='",
"operator_name : '<' '<'",
"operator_name : '>' '>'",
"operator_name : '<' '<' '='",
"operator_name : '>' '>' '='",
"operator_name : '&' '&'",
"operator_name : '|' '|'",
"operator_name : '+' '+'",
"operator_name : '-' '-'",
"operator_name : ','",
"operator_name : '-' '>' '*'",
"operator_name : '-' '>'",
"operator_name : '(' ')'",
"operator_name : '[' ']'",
"opt_virtual :",
"opt_virtual : VIRTUAL",
"type_and_name : type_name fct_name",
"type_and_name : fct_name",
"type_and_name : opt_virtual '~' fct_name",
"type_and_name : decl_specs type_name decl_specs_opt ptr_operators_opt fct_name",
"type_and_name : decl_specs type_name",
"type_and_name : type_name ptr_operators fct_name",
"type_and_name : type_name decl_specs ptr_operators_opt fct_name",
"type_and_name : type_name OPERATOR operator_name",
"type_and_name : OPERATOR operator_name",
"type_and_name : decl_specs type_name decl_specs_opt ptr_operators_opt OPERATOR operator_name",
"type_and_name : type_name ptr_operators OPERATOR operator_name",
"type_and_name : type_name decl_specs ptr_operators_opt OPERATOR operator_name",
"signal_or_slot : type_and_name fct_decl opt_semicolons",
"signal_or_slot : type_and_name opt_bitfield ';' opt_semicolons",
"signal_or_slot : type_and_name opt_bitfield ',' member_declarator_list ';' opt_semicolons",
"signal_or_slot : enum_specifier ';' opt_semicolons",
"signal_or_slot : USING complete_class_name ';' opt_semicolons",
"signal_or_slot : USING NAMESPACE complete_class_name ';' opt_semicolons",
"signal_or_slot : NAMESPACE IDENTIFIER '{'",
"member_declarator_list : member_declarator",
"member_declarator_list : member_declarator_list ',' member_declarator",
"member_declarator : declarator",
"$$20 :",
"member_declarator : IDENTIFIER ':' $$20 const_expression",
"$$21 :",
"member_declarator : ':' $$21 const_expression",
"opt_bitfield :",
"$$22 :",
"opt_bitfield : ':' $$22 const_expression",
"$$23 :",
"enum_specifier : ENUM opt_identifier '{' $$23 '}'",
"opt_identifier :",
"opt_identifier : IDENTIFIER",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 836 "moc.y"

#if defined(_OS_WIN32_)
#include <io.h>
#undef isatty
extern "C" int hack_isatty( int )
{
    return 0;
}
#define isatty hack_isatty
#else
#include <unistd.h>
#endif

#include "lex.yy.c"

void 	  init();				// initialize
void 	  initClass();				// prepare for new class
void 	  generateClass();			// generate C++ code for class
void 	  initExpression();			// prepare for new expression
QCString  combinePath( const char *, const char * );

QCString  fileName;				// file name
QCString  outputFile;				// output file name
QCString  includeFile;				// name of #include file
QCString  includePath;				// #include file path
QCString  qtPath;				// #include qt file path
bool	  noInclude     = FALSE;		// no #include <filename>
bool	  generatedCode = FALSE;		// no code generated
bool	  mocError = FALSE;			// moc parsing error occurred
QCString  className;				// name of parsed class
QCString  superclassName;			// name of super class
FuncList  signals;				// signal interface
FuncList  slots;				// slots interface

FILE  *out;					// output file

int yyparse();

void replace( char *s, char c1, char c2 );

int main( int argc, char **argv )
{
    bool autoInclude = TRUE;
    char *error	     = 0;
    qtPath = "";
    for ( int n=1; n<argc && error==0; n++ ) {
	QCString arg = argv[n];
	if ( arg[0] == '-' ) {			// option
	    QCString opt = &arg[1];
	    if ( opt[0] == 'o' ) {		// output redirection
		if ( opt[1] == '\0' ) {
		    if ( !(n < argc-1) ) {
			error = "Missing output-file name";
			break;
		    }
		    outputFile = argv[++n];
		} else
		    outputFile = &opt[1];
	    } else if ( opt == "i" ) {		// no #include statement
		noInclude   = TRUE;
		autoInclude = FALSE;
	    } else if ( opt[0] == 'f' ) {	// produce #include statement
		noInclude   = FALSE;
		autoInclude = FALSE;
		if ( opt[1] ) {			// -fsomething.h
		    includeFile = &opt[1];
		}
	    } else if ( opt[0] == 'p' ) {	// include file path
		if ( opt[1] == '\0' ) {
		    if ( !(n < argc-1) ) {
			error = "Missing path name for the -p option.";
			break;
		    }
		    includePath = argv[++n];
		} else {
		    includePath = &opt[1];
		}
	    } else if ( opt[0] == 'q' ) {	// qt include file path
		if ( opt[1] == '\0' ) {
		    if ( !(n < argc-1) ) {
			error = "Missing path name for the -q option.";
			break;
		    }
		    qtPath = argv[++n];
		} else {
		    qtPath = &opt[1];
		}
		replace(qtPath.data(),'\\','/');
		if ( qtPath.right(1) != "/" )
		    qtPath += '/';
	    } else if ( opt == "k" ) {		// don't stop on errors
		errorControl = TRUE;
	    } else if ( opt == "nw" ) {		// don't display warnings
		displayWarnings = FALSE;
	    } else if ( opt == "ldbg" ) {	// lex debug output
		lexDebug = TRUE;
	    } else if ( opt == "ydbg" ) {	// yacc debug output
		yydebug = TRUE;
	    } else if ( opt == "dbg" ) {	// non-signal members are slots
		grammarDebug = TRUE;
	    } else {
		error = "Invalid argument";
	    }
	} else {
	    if ( !fileName.isNull() )		// can handle only one file
		error	 = "Too many input files specified";
	    else
		fileName = arg.copy();
	}
    }

    if ( autoInclude ) {
	int ppos = fileName.findRev('.');
	if ( ppos != -1 && tolower( fileName[ppos + 1] ) == 'h' )
	    noInclude = FALSE;
	else
	    noInclude = TRUE;
    }
    if ( !fileName.isEmpty() && !outputFile.isEmpty() &&
	 includeFile.isEmpty() && includePath.isEmpty() ) {
	includeFile = combinePath(fileName,outputFile);
    }
    if ( includeFile.isEmpty() )
	includeFile = fileName.copy();
    if ( !includePath.isEmpty() ) {
	if ( includePath.right(1) != "/" )
	    includePath += '/';
	includeFile = includePath + includeFile;
    }
    if ( fileName.isNull() && !error ) {
	fileName = "standard input";
	yyin	 = stdin;
    } else if ( argc < 2 || error ) {		// incomplete/wrong args
	fprintf( stderr, "Qt meta object compiler\n" );
	if ( error )
	    fprintf( stderr, "moc: %s\n", error );
	fprintf( stderr, "Usage:  moc [options] <header-file>\n"
		 "\t-o file  Write output to file rather than stdout\n"
		 "\t-i       Do not generate an #include statement\n"
		 "\t-f[file] Force #include, optional file name\n"
		 "\t-p path  Path prefix for included file\n"
		 "\t-k       Do not stop on errors\n"
		 "\t-nw      Do not display warnings\n"
#if 0
		 "\t-ldbg    lex debug output\n"
		 "\t-ydbg    yacc debug output\n"
		 "\t-dbg     test parser, all non-signal members are slots\n"
#endif
		 );
	return 1;
    } else {
	yyin = fopen( (const char *)fileName, "r" );
	if ( !yyin ) {
	    fprintf( stderr, "moc: %s: No such file\n", (const char*)fileName);
	    return 1;
	}
    }
    if ( !outputFile.isEmpty() ) {		// output file specified
	out = fopen( (const char *)outputFile, "w" );	// create output file
	if ( !out ) {
	    fprintf( stderr, "moc: Cannot create %s\n",
		     (const char*)outputFile );
	    return 1;
	}
    } else {					// use stdout
	out = stdout;
    }
    init();
    yyparse();
    fclose( yyin );
    if ( !outputFile.isNull() )
	fclose( out );

    if ( !generatedCode && displayWarnings && !mocError ) {
        fprintf( stderr, "%s:%d: Warning: %s\n", fileName.data(), 0,
		 "No relevant classes found. No output generated." );
    }

    slots.clear();
    signals.clear();

    return mocError ? 1 : 0;
}

void replace( char *s, char c1, char c2 )
{
    if ( !s )
	return;
    while ( *s ) {
	if ( *s == c1 )
	    *s = c2;
	s++;
    }
}

/*
  This function looks at two file names and returns the name of the
  infile, with a path relative to outfile. Examples:
    /tmp/abc	/tmp/bcd	->	abc
    xyz/a/bc	xyz/b/ac	->	../a/bc
    /tmp/abc	xyz/klm		-)	/tmp/abc
 */

QCString combinePath( const char *infile, const char *outfile )
{
    QCString a = infile;  replace(a.data(),'\\','/');
    QCString b = outfile; replace(b.data(),'\\','/');
    a = a.stripWhiteSpace();
    b = b.stripWhiteSpace();
    QCString r;
    int i = 0;
    int ncommondirs = 0;
    while ( a[i] && a[i] == b[i] ) {
	if ( a[i] == '/' && i > 0 )
	    ncommondirs++;
	i++;
    }
    if ( ncommondirs > 0 ) {			// common base directory
	while ( i>=0 ) {
	    if ( a[i] == '/' && b[i] == '/' )
		break;
	    --i;
	}
	++i;
	a = &a[i];
	b = &b[i];
    } else {
	if ( (a[0] == '/') || (isalpha(a[0]) && a[1] == ':') )
	    return a;
	b = &b[i];
    }
    i = b.contains('/');
    while ( i-- > 0 )
	r += "../";
    r += a;
    return r;
}


#define getenv hack_getenv			// workaround for byacc
char *getenv()		     { return 0; }
char *getenv( const char * ) { return 0; }


void init()					// initialize
{
    BEGIN OUTSIDE;
    lineNo	 = 1;
    skipClass	 = FALSE;
    skipFunc	 = FALSE;
    signals.setAutoDelete( TRUE );
    slots.setAutoDelete( TRUE );

    tmpArgList	 = new ArgList;
    CHECK_PTR( tmpArgList );
    tmpFunc	 = new Function;
    CHECK_PTR( tmpFunc );
}

void initClass()				 // prepare for new class
{
    tmpAccessPerm    = _PRIVATE;
    subClassPerm     = _PRIVATE;
    Q_OBJECTdetected = FALSE;
    skipClass	     = FALSE;
    templateClass    = FALSE;
    slots.clear();
    signals.clear();
}

struct NamespaceInfo
{
    QCString name;
    int pLevelOnEntering; // Parenthesis level on entering the namespace
    QDict<char> definedClasses; // Classes defined in the namespace
};

QList<NamespaceInfo> namespaces;

void enterNameSpace( const char *name = 0 )   	 // prepare for new class
{
    static bool first = TRUE;
    if ( first ) {
	namespaces.setAutoDelete( TRUE );
	first = FALSE;
    }
	
    NamespaceInfo *tmp = new NamespaceInfo;
    if ( name )
	tmp->name = name;
    tmp->pLevelOnEntering = namespacePLevel;
    namespaces.append( tmp );
}

void leaveNameSpace()				 // prepare for new class
{
    NamespaceInfo *tmp = namespaces.last();
    namespacePLevel = tmp->pLevelOnEntering;
    namespaces.remove();
}

QCString nameQualifier()
{
    QListIterator<NamespaceInfo> iter( namespaces );
    NamespaceInfo *tmp;
    QCString qualifier = "";
    for( ; (tmp = iter.current()) ; ++iter ) {
	if ( !tmp->name.isNull() ) {  // If not unnamed namespace
	    qualifier += tmp->name;
	    qualifier += "::";
	}
    }
    return qualifier;
}

int openNameSpaceForMetaObject( FILE *out )
{
    int levels = 0;
    QListIterator<NamespaceInfo> iter( namespaces );
    NamespaceInfo *tmp;
    QCString indent = "";
    for( ; (tmp = iter.current()) ; ++iter ) {
	if ( !tmp->name.isNull() ) {  // If not unnamed namespace
	    fprintf( out, "%snamespace %s {\n", (const char *)indent,
		     (const char *) tmp->name );
	    indent += "    ";
	    levels++;
	}
    }
    QCString nm = className;
    int pos;
    while( (pos = nm.find( "::" )) != -1 ) {
	QCString spaceName = nm.left( pos );
	nm = nm.right( nm.length() - pos - 2 );
	if ( !spaceName.isEmpty() ) {
	    fprintf( out, "%snamespace %s {\n", (const char *)indent,
		     (const char *) spaceName );
	    indent += "    ";
	    levels++;
	}
    }
    return levels;
}

void closeNameSpaceForMetaObject( FILE *out, int levels )
{
    int i;
    for( i = 0 ; i < levels ; i++ )
	    fprintf( out, "}" );
    if ( levels )
	fprintf( out, "\n" );
	
}

void selectOutsideClassState()
{
    if ( namespaces.count() == 0 )
	BEGIN OUTSIDE;
    else
	BEGIN IN_NAMESPACE;
}

void registerClassInNamespace()
{
    if ( namespaces.count() == 0 )
	return;
    namespaces.last()->definedClasses.insert((const char *)className,(char*)1);
}

//
// Remove white space from SIGNAL and SLOT names.
// This function has been copied from qobject.cpp.
//

inline bool isIdentChar( char x )
{						// Avoid bug in isalnum
    return x == '_' || (x >= '0' && x <= '9') ||
	 (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

inline bool isSpace( char x )
{
#if defined(_CC_BOR_)
  /*
    Borland C++ 4.5 has a weird isspace() bug.
    isspace() usually works, but not here.
    This implementation is sufficient for our internal use: rmWS()
  */
    return (uchar)x <= 32;
#else
    return isspace( x );
#endif
}

static QCString rmWS( const char *src )
{
    QCString result( strlen(src)+1 );
    char *d = result.data();
    char *s = (char *)src;
    char last = 0;
    while( *s && isSpace(*s) )			// skip leading space
	s++;
    while ( *s ) {
	while ( *s && !isSpace(*s) )
	    last = *d++ = *s++;
	while ( *s && isSpace(*s) )
	    s++;
	if ( *s && isIdentChar(*s) && isIdentChar(last) )
	    last = *d++ = ' ';
    }
    result.truncate( (int)(d - result.data()) );
    return result;
}


void initExpression()
{
    tmpExpression = "";
}

void addExpressionString( char *s )
{
    tmpExpression += s;
}

void addExpressionChar( char c )
{
    tmpExpression += c;
}

void yyerror( char *msg )			// print yacc error message
{
    mocError = TRUE;
    fprintf( stderr, "%s:%d: Error: %s\n", fileName.data(), lineNo, msg );
}

void moc_err( char *s )
{
    yyerror( s );
    if ( errorControl )
	exit( -1 );
}

void moc_err( char *s1, char *s2 )
{
    static char tmp[1024];
    sprintf( tmp, s1, s2 );
    yyerror( tmp );
    if ( errorControl )
	exit( -1 );
}

void moc_warn( char *msg )
{
    if ( displayWarnings )
	fprintf( stderr, "%s:%d: Warning: %s\n", fileName.data(), lineNo, msg);
}

void func_warn( char *msg )
{
    moc_warn( msg );
    skipFunc = TRUE;
}

void operatorError()
{
    moc_warn("Operator functions cannot be signals or slots.");
    skipFunc = TRUE;
}

#ifndef yywrap
int yywrap()					// more files?
{
    return 1;					// end of file
}
#endif

char *stradd( const char *s1, const char *s2 )	// adds two strings
{
    char *n = new char[strlen(s1)+strlen(s2)+1];
    CHECK_PTR( n );
    strcpy( n, s1 );
    strcat( n, s2 );
    return n;
}

char *stradd( const char *s1, const char *s2, const char *s3 )// adds 3 strings
{
    char *n = new char[strlen(s1)+strlen(s2)+strlen(s3)+1];
    CHECK_PTR( n );
    strcpy( n, s1 );
    strcat( n, s2 );
    strcat( n, s3 );
    return n;
}

char *stradd( const char *s1, const char *s2,
	      const char *s3, const char *s4 )// adds 4 strings
{
    char *n = new char[strlen(s1)+strlen(s2)+strlen(s3)+strlen(s4)+1];
    CHECK_PTR( n );
    strcpy( n, s1 );
    strcat( n, s2 );
    strcat( n, s3 );
    strcat( n, s4 );
    return n;
}


char *straddSpc( const char *s1, const char *s2 )
{
    char *n = new char[strlen(s1)+strlen(s2)+2];
    CHECK_PTR( n );
    strcpy( n, s1 );
    strcat( n, " " );
    strcat( n, s2 );
    return n;
}

char *straddSpc( const char *s1, const char *s2, const char *s3 )
{
    char *n = new char[strlen(s1)+strlen(s2)+strlen(s3)+3];
    CHECK_PTR( n );
    strcpy( n, s1 );
    strcat( n, " " );
    strcat( n, s2 );
    strcat( n, " " );
    strcat( n, s3 );
    return n;
}

char *straddSpc( const char *s1, const char *s2,
	      const char *s3, const char *s4 )
{
    char *n = new char[strlen(s1)+strlen(s2)+strlen(s3)+strlen(s4)+4];
    CHECK_PTR( n );
    strcpy( n, s1 );
    strcat( n, " " );
    strcat( n, s2 );
    strcat( n, " " );
    strcat( n, s3 );
    strcat( n, " " );
    strcat( n, s4 );
    return n;
}

// Generate C++ code for building member function table

QCString pureClassName()
{
    QCString result;
    int pos = className.findRev( "::");
    if ( pos != -1 )
        result = className.right( className.length() - pos - 2 );
    else
	result = className;
    return result;
}

QCString qualifiedClassName()
{
    QCString tmp = nameQualifier();
    tmp += className;
    return tmp;
}

QCString qualifiedSuperclassName()
{
    if ( namespaces.count() == 0 )
	return superclassName;
    if ( namespaces.last()->definedClasses.find((const char *)superclassName)){
	QCString tmp = nameQualifier();
	tmp += superclassName;
	return tmp;
    } else {
	return superclassName;
    }
}

const int Slot_Num   = 1;
const int Signal_Num = 2;

void generateFuncs( FuncList *list, char *functype, int num )
{
    Function *f;
    for ( f=list->first(); f; f=list->next() ) {
	QCString typstr = "";
	int count = 0;
	Argument *a = f->args->first();
	while ( a ) {
	    if ( !a->leftType.isEmpty() || ! a->rightType.isEmpty() ) {
		if ( count++ )
		    typstr += ",";
		typstr += a->leftType;
		typstr += a->rightType;
	    }
	    a = f->args->next();
	}
	fprintf( out, "    typedef %s(%s::*m%d_t%d)(%s)%s;\n",
		 (const char*)f->type, (const char*)qualifiedClassName(),
		 num, list->at(),
		 (const char*)typstr,  (const char*)f->qualifier );
	f->type = f->name.copy();
	f->type += "(";
	f->type += typstr;
	f->type += ")";
    }
    for ( f=list->first(); f; f=list->next() )
	fprintf( out, "    m%d_t%d v%d_%d = Q_AMPERSAND %s::%s;\n",
		 num, list->at(), num, list->at(),
		 (const char*)qualifiedClassName(), (const char*)f->name);
    if ( list->count() )
	fprintf(out,"    QMetaData *%s_tbl = QMetaObject::new_metadata(%d);\n",
		functype, list->count() );
    for ( f=list->first(); f; f=list->next() )
	fprintf( out, "    %s_tbl[%d].name = \"%s\";\n",
		 functype, list->at(), (const char*)f->type );
    for ( f=list->first(); f; f=list->next() )
	fprintf( out, "    %s_tbl[%d].ptr = *((QMember*)&v%d_%d);\n",
		 functype, list->at(), num, list->at() );
}

void generateClass()		      // generate C++ source code for a class
{
    static int gen_count = 0;
    char *hdr1 = "/****************************************************************************\n"
		 "** %s meta object code from reading C++ file '%s'\n**\n";
    char *hdr2 = "** Created: %s\n"
		 "**      by: The Qt Meta Object Compiler ($Revision: 2.53 $)\n**\n";
    char *hdr3 = "** WARNING! All changes made in this file will be lost!\n";
    char *hdr4 = "*****************************************************************************/\n\n";
    int   i;

    if ( skipClass )				// don't generate for class
	return;
    if ( !Q_OBJECTdetected ) {
	if ( signals.count() == 0 && slots.count() == 0 )
	    return;
	generatedCode = TRUE;
	if ( displayWarnings )
	    moc_err("The declaration of the class \"%s\" contains slots "
		    "and/or signals\n\t but no Q_OBJECT macro!", className.data());
    } else {
	if ( superclassName.isEmpty() )
	    moc_err("The declaration of the class \"%s\" contains the\n"
		    "\tQ_OBJECT macro but does not inherit from any class!\n"
		    "\tInherit from QObject or one of its descendants"
		    " or remove Q_OBJECT. ", className.data() );
    }
    if ( templateClass ) {			// don't generate for class
	moc_err( "Sorry, Qt does not support templates that contain\n"
		 "signals, slots or Q_OBJECT. This will be supported soon." );
	return;
    }
    generatedCode = TRUE;
    if ( gen_count++ == 0 ) {			// first class to be generated
	QDateTime dt = QDateTime::currentDateTime();
	QCString dstr = dt.toString().ascii();
	QCString fn = fileName;
	i = fileName.length()-1;
	while ( i>0 && fileName[i-1] != '/' && fileName[i-1] != '\\' )
	    i--;				// skip path
	if ( i >= 0 )
	    fn = &fileName[i];
	fprintf( out, hdr1, (const char*)qualifiedClassName(),(const char*)fn);
	fprintf( out, hdr2, (const char*)dstr );
	fprintf( out, hdr3 );
	fprintf( out, hdr4 );
	fprintf( out, "#define Q_MOC_%s\n", className.data() );
	fprintf( out, "#if !defined(Q_MOC_OUTPUT_REVISION)\n" );
	fprintf( out, "#define Q_MOC_OUTPUT_REVISION %d\n", formatRevision );
	fprintf( out, "#elif Q_MOC_OUTPUT_REVISION != %d\n", formatRevision );
	fprintf( out, "#error \"Moc format conflict - "
		 "please regenerate all moc files\"\n" );
	fprintf( out, "#endif\n\n" );
	if ( !noInclude )
	    fprintf( out, "#include \"%s\"\n", (const char*)includeFile );
	fprintf( out, "#include <%sqmetaobject.h>\n", (const char*)qtPath );
	fprintf( out, "#include <%sqapplication.h>\n", (const char*)qtPath );
	fprintf( out, "\n" );
	fprintf( out, "#if defined(Q_SPARCWORKS_FUNCP_BUG)\n" );
	fprintf( out, "#define Q_AMPERSAND\n" );
	fprintf( out, "#else\n" );
	fprintf( out, "#define Q_AMPERSAND &\n" );
	fprintf( out, "#endif\n" );
	fprintf( out, "\n\n" );
    } else {
	fprintf( out, "\n\n" );
    }

//
// Generate virtual function className()
//
    fprintf( out, "const char *%s::className() const\n{\n    ",
	     (const char*)qualifiedClassName() );
    fprintf( out, "return \"%s\";\n}\n\n", (const char*)qualifiedClassName() );

//
// Generate static metaObj variable
//
    fprintf( out, "QMetaObject *%s::metaObj = 0;\n\n", (const char*)qualifiedClassName());

//
// Generate static meta-object constructor-object (we don't rely on
// it, except for QBuilder).
//
    fprintf( out, "\n#if QT_VERSION >= 199\n" );
    int levels = openNameSpaceForMetaObject( out );
    fprintf( out, "static QMetaObjectInit init_%s(&%s::staticMetaObject);\n\n",
	(const char*)pureClassName(), (const char*)qualifiedClassName() );
    closeNameSpaceForMetaObject( out, levels );
    fprintf( out, "#endif\n\n" );

//
// Generate initMetaObject member function
//
    fprintf( out, "void %s::initMetaObject()\n{\n", (const char*)qualifiedClassName() );
    fprintf( out, "    if ( metaObj )\n\treturn;\n" );
    fprintf( out, "    if ( strcmp(%s::className(), \"%s\") != 0 )\n"
	          "\tbadSuperclassWarning(\"%s\",\"%s\");\n",
             (const char*)qualifiedSuperclassName(), (const char*)qualifiedSuperclassName(),
             (const char*)qualifiedClassName(), (const char*)qualifiedSuperclassName() );
    fprintf( out, "\n#if QT_VERSION >= 199\n" );
    fprintf( out, "    staticMetaObject();\n");
    fprintf( out, "}\n\n");

//
// Generate tr member function
//
    fprintf( out, "QString %s::tr(const char* s)\n{\n", (const char*)qualifiedClassName() );
    fprintf( out, "    return ((QNonBaseApplication*)qApp)->translate(\"%s\",s);\n}\n\n", (const char*)qualifiedClassName() );

//
// Generate staticMetaObject member function
//
    fprintf( out, "void %s::staticMetaObject()\n{\n", (const char*)qualifiedClassName() );
    fprintf( out, "    if ( metaObj )\n\treturn;\n" );
    fprintf( out, "    %s::staticMetaObject();\n", (const char*)qualifiedSuperclassName() );
    fprintf( out, "#else\n\n" );
    fprintf( out, "    %s::initMetaObject();\n", (const char*)qualifiedSuperclassName() );
    fprintf( out, "#endif\n\n" );
//
// Build slots array in staticMetaObject()
//
    generateFuncs( &slots, "slot", Slot_Num );

//
// Build signals array in staticMetaObject()
//
    generateFuncs( &signals, "signal", Signal_Num );

//
// Finally code to create and return meta object
//
    fprintf( out, "    metaObj = QMetaObject::new_metaobject(\n"
		  "\t\"%s\", \"%s\",\n",
	     (const char*)qualifiedClassName(), (const char*)qualifiedSuperclassName() );
    if ( slots.count() )
	fprintf( out, "\tslot_tbl, %d,\n", slots.count() );
    else
	fprintf( out, "\t0, 0,\n" );
    if ( signals.count() )
	fprintf( out, "\tsignal_tbl, %d );\n", signals.count());
    else
	fprintf( out, "\t0, 0 );\n" );

    fprintf( out, "}\n" );

//
// End of function initMetaObject()
//

//
// Generate internal signal functions
//
    Function *f;
    f = signals.first();			// make internal signal methods
    static bool included_list_stuff = FALSE;
    while ( f ) {
	QCString typstr = "";			// type string
	QCString valstr = "";			// value string
	QCString argstr = "";			// argument string (type+value)
	char	buf[12];
	Argument *a = f->args->first();
	QCString typvec[32], valvec[32], argvec[32];
	typvec[0] = "";
	valvec[0] = "";
	argvec[0] = "";

	i = 0;
	while ( a ) {				// argument list
	    if ( !a->leftType.isEmpty() || !a->rightType.isEmpty() ) {
		if ( i ) {
		    typstr += ",";
		    valstr += ", ";
		    argstr += ", ";
		}
		typstr += a->leftType;
		typstr += a->rightType;
		argstr += a->leftType;
		argstr += " ";
		sprintf( buf, "t%d", i );
		valstr += buf;
		argstr += buf;
		argstr += a->rightType;
		++i;
		typvec[i] = typstr.copy();
		valvec[i] = valstr.copy();
		argvec[i] = argstr.copy();
	    }
	    a = f->args->next();
	}

	const char *predef_call_func;
	if ( typstr == "bool" ) {
	    predef_call_func = "activate_signal_bool";
	} else if ( typstr == "QString" ) {
	    predef_call_func = "activate_signal_string";
	} else if ( typstr == "const QString&" ) {
	    predef_call_func = "activate_signal_strref";
	} else if ( typstr.isEmpty() || typstr == "short" ||
		    typstr == "int" ||  typstr == "long" ||
		    typstr == "char*" || typstr == "const char*" ) {
	    predef_call_func = "activate_signal";
	} else {
	    predef_call_func = 0;
	}
	if ( !predef_call_func && !included_list_stuff ) {
	    // yes we need it, because otherwise QT_VERSION may not be defined
	    fprintf( out, "\n#include <%sqobjectdefs.h>\n", (const char*)qtPath );
	    fprintf( out, "#include <%sqsignalslotimp.h>\n", (const char*)qtPath );
	    included_list_stuff = TRUE;
	}

	fprintf( out, "\n/" /* c++ */ "/ SIGNAL %s\n", (const char*)f->name );
	fprintf( out, "void %s::%s(", (const char*)qualifiedClassName(),
		 (const char*)f->name );

	if ( argstr.isEmpty() )
	    fprintf( out, ")\n{\n" );
	else
	    fprintf( out, " %s )\n{\n", (const char*)argstr );

	if ( predef_call_func ) {
	    fprintf( out, "    %s( \"%s(%s)\"", predef_call_func,
		     (const char*)f->name, (const char*)typstr );
	    if ( !valstr.isEmpty() )
		fprintf( out, ", %s", (const char*)valstr );
	    fprintf( out, " );\n}\n" );
	    f = signals.next();
	    continue;
	}


	fprintf( out,"    // No builtin function for signal parameter type %s\n",
		 (const char*)typstr );
	int nargs = f->args->count();
	fprintf( out, "    QConnectionList *clist = receivers(\"%s(%s)\");\n",
		 (const char*)f->name, (const char*)typstr );
	fprintf( out, "    if ( !clist || signalsBlocked() )\n\treturn;\n" );
	if ( nargs ) {
	    for ( i=0; i<=nargs; i++ ) {
		fprintf( out, "    typedef void (QObject::*RT%d)(%s);\n",
			 i, (const char*)typvec[i] );
		fprintf( out, "    typedef RT%d *PRT%d;\n", i, i );
	    }
	} else {
	    fprintf( out, "    typedef void (QObject::*RT)(%s);\n",
		     (const char*)typstr);
	    fprintf( out, "    typedef RT *PRT;\n" );	
	}
	if ( nargs ) {
	    for ( i=0; i<=nargs; i++ )
		fprintf( out, "    RT%d r%d;\n", i, i );
	} else {
	    fprintf( out, "    RT r;\n" );
	}
	fprintf( out, "    QConnectionListIt it(*clist);\n" );
	fprintf( out, "    QConnection   *c;\n" );
	fprintf( out, "    QSenderObject *object;\n" );
	fprintf( out, "    while ( (c=it.current()) ) {\n" );
	fprintf( out, "\t++it;\n" );
	fprintf( out, "\tobject = (QSenderObject*)c->object();\n" );
	fprintf( out, "\tobject->setSender( this );\n" );
	if ( nargs ) {
	    fprintf( out, "\tswitch ( c->numArgs() ) {\n" );
	    for ( i=0; i<=nargs; i++ ) {
		fprintf( out, "\t    case %d:\n", i );
		fprintf( out, "\t\tr%d = *((PRT%d)(c->member()));\n", i, i );
		fprintf( out, "\t\t(object->*r%d)(%s);\n",
			 i, (const char*)valvec[i] );
		fprintf( out, "\t\tbreak;\n" );
	    }
	    fprintf( out, "\t}\n" );
	} else {
	    fprintf( out, "\tr = *((PRT)(c->member()));\n" );
	    fprintf( out, "\t(object->*r)(%s);\n", (const char*)valstr );
	}
	fprintf( out, "    }\n}\n" );
	f = signals.next();
    }

}


ArgList *addArg( Argument *a )			// add argument to list
{
    tmpArgList->append( a );
    return tmpArgList;
}

void addMember( char m )
{
    if ( skipFunc ) {
	tmpArgList  = new ArgList;   // ugly but works!
	CHECK_PTR( tmpArgList );
	tmpFunc	    = new Function;
	CHECK_PTR( tmpFunc );
	skipFunc    = FALSE;
	return;
    }
    if ( m == 's' && tmpFunc->type != "void" ) {
	moc_err( "Signals must have \"void\" as their return type" );
	return;
    }
    tmpFunc->accessPerm = tmpAccessPerm;
    tmpFunc->args	= tmpArgList;
    tmpFunc->lineNo	= lineNo;
    tmpArgList		= new ArgList;
    CHECK_PTR( tmpArgList );
    switch( m ) {
	case 's': signals.append( tmpFunc ); break;
	case 't': slots.  append( tmpFunc ); break;
    }
    skipFunc = FALSE;
    tmpFunc  = new Function;
    CHECK_PTR( tmpFunc );
}
#line 1855 "y.tab.c"
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 10:
#line 246 "moc.y"
{ enterNameSpace(yyvsp[0].string); }
break;
case 11:
#line 247 "moc.y"
{ BEGIN IN_NAMESPACE; }
break;
case 12:
#line 249 "moc.y"
{ leaveNameSpace();
			                       selectOutsideClassState();
                                             }
break;
case 13:
#line 254 "moc.y"
{ enterNameSpace(); }
break;
case 14:
#line 255 "moc.y"
{ BEGIN IN_NAMESPACE; }
break;
case 15:
#line 257 "moc.y"
{ leaveNameSpace();
  			                       selectOutsideClassState();
			                     }
break;
case 17:
#line 266 "moc.y"
{ selectOutsideClassState(); }
break;
case 18:
#line 270 "moc.y"
{ selectOutsideClassState(); }
break;
case 19:
#line 273 "moc.y"
{ selectOutsideClassState(); }
break;
case 20:
#line 274 "moc.y"
{ selectOutsideClassState(); }
break;
case 21:
#line 277 "moc.y"
{ initClass(); }
break;
case 22:
#line 278 "moc.y"
{ generateClass();
			                        registerClassInNamespace();
						selectOutsideClassState(); }
break;
case 23:
#line 286 "moc.y"
{ yyval.string = yyvsp[0].string; }
break;
case 24:
#line 287 "moc.y"
{ yyval.string = yyvsp[0].string; }
break;
case 25:
#line 291 "moc.y"
{ yyval.string = stradd( yyvsp[-3].string, "<",
				     tmpExpression =
				     tmpExpression.stripWhiteSpace(), ">" ); }
break;
case 26:
#line 302 "moc.y"
{ initExpression();
						    templLevel = 1;
						    BEGIN IN_TEMPL_ARGS; }
break;
case 27:
#line 315 "moc.y"
{ initExpression();
						    BEGIN IN_EXPR; }
break;
case 28:
#line 321 "moc.y"
{ yyval.string = ""; }
break;
case 29:
#line 322 "moc.y"
{ yyval.string = yyvsp[0].string; }
break;
case 30:
#line 323 "moc.y"
{ yyval.string = ""; }
break;
case 31:
#line 324 "moc.y"
{ skipFunc = TRUE; yyval.string = ""; }
break;
case 32:
#line 325 "moc.y"
{ skipFunc = TRUE; yyval.string = ""; }
break;
case 33:
#line 329 "moc.y"
{ yyval.string = straddSpc(yyvsp[-2].string,yyvsp[-1].string,yyvsp[0].string); }
break;
case 34:
#line 332 "moc.y"
{ yyval.string = ""; }
break;
case 35:
#line 333 "moc.y"
{ yyval.string = yyvsp[0].string; }
break;
case 36:
#line 336 "moc.y"
{ yyval.string = yyvsp[0].string; }
break;
case 37:
#line 337 "moc.y"
{ yyval.string = straddSpc(yyvsp[-1].string,yyvsp[0].string); }
break;
case 40:
#line 342 "moc.y"
{ skipFunc = TRUE; }
break;
case 44:
#line 350 "moc.y"
{ yyval.string = "const"; }
break;
case 45:
#line 351 "moc.y"
{ yyval.string = "volatile"; }
break;
case 46:
#line 354 "moc.y"
{ yyval.string = yyvsp[0].string; }
break;
case 47:
#line 355 "moc.y"
{ yyval.string = yyvsp[0].string; }
break;
case 48:
#line 356 "moc.y"
{ yyval.string = yyvsp[0].string; }
break;
case 49:
#line 360 "moc.y"
{ yyval.string = straddSpc(yyvsp[-1].string,yyvsp[0].string); }
break;
case 50:
#line 361 "moc.y"
{ yyval.string = yyvsp[0].string; }
break;
case 51:
#line 363 "moc.y"
{ yyval.string = "char"; }
break;
case 52:
#line 364 "moc.y"
{ yyval.string = "short"; }
break;
case 53:
#line 365 "moc.y"
{ yyval.string = "int"; }
break;
case 54:
#line 366 "moc.y"
{ yyval.string = "long"; }
break;
case 55:
#line 367 "moc.y"
{ yyval.string = "signed"; }
break;
case 56:
#line 368 "moc.y"
{ yyval.string = "unsigned"; }
break;
case 57:
#line 369 "moc.y"
{ yyval.string = "float"; }
break;
case 58:
#line 370 "moc.y"
{ yyval.string = "double"; }
break;
case 59:
#line 371 "moc.y"
{ yyval.string = "void"; }
break;
case 60:
#line 375 "moc.y"
{ yyval.string = stradd( "template<",
				     tmpExpression =
				     tmpExpression.stripWhiteSpace(), ">" ); }
break;
case 62:
#line 381 "moc.y"
{ templateClass = TRUE; }
break;
case 63:
#line 385 "moc.y"
{ yyval.string = "class"; }
break;
case 64:
#line 386 "moc.y"
{ yyval.string = "struct"; }
break;
case 65:
#line 389 "moc.y"
{ yyval.string = yyvsp[0].string; }
break;
case 66:
#line 391 "moc.y"
{ yyval.string = stradd( "::", yyvsp[0].string ); }
break;
case 67:
#line 395 "moc.y"
{ yyval.string = stradd( yyvsp[-2].string, "::", yyvsp[0].string );}
break;
case 68:
#line 396 "moc.y"
{ yyval.string = yyvsp[0].string; }
break;
case 69:
#line 400 "moc.y"
{ yyval.string = straddSpc(yyvsp[-1].string,yyvsp[0].string); }
break;
case 70:
#line 401 "moc.y"
{ yyval.string = stradd("enum ",yyvsp[0].string); }
break;
case 71:
#line 402 "moc.y"
{ yyval.string = stradd("union ",yyvsp[0].string); }
break;
case 72:
#line 407 "moc.y"
{ yyval.arg_list = yyvsp[-1].arg_list;}
break;
case 73:
#line 408 "moc.y"
{ yyval.arg_list = yyvsp[-2].arg_list;
				       moc_warn("Ellipsis not supported"
					       " in signals and slots.\n"
					       "Ellipsis argument ignored."); }
break;
case 74:
#line 414 "moc.y"
{ yyval.arg_list = tmpArgList; }
break;
case 75:
#line 415 "moc.y"
{ yyval.arg_list = yyvsp[0].arg_list; }
break;
case 77:
#line 419 "moc.y"
{ moc_warn("Ellipsis not supported"
					       " in signals and slots.\n"
					       "Ellipsis argument ignored."); }
break;
case 78:
#line 427 "moc.y"
{ yyval.arg_list = addArg(yyvsp[0].arg); }
break;
case 79:
#line 428 "moc.y"
{ yyval.arg_list = addArg(yyvsp[0].arg); }
break;
case 80:
#line 431 "moc.y"
{ yyval.arg = new Argument(straddSpc(yyvsp[-1].string,yyvsp[0].string),"");
				  CHECK_PTR(yyval.arg); }
break;
case 81:
#line 434 "moc.y"
{ expLevel = 1; }
break;
case 82:
#line 436 "moc.y"
{ yyval.arg = new Argument(straddSpc(yyvsp[-4].string,yyvsp[-3].string),"");
				  CHECK_PTR(yyval.arg); }
break;
case 83:
#line 440 "moc.y"
{ yyval.arg = new Argument(straddSpc(yyvsp[-3].string,yyvsp[-2].string),yyvsp[0].string);
				  CHECK_PTR(yyval.arg); }
break;
case 84:
#line 444 "moc.y"
{ expLevel = 1; }
break;
case 85:
#line 446 "moc.y"
{ yyval.arg = new Argument(straddSpc(yyvsp[-6].string,yyvsp[-5].string),yyvsp[-3].string);
				  CHECK_PTR(yyval.arg); }
break;
case 86:
#line 451 "moc.y"
{ yyval.string = ""; }
break;
case 87:
#line 452 "moc.y"
{ yyval.string = yyvsp[0].string; }
break;
case 88:
#line 456 "moc.y"
{ yyval.string = straddSpc(yyvsp[-1].string,yyvsp[0].string); }
break;
case 89:
#line 457 "moc.y"
{ expLevel = 1; }
break;
case 90:
#line 459 "moc.y"
{ yyval.string = stradd( "[",
				     tmpExpression =
				     tmpExpression.stripWhiteSpace(), "]" ); }
break;
case 91:
#line 462 "moc.y"
{ expLevel = 1; }
break;
case 92:
#line 464 "moc.y"
{ yyval.string = stradd( yyvsp[-4].string,"[",
				     tmpExpression =
				     tmpExpression.stripWhiteSpace(),"]" ); }
break;
case 93:
#line 467 "moc.y"
{ yyval.string = yyvsp[0].string; }
break;
case 94:
#line 468 "moc.y"
{ yyval.string = yyvsp[-1].string; }
break;
case 95:
#line 471 "moc.y"
{ yyval.string = ""; }
break;
case 96:
#line 473 "moc.y"
{ yyval.string = straddSpc(yyvsp[-1].string,yyvsp[0].string);}
break;
case 97:
#line 474 "moc.y"
{ expLevel = 1; }
break;
case 98:
#line 476 "moc.y"
{ yyval.string = stradd( yyvsp[-4].string,"[",
				     tmpExpression =
				     tmpExpression.stripWhiteSpace(),"]" ); }
break;
case 99:
#line 479 "moc.y"
{ yyval.string = yyvsp[-1].string; }
break;
case 101:
#line 490 "moc.y"
{ tmpFunc->args	     = yyvsp[-3].arg_list;
						  tmpFunc->qualifier = yyvsp[-1].string; }
break;
case 103:
#line 496 "moc.y"
{ func_warn("Variable as signal or slot."); }
break;
case 104:
#line 497 "moc.y"
{ expLevel=0; }
break;
case 105:
#line 499 "moc.y"
{ skipFunc = TRUE; }
break;
case 106:
#line 500 "moc.y"
{ expLevel=0; }
break;
case 107:
#line 502 "moc.y"
{ skipFunc = TRUE; }
break;
case 108:
#line 506 "moc.y"
{ expLevel = 1; }
break;
case 110:
#line 508 "moc.y"
{ expLevel = 1; }
break;
case 112:
#line 513 "moc.y"
{ yyval.string = ""; }
break;
case 113:
#line 514 "moc.y"
{ yyval.string = yyvsp[0].string; }
break;
case 114:
#line 517 "moc.y"
{ yyval.string = yyvsp[0].string; }
break;
case 115:
#line 518 "moc.y"
{ yyval.string = straddSpc(yyvsp[-1].string,yyvsp[0].string);}
break;
case 116:
#line 521 "moc.y"
{ yyval.string = straddSpc("*",yyvsp[0].string);}
break;
case 117:
#line 522 "moc.y"
{ yyval.string = stradd("&",yyvsp[0].string);}
break;
case 118:
#line 529 "moc.y"
{ yyval.string = ""; }
break;
case 119:
#line 530 "moc.y"
{ yyval.string = yyvsp[0].string; }
break;
case 120:
#line 533 "moc.y"
{ yyval.string = yyvsp[0].string; }
break;
case 121:
#line 535 "moc.y"
{ yyval.string = straddSpc(yyvsp[-1].string,yyvsp[0].string); }
break;
case 122:
#line 538 "moc.y"
{ yyval.string = "const"; }
break;
case 123:
#line 539 "moc.y"
{ yyval.string = "volatile"; }
break;
case 127:
#line 547 "moc.y"
{BEGIN IN_FCT; fctLevel = 1;}
break;
case 128:
#line 548 "moc.y"
{BEGIN QT_DEF; }
break;
case 129:
#line 555 "moc.y"
{ BEGIN IN_CLASS;
                                                  classPLevel = 1; }
break;
case 130:
#line 558 "moc.y"
{ BEGIN QT_DEF; }
break;
case 131:
#line 559 "moc.y"
{ BEGIN QT_DEF;	  /* -- " -- */
						  skipClass = TRUE; }
break;
case 132:
#line 563 "moc.y"
{ BEGIN QT_DEF; /* catch ';' */
						  skipClass = TRUE; }
break;
case 133:
#line 565 "moc.y"
{ skipClass = TRUE;
						  BEGIN GIMME_SEMICOLON; }
break;
case 139:
#line 578 "moc.y"
{ className = yyvsp[0].string; }
break;
case 140:
#line 581 "moc.y"
{ className = yyvsp[0].string; }
break;
case 141:
#line 585 "moc.y"
{ superclassName = yyvsp[0].string; }
break;
case 142:
#line 588 "moc.y"
{ yyval.string = 0; }
break;
case 143:
#line 589 "moc.y"
{ yyval.string = yyvsp[0].string; }
break;
case 148:
#line 601 "moc.y"
{ tmpAccessPerm = yyvsp[0].access; }
break;
case 149:
#line 602 "moc.y"
{ moc_err( "Missing access specifier"
						   " before \"slots:\"." ); }
break;
case 150:
#line 606 "moc.y"
{ BEGIN QT_DEF; }
break;
case 152:
#line 608 "moc.y"
{ BEGIN QT_DEF; }
break;
case 154:
#line 610 "moc.y"
{ if ( tmpAccessPerm )
				moc_warn("Q_OBJECT is not in the private"
					" section of the class.\n"
					"Q_OBJECT is a macro that resets"
					" access permission to \"private\".");
						  Q_OBJECTdetected = TRUE; }
break;
case 155:
#line 619 "moc.y"
{ moc_err( "Signals cannot "
						 "have access specifiers" ); }
break;
case 157:
#line 622 "moc.y"
{ if ( grammarDebug )
						  BEGIN QT_DEF;
					      else
						  BEGIN IN_CLASS;
					 }
break;
case 159:
#line 628 "moc.y"
{ BEGIN IN_CLASS;
					   if ( classPLevel != 1 )
					       moc_warn( "unexpected access"
							 "specifier" );
					 }
break;
case 164:
#line 644 "moc.y"
{ addMember('s'); }
break;
case 169:
#line 655 "moc.y"
{ addMember('t'); }
break;
case 172:
#line 662 "moc.y"
{ yyval.string=yyvsp[0].string; }
break;
case 175:
#line 670 "moc.y"
{ yyval.string = stradd( yyvsp[-3].string, "(", yyvsp[-1].string, ")" ); }
break;
case 176:
#line 672 "moc.y"
{ yyval.string = stradd( yyvsp[-3].string, "(", yyvsp[-1].string, ")" ); }
break;
case 177:
#line 675 "moc.y"
{yyval.string=yyvsp[0].string;}
break;
case 178:
#line 676 "moc.y"
{yyval.string=yyvsp[0].string;}
break;
case 179:
#line 677 "moc.y"
{yyval.string=yyvsp[0].string;}
break;
case 180:
#line 678 "moc.y"
{yyval.string=yyvsp[0].string;}
break;
case 181:
#line 679 "moc.y"
{yyval.string=yyvsp[0].string;}
break;
case 182:
#line 680 "moc.y"
{yyval.string=yyvsp[0].string;}
break;
case 183:
#line 681 "moc.y"
{yyval.string=yyvsp[0].string;}
break;
case 184:
#line 682 "moc.y"
{yyval.string=yyvsp[0].string;}
break;
case 185:
#line 683 "moc.y"
{yyval.string=yyvsp[0].string;}
break;
case 186:
#line 684 "moc.y"
{yyval.string=yyvsp[0].string;}
break;
case 187:
#line 687 "moc.y"
{ yyval.access=_PRIVATE; }
break;
case 188:
#line 688 "moc.y"
{ yyval.access=_PROTECTED; }
break;
case 189:
#line 689 "moc.y"
{ yyval.access=_PUBLIC; }
break;
case 233:
#line 741 "moc.y"
{ tmpFunc->type = yyvsp[-1].string;
						  tmpFunc->name = yyvsp[0].string; }
break;
case 234:
#line 744 "moc.y"
{ tmpFunc->type = "int";
						  tmpFunc->name = yyvsp[0].string;
				  if ( tmpFunc->name == className )
				      func_warn( "Constructors cannot be"
						 " signals or slots.");
						}
break;
case 235:
#line 751 "moc.y"
{
				       func_warn( "Destructors cannot be"
						  " signals or slots.");
						}
break;
case 236:
#line 757 "moc.y"
{
						    char *tmp =
							straddSpc(yyvsp[-4].string,yyvsp[-3].string,yyvsp[-2].string,yyvsp[-1].string);
						    tmpFunc->type = rmWS(tmp);
						    delete tmp;
						    tmpFunc->name = yyvsp[0].string; }
break;
case 237:
#line 764 "moc.y"
{ skipFunc = TRUE; }
break;
case 238:
#line 766 "moc.y"
{ tmpFunc->type =
						      straddSpc(yyvsp[-2].string,yyvsp[-1].string);
						  tmpFunc->name = yyvsp[0].string; }
break;
case 239:
#line 771 "moc.y"
{ tmpFunc->type =
						      straddSpc(yyvsp[-3].string,yyvsp[-2].string,yyvsp[-1].string);
						  tmpFunc->name = yyvsp[0].string; }
break;
case 240:
#line 775 "moc.y"
{ operatorError();    }
break;
case 241:
#line 777 "moc.y"
{ operatorError();    }
break;
case 242:
#line 780 "moc.y"
{ operatorError();    }
break;
case 243:
#line 782 "moc.y"
{ operatorError();    }
break;
case 244:
#line 785 "moc.y"
{ operatorError();    }
break;
case 246:
#line 790 "moc.y"
{ func_warn("Variable as signal or slot."); }
break;
case 247:
#line 793 "moc.y"
{ func_warn("Variable as signal or slot."); }
break;
case 248:
#line 795 "moc.y"
{ func_warn("Enum declaration as signal or"
					  " slot."); }
break;
case 249:
#line 798 "moc.y"
{ func_warn("Using declaration as signal or"
					    " slot."); }
break;
case 250:
#line 801 "moc.y"
{ func_warn("Using declaration as signal or"
					    " slot."); }
break;
case 251:
#line 804 "moc.y"
{ classPLevel++;
				  moc_err("Namespace declaration as signal or"
					  " slot."); }
break;
case 255:
#line 815 "moc.y"
{ expLevel = 0; }
break;
case 257:
#line 817 "moc.y"
{ expLevel = 0; }
break;
case 260:
#line 822 "moc.y"
{ expLevel = 0; }
break;
case 262:
#line 827 "moc.y"
{BEGIN IN_FCT; fctLevel=1;}
break;
case 263:
#line 828 "moc.y"
{BEGIN QT_DEF; }
break;
#line 2719 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
