/* DEFINIÇÕES */
%{
#include <stdio.h>
#include <stdlib.h>
//#include "tokens.h"
//#include "hash.h"

//HASH_TABLE hashTable;
int LineNumber = 1;
int running = 1;

void initMe(void);

%}


/* CÓDIGO C */
%%

"byte"		{ printf ("KW_BYTE\n"); }
"bool"		{ printf ("KW_BOOL\n\n"); }
"word"		{ printf ("KW_WORD\n\n"); }
"if"		{ printf ("KW_IF\n\n"); }
"then"		{ printf ("KW_THEN\n\n"); }
"else"		{ printf ("KW_ELSE\n\n"); }
"input"		{ printf ("KW_INPUT\n\n"); }
"output"	{ printf ("KW_OUTPUT\n\n"); }
"return"	{ printf ("KW_RETURN\n\n"); }
"loop"		{ printf ("KW_LOOP\n\n"); }
"true"		{ printf ("LIT_TRUE\n\n"); }
"false"		{ printf ("LIT_FALSE\n\n"); }
[a-zA-Z_][a-zA-Z0-9_]*	{ printf ("TK_IDENTIFIER\n\n"); }
[0-9][0-9a-fA-F]*	{ printf ("LIT_INTEGER\n\n"); }
'.'			{ printf ("LIT_CHAR\n\n"); }
"<="		{ printf ("OPERATOR_LE\n\n"); }
">="		{ printf ("OPERATOR_GE\n\n"); }
"=="		{ printf ("OPERATOR_EQ\n\n"); }
"!="		{ printf ("OPERATOR_NE\n\n"); }
"&&"		{ printf ("OPERATOR_AND\n\n"); }
"||"		{ printf ("OPERATOR_OR\n\n"); }
["//"]+		{ printf ("LINE COMMENT\n\n"); }
"/*"		{ printf ("INIT COMMENT\n\n"); }
"\*"		{ printf ("END COMMENT\n\n"); }


"\n"		{ ++LineNumber; }
[ \t\v\f]+	{ }

.		{ printf ("TOKEN_ERROR\n\n"); }

%%

int main(int argc, char *argv[])
{	

	yylex();
	return 0;
}

void initMe(void)
{
	//hashInit(&hashTable);
}

int getLineNumber(void)
{
	return LineNumber;
}

int yywrap()
{
	running = 0;
	return 1;
}
