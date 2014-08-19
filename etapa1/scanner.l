%{
#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"	
#include "hash.h"

HASH_TABLE hashTable;
int LineNumber = 1;
int runningFlag = 1;

void initMe(void);
int getLineNumber(void);
int isRunning(void);
char* subString (const char* input, int offset, int len, char* dest);

%}

%x COMM

%%

"word"			{ return KW_WORD; }
"bool"			{ return KW_BOOL; }
"byte"			{ return KW_BYTE; }
"if"			{ return KW_IF; }
"then"			{ return KW_THEN; }
"else"			{ return KW_ELSE; }
"loop"			{ return KW_LOOP; }
"input"			{ return KW_INPUT; }
"output"		{ return KW_OUTPUT; }
"return"		{ return KW_RETURN; }

"TRUE"	{ 
	hashInsert(&hashTable, LIT_TRUE, yytext);
	return LIT_TRUE;
}
"FALSE"	{ 
	hashInsert(&hashTable, LIT_FALSE, yytext);
	return LIT_FALSE;
} 

[0-9][0-9A-Za-z_]*[A-Za-z_][0-9A-Za-z_]*	{ 
	hashInsert(&hashTable, TK_IDENTIFIER, yytext); 
	return TK_IDENTIFIER; 
}

[0-9][0-9]*	{ 
	hashInsert(&hashTable, LIT_INTEGER, yytext);
	return LIT_INTEGER; 
}

'.'	{
	if(strlen(yytext)==2) return TOKEN_ERROR;//caso char seja vazio
	char var[0];
	var[0] = yytext[1]; //para remover as aspas
	hashInsert(&hashTable, LIT_CHAR, var);
	return LIT_CHAR; 
}   

["][^"]*["]	{
	if(strlen(yytext)==2) return TOKEN_ERROR;
	hashInsert(&hashTable, LIT_STRING, yytext);
	return LIT_STRING;
}

","|";"|":"|"("|")"|"["|"]"|"{"|"}"|"+"|"-"|"*"|"/"|"<"|">"|"="|"!"|"&"|"$"	{ return yytext[0]; }

"<="		{ return OPERATOR_LE; }
">="		{ return OPERATOR_GE; }
"=="		{ return OPERATOR_EQ; }
"!="		{ return OPERATOR_NE; }
"&&"		{ return OPERATOR_AND; }
"||"		{ return OPERATOR_OR; }


\/\/.*		{ }
"/*"		BEGIN (COMM);

"\n"		{ ++LineNumber; }
[ \t\v\f]+	{ }

[a-zA-Z][a-zA-Z0-9_]*	{ return TOKEN_ERROR; }
.		{ return TOKEN_ERROR; }

<COMM>"*/"	BEGIN(INITIAL);
<COMM>.		{}
<COMM>"\n"	{ ++LineNumber; } 

%%

#include "main.c"

void initMe(void)
{
	hashInit(&hashTable);
}

int getLineNumber(void)
{
	return LineNumber;
}

int isRunning(void){
	return runningFlag;
}

int yywrap()
{
	runningFlag = 0;
	return 1;
}


