#include <stdio.h>
#include <stdlib.h>
#include "../include/astree.h"
#include "../include/hash.h"

extern int getLineNumber(void);
extern FILE *output;


ASTREE* AstreeCreate (int type, HASH_NODE* symbol, ASTREE* s0, ASTREE* s1, ASTREE* s2, ASTREE* s3)
{
	ASTREE *node = (ASTREE *) malloc(sizeof(ASTREE));
	node->lineNumber = getLineNumber();
  	node->type = type;
   	node->symbol = symbol;
	node->son[0] = s0;
	node->son[1] = s1;
	node->son[2] = s2;
	node->son[3] = s3;
	return node;
}

void astreePrintSingle (ASTREE *node,int level)
{
	if (!node)
		return;

	fprintf(stderr, "\n%d: ", node->lineNumber); 
	int i;
	for(i=0; i<level; i++)
		fprintf(stderr, "\t");

	switch (node->type)
	{	

		case ASTREE_SCALAR_ASS: 	fprintf(stderr, "ASTREE_SCALAR_ASS"); break;
		case ASTREE_SYMBOL: 		
						fprintf(stderr, "ASTREE_SYMBOL"); 
						fprintf(output, "%s",node->symbol->text); 
						break;

	// Tipos de dados
		case ASTREE_KW_WORD: 		
						fprintf(stderr, "ASTREE_KW_WORD");
						fprintf(output, "word");
						break;
		case ASTREE_KW_BYTE: 		
						fprintf(stderr, "ASTREE_KW_BYTE"); 
						fprintf(output, "byte");
						break;
		case ASTREE_KW_BOOL: 		
						fprintf(stderr, "ASTREE_KW_BOOL"); 
						fprintf(output, "bool");
						break;
	// Operaçoes
		case ASTREE_DIV: 		
						fprintf(stderr, "ASTREE_DIV");
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, "/");
						astreePrintSingle(node->son[1],level+1);
						break;
		case ASTREE_ADD:		
						fprintf(stderr, "ASTREE_ADD"); 
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, "+");
						astreePrintSingle(node->son[1],level+1);
						break;
		case ASTREE_MUL:		
						fprintf(stderr, "ASTREE_MUL"); 
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, "*");
						astreePrintSingle(node->son[1],level+1);
						break;
		case ASTREE_SUB: 		
						fprintf(stderr, "ASTREE_SUB"); 
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, "-");
						astreePrintSingle(node->son[1],level+1);
						break;
		case ASTREE_OP_AND: 		
						fprintf(stderr, "ASTREE_OP_AND"); 
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, "&&");
						astreePrintSingle(node->son[1],level+1);
						break;
		case ASTREE_OP_OR: 		
						fprintf(stderr, "ASTREE_OP_OR"); 
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, "||");
						astreePrintSingle(node->son[1],level+1);
						break;
		case ASTREE_OP_LE: 		
						fprintf(stderr, "ASTREE_OP_LE");
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, "<=");
						astreePrintSingle(node->son[1],level+1);
						break;
		case ASTREE_OP_GE: 		
						fprintf(stderr, "ASTREE_OP_GE"); 
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, ">=");
						astreePrintSingle(node->son[1],level+1);
						break;
		case ASTREE_OP_EQ: 		
						fprintf(stderr, "ASTREE_OP_EQ");
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, "==");
						astreePrintSingle(node->son[1],level+1);
						break;
		case ASTREE_OP_NE: 		
						fprintf(stderr, "ASTREE_OP_NE");
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, "!=");
						astreePrintSingle(node->son[1],level+1);
						break;
		case ASTREE_LESS: 		
						fprintf(stderr, "ASTREE_LESS");
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, "<");
						astreePrintSingle(node->son[1],level+1);
						break;
		case ASTREE_GREAT: 		
						fprintf(stderr, "ASTREE_GREAT"); 
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, ">");
						astreePrintSingle(node->son[1],level+1);
						break;
	// Literais
		case ASTREE_LIT_INTEGER: 	
						fprintf(stderr, "ASTREE_LIT_INTEGER"); 
						fprintf(output, "%s",node->symbol->text); 
						break;
		case ASTREE_LIT_TRUE:		
						fprintf(stderr, "ASTREE_LIT_TRUE");
						fprintf(output, "%s",node->symbol->text); 
						break;
		case ASTREE_LIT_FALSE: 		
						fprintf(stderr, "ASTREE_LIT_FALSE"); 
						fprintf(output, "%s",node->symbol->text); 
						break;
		case ASTREE_LIT_CHAR: 		
						fprintf(stderr, "ASTREE_LIT_CHAR"); 
						fprintf(output, "%s",node->symbol->text); 
						break;
		case ASTREE_LIT_STRING:		
						fprintf(stderr, "ASTREE_LIT_STRING"); 
						fprintf(output, "%s",node->symbol->text); 
						break;
	// Fluxo
		case ASTREE_IF: 		
						fprintf(stderr, "ASTREE_IF"); 
						fprintf(output, "\nif ("); 
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, ") then \n");
						astreePrintSingle(node->son[1],level+1);
						break;
		case ASTREE_IF_ELSE: 		
						fprintf(stderr, "ASTREE_IF_ELSE"); 
						fprintf(output, "\nif ("); 
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, ") then \n");
						astreePrintSingle(node->son[1],level+1);
						fprintf(output, "\nelse");
						astreePrintSingle(node->son[2],level+1);
						break;
		case ASTREE_LOOP: 		
						fprintf(stderr, "ASTREE_LOOP"); 
						fprintf(output, "\nloop ("); 
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, ")\n");
						astreePrintSingle(node->son[1],level+1);
						break;

		case ASTREE_DEC_GLOBAL: 	fprintf(stderr, "ASTREE_DEC_GLOBAL"); break;
		case ASTREE_DEC_LOCAL: 		fprintf(stderr, "ASTREE_DEC_LOCAL"); break;

	// Declaracoes
		case ASTREE_VAR: 		
						fprintf(stderr, "ASTREE_VAR");	
						fprintf(output, "\n"); 	
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, " %s",node->symbol->text); 	
						fprintf(output, ":"); 	
						astreePrintSingle(node->son[1],level+1);	
						fprintf(output, ";"); 	
						break;
		case ASTREE_VECTOR: 		
						fprintf(stderr, "ASTREE_VECTOR");
						fprintf(output, "\n"); 	
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, " %s",node->symbol->text); 	
						fprintf(output, "["); 	
						astreePrintSingle(node->son[1],level+1);	
						fprintf(output, "]"); 	
						if (node->son[2])
							{	
							fprintf(output, ":"); 	
							astreePrintSingle(node->son[2],level+1); 
							}
						fprintf(output, ";"); 	
						break;
		case ASTREE_PONT: 		
						fprintf(stderr, "ASTREE_PONT"); 
						fprintf(output, "\n"); 	
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, " $"); 	
						fprintf(output, "%s",node->symbol->text); 
						if (node->son[1])
							{
							fprintf(output, ":");
							astreePrintSingle(node->son[1],level+1);	
							}
						fprintf(output, ";"); 	
						break;


		case ASTREE_LIST_VAR: 		
						fprintf(stderr, "ASTREE_LIST_VAR"); 
						astreePrintSingle(node->son[0],level);
						astreePrintSingle(node->son[1],level);
						//fprintf(output, ";");
						break;

		case ASTREE_LIST_VEC: 		fprintf(stderr, "ASTREE_LIST_VEC"); break;
		case ASTREE_LIST_FUNC: 		fprintf(stderr, "ASTREE_LIST_FUNC"); break;


		case ASTREE_COMAND: 		
						fprintf(stderr, "ASTREE_COMAND"); 
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, ";");
						break;
		case ASTREE_COMANDLIST: 	
						fprintf(stderr, "ASTREE_COMANDLIST"); 
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, ";");
						astreePrintSingle(node->son[1],level+1);
						break;



		case ASTREE_COMANDBLK:		
						fprintf(stderr, "ASTREE_COMANDBLK"); 
						fprintf(output, "\n{"); 
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, "}\n"); 
						break;



	// Comands
		case ASTREE_EQUAL: 		
						fprintf(stderr, "ASTREE_EQUAL"); 	
						fprintf(output, " %s",node->symbol->text);
						fprintf(output, "=");  
						astreePrintSingle(node->son[0],level+1);	
						break;
		case ASTREE_EQUAL_VEC: 		
						fprintf(stderr, "ASTREE_EQUAL_VEC"); 	
						fprintf(output, " %s",node->symbol->text);
						fprintf(output, "[");  
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, "]");  
						fprintf(output, "=");  
						astreePrintSingle(node->son[1],level+1);
						break;

    // ARRUMEI
		case ASTREE_OUTPUT:		
						fprintf(stderr, "ASTREE_OUTPUT");
						fprintf(output, "output "); 
						astreePrintSingle(node->son[0],level+1);
						break;
		case ASTREE_SINGLE_OUTPUT:		
						fprintf(stderr, "ASTREE_SINGLE_OUTPUT");
						astreePrintSingle(node->son[0],level+1);
						break;
		case ASTREE_LIST_OUTPUT: 	
                        fprintf(stderr, "ASTREE_LIST_OUTPUT");
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, ", "); 
						astreePrintSingle(node->son[1],level+1);
                        break;



		case ASTREE_INPUT: 		
						fprintf(stderr, "ASTREE_INPUT"); 
						fprintf(output, "input"); 
						fprintf(output, " %s",node->symbol->text); 
						break;
		case ASTREE_RETURN: 		
						fprintf(stderr, "ASTREE_RETURN"); 
						fprintf(output, "return "); 
						astreePrintSingle(node->son[0],level+1);
						break;
		case ASTREE_VECTOR_ID: 		
						fprintf(stderr, "ASTREE_VECTOR_ID"); 
						fprintf(output, " %s",node->symbol->text); 
						fprintf(output, "[");  
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, "]");  
						break;
		case ASTREE_FUNC_CALL: 		
						fprintf(stderr, "ASTREE_FUNC_CALL"); 
						fprintf(output, " %s",node->symbol->text); 
						fprintf(output, "(");  
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, ")");  
						break;
		case ASTREE_PONT_END: 		
						fprintf(stderr, "ASTREE_PONT_END"); 
						fprintf(output, " &");  
						fprintf(output, "%s",node->symbol->text); 
						break;
		case ASTREE_PONT_VAL: 		
						fprintf(stderr, "ASTREE_PONT_VAL"); 
						fprintf(output, " *");  
						fprintf(output, "%s",node->symbol->text); 
						break;

	// Parametros
		case ASTREE_PARAM_FUNC: 		
						fprintf(stderr, "ASTREE_PARAM_FUNC"); 
						break;
		case ASTREE_PARAM_FUNC_ID: 	
						fprintf(stderr, "ASTREE_PARAM_FUNC_ID"); 
						fprintf(output, " %s",node->symbol->text); 
						break;
		case ASTREE_PARAM_FUNC_IDLIST: 
						fprintf(stderr, "ASTREE_PARAM_FUNC_IDLIST"); 
						fprintf(output, " %s",node->symbol->text); 
						if(node->son[0])	
							fprintf(output, ",");  
						astreePrintSingle(node->son[0],level+1);
						break;
		case ASTREE_PARAM_DECFUNC: 	
						fprintf(stderr, "ASTREE_PARAM_DECFUNC"); 
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, " %s",node->symbol->text); 
						break;
		case ASTREE_PARAM_DECFUNC_LIST:
						fprintf(stderr, "ASTREE_PARAM_DECFUNC_LIST"); 
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, " %s",node->symbol->text); 
						fprintf(output, ",");  
						astreePrintSingle(node->son[1],level+1);
						break;
		case ASTREE_PARAM_FUNC_VALUE: 	
						fprintf(stderr, "ASTREE_PARAM_FUNC_VALUE");
						astreePrintSingle(node->son[0],level+1);
						break;			
		case ASTREE_PARAM_FUNC_VALUELIST: 
						fprintf(stderr, "ASTREE_PARAM_FUNC_VALUELIST");
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, ",");  
						astreePrintSingle(node->son[1],level+1);
						break;

		case ASTREE_DECFUNC: 		
						fprintf(stderr, "ASTREE_DECFUNC");; 
						fprintf(output, "\n"); 	
						astreePrintSingle(node->son[0],level+1);
						fprintf(output, " %s",node->symbol->text); 
						fprintf(output, "("); 	
						astreePrintSingle(node->son[1],level+1);
						fprintf(output, ")"); 	
						astreePrintSingle(node->son[2],level+1);
						astreePrintSingle(node->son[3],level+1);
						break;

						


		case ASTREE_GLOBAL: 		fprintf(stderr, "ASTREE_GLOBAL"); break;
		default: fprintf(stderr, "ASTREE UNKNOWN"); break;
	}
	
	if(node->symbol)
	{
		if(node->symbol->text)
			fprintf(stderr, ") %s", node->symbol->text);
		else
			fprintf(stderr, ")");
	}
	else
		fprintf(stderr, ")");

}


// print a esquerda
void astreePrintTree (ASTREE *node, int level)
{
	astreePrintSingle(node,0);

}




