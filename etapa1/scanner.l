%{
#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"	
#include "hash.h"

HASH_TABLE hashTable;
int LineNumber = 1;
int running = 1;

void initMe(void);

%}

%x COMM

%%

byte		{ return KW_BYTE; }
bool		{ return KW_BOOL; }
word		{ return KW_WORD; }
if		{ return KW_IF; }
then		{ return KW_THEN; }
else		{ return KW_ELSE; }
input		{ return KW_INPUT; }
output		{ return KW_OUTPUT; }
return		{ return KW_RETURN; }
loop		{ return KW_LOOP; }


true	{ hashInsert(&hashTable, LIT_TRUE, yytext);
	return LIT_TRUE;
}
false	{ hashInsert(&hashTable, LIT_FALSE, yytext);
	return LIT_FALSE;
} 

[a-zA-Z_][a-zA-Z0-9_]*	{   
	hashInsert(&hashTable, TK_IDENTIFIER, yytext); 
	return TK_IDENTIFIER; 
}

[0-9][0-9a-fA-F]*	{ hashInsert(&hashTable, LIT_INTEGER, yytext);
	return LIT_INTEGER; 
}

'.'	{ hashInsert(&hashTable, LIT_CHAR, yytext);
	return LIT_CHAR; 
}   

["][^"]*["]	{
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

int yywrap()
{
	running = 0;
	return 1;
}

