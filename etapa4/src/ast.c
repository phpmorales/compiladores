#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/ast.h"
#include "../include/hash.h"

extern  int     getLineNumber(void);
extern  FILE    *output;

ast* astCreate(int type, HASH_NODE *symbol, ast *s0,ast *s1, ast *s2, ast *s3)
{
	ast *newnode;
	newnode = (ast*) calloc(1,sizeof(ast));
	newnode->type = type;
	newnode->symbol = symbol;
	newnode->son[0]= s0;
	newnode->son[1]= s1;
	newnode->son[2]= s2;
	newnode->son[3]= s3;
	return newnode;
};

void astPrintNode (ast *node)
{
	if(node==0) 
        return;

    printf("[");
	switch(node->type)
	{
		/* ROOT NODE */
		case AST_PROGRAM_INI:   printf("AST_PROGRAM");				break;	
		case AST_PROGRAM: 		printf("AST_PROGRAM");				break;	
		
		/* COMMANDS */
		case AST_CMD_LIST: 		printf("AST_CMD_LIST");				break;
		
		/* BLOCK */
		case AST_BLOCK: 		printf("AST_BLOCK");				break;		
		
		/* DATA TYPE */
		case AST_BOOL: 			printf("AST_BOOL");					break;
		case AST_WORD: 			printf("AST_WORD");					break;
		case AST_BYTE: 			printf("AST_BYTE");					break;
		
		/* ARIM OPERATIONS */
		case AST_SYMBOL:    	printf("AST_SYMBOL"); 				break;
		case AST_ADD:       	printf("AST_ADD");    				break;
		case AST_SUB:       	printf("AST_SUB");     				break;
		case AST_MUL: 			printf("AST_MUL");					break;
		case AST_DIV: 			printf("AST_DIV");					break;
		
		/* LOGICAL OPERATIONS */
        case AST_GREATER: 		printf("AST_GREATER");				break;
        case AST_LESS: 			printf("AST_LESS");					break;
        case AST_AND: 			printf("AST_AND");					break;
        case AST_OR: 			printf("AST_OR");					break;
        case AST_LE: 			printf("AST_LE");					break;
        case AST_GE: 			printf("AST_GE");					break;
        case AST_EQ: 			printf("AST_EQ");					break;
        case AST_NE: 			printf("AST_NE");					break;
        case AST_INV_EXPR: 		printf("AST_INV_EXPR");				break;
        case AST_BOOLEAN_INV: 	printf("AST_BOOLEAN_INV");			break;
        case AST_ARIT_INV:		printf("AST_ARIT_INV");				break;
		
		/* I/O */
		case AST_IN: 			printf("AST_IN");					break;		
		case AST_OUT_ARG: 		printf("AST_OUT_ARG");				break;
		case AST_OUT: 			printf("AST_OUT");					break;

		/* EXPRESSION */
		case AST_PAR_EXPR: 		printf("AST_PAR_EXPR");				break;	
		
		/*	FLUX CONTROL */
		case AST_IF: 			printf("AST_IF");					break;
		case AST_CMD_THEN: 		printf("AST_CMD_THEN");				break;
		case AST_CMD_ELSE: 		printf("AST_CMD_ELSE");				break;
		case AST_CMD_LOOP: 		printf("AST_CMD_LOOP");				break;		
		
		/* DECLARATIONS/DEFINITIONS */
		case AST_DEC:			printf("AST_DEC");					break;
		case AST_DECL: 			printf("AST_DECL");					break;
		case AST_FUN_DEF:  		printf("AST_FUN_DEF");				break;
		case AST_NDEC: 			printf("AST_NDEC");					break;
		case AST_POINTER_DEC: 	printf("AST_POINTER_DEC");			break;
		case AST_ARRAY_DEC: 	printf("AST_ARRAY_DEC");			break;		
		case AST_INDEX: 		printf("AST_INDEX");				break;
		
		/* POINTERS */
		case AST_POINTER_ADDR:  printf("AST_POINTER_ADDR"); 		break;		
		case AST_POINTER: 	    printf("AST_POINTER");				break;			
		
		/* FUNCTIONS AND PARAMETERS */
		case AST_PARAM: 		printf("AST_PARAM");				break;
		case AST_PASS_PARAM: 	printf("AST_PASS_PARAM");			break;
		case AST_PARAM_REF: 	printf("AST_PARAM_REF");			break;
		case AST_FUNC_CALL: 	printf("AST_FUNC_CALL");			break;	
		case AST_RETURN: 		printf("AST_RETURN");				break;		
		
		/* ATRIBUITIONS */
		case AST_ATRR: 			printf("AST_ATRR");					break;		
		case AST_ATRR_LIT: 		printf("AST_ATRR_LIT");				break;
	
		/* DEFAULT ACTION */
		default: 				printf("AST_ERROR %d", node->type);	break;
	}
     printf("]");

	if(node->symbol)    
        printf("[%s]\n",node->symbol->text);
	else                
        printf("\n");

}

void astPrintTree (ast* node, int level)
{
	int i = 0;
	int j = 0;

	if (!node) 
        return;

	for (j = 0; j < level; ++j) 
        fprintf(stderr, " ");

	printf("[%d]",level);

	astPrintNode(node);

	for (i = 0; i < MAX_SONS; ++i)
		if(node->son[i]) 
            astPrintTree(node->son[i], level + 1);

}

void decompile(ast *root)
{	
	if (root !=0)
	{
	    switch(root->type)
	    {	
			/* ROOT NODE */		
			case AST_PROGRAM_INI:	
				decompile(root->son[0]); 
				break;
			/* ROOT NODE */		
			case AST_PROGRAM:	
				decompile(root->son[0]); 
                decompile(root->son[1]); 
				break;
				
			/* COMMANDS */	
			case AST_CMD_LIST:	decompile(root->son[0]);
				if(root->son[1]!=0)
					fprintf(output,";\n");
				decompile(root->son[1]);					
				break;				
			
			/* BLOCK */
			case AST_BLOCK:		
				fprintf(output,"{\n");
				decompile(root->son[0]);
				fprintf(output,"}");									
				break;				
			
			/* DATA TYPE */
			case AST_WORD: 	 
				fprintf(output,"word "); 
				break;
			case AST_BYTE:		 
				fprintf(output,"byte "); 
				break;
			case AST_BOOL: 	 
				fprintf(output,"bool "); 
				break;
			case AST_SYMBOL:	 
				fprintf(output,"%s",root->symbol->text); 
				decompile(root->son[0]); 
				break;				
			
			/* ARIM OPERATIONS */
			case AST_ADD:		
				decompile(root->son[0]);
				fprintf(output," + ");
				decompile(root->son[1]);
				break;
			case AST_SUB:		
				decompile(root->son[0]);
				fprintf(output," - ");
				decompile(root->son[1]);
				break;
			case AST_MUL:		
				decompile(root->son[0]);
				fprintf(output," * ");
				decompile(root->son[1]);
				break;
			case AST_DIV:		
				decompile(root->son[0]);
				fprintf(output," / ");
				decompile(root->son[1]);
				break;								
			
			/* LOGICAL OPERATIONS*/
			case AST_GREATER:	
				decompile(root->son[0]);
				fprintf(output," > ");
				decompile(root->son[1]);
				break;
			case AST_LESS:		
				decompile(root->son[0]);
				fprintf(output," < ");
				decompile(root->son[1]);
				break;
			case AST_AND:		
				decompile(root->son[0]);
				fprintf(output," && ");
				decompile(root->son[1]);
				break;
			case AST_OR:		
				decompile(root->son[0]);
				fprintf(output," || ");
				decompile(root->son[1]);
			case AST_LE:		
				decompile(root->son[0]);
				fprintf(output," <= ");
				decompile(root->son[1]);
				break;
			case AST_GE:		
				decompile(root->son[0]);
				fprintf(output," >= ");
				decompile(root->son[1]);
				break;	
			case AST_EQ:		
				decompile(root->son[0]);
				fprintf(output," == ");
				decompile(root->son[1]);
				break;
			case AST_NE:		
				decompile(root->son[0]);
				fprintf(output," != ");
				decompile(root->son[1]);
				break;	
			case AST_INV_EXPR:	
				decompile(root->son[0]);
				fprintf(output,"(");
				decompile(root->son[1]);
				fprintf(output,")");					
				break;
			case AST_BOOLEAN_INV:	 
				fprintf(output,"!");
				break;
			case AST_ARIT_INV:	 
				fprintf(output,"-");
				break;					
			
			/* I/O */
			case AST_IN:		 
				fprintf(output,"input ");
				fprintf(output,"%s",root->symbol->text); 
				decompile(root->son[1]);					
				break;	
			case AST_OUT:		 
				fprintf(output,"output ");
				decompile(root->son[0]);
				break;
			case AST_OUT_ARG:	
			if(root->symbol !=0)
				fprintf(output,"%s",root->symbol->text);
				decompile(root->son[0]);
					if(root->son[1]!=0)
				fprintf(output,",");
				decompile(root->son[1]);				
				break;					
			
			/* EXPRESSION */
			case AST_PAR_EXPR:	 
				fprintf(output,"(");
				decompile(root->son[1]);
				fprintf(output,")");
				break;				
			
			/*	FLUX CONTROL */
			case AST_IF:		 
				fprintf(output,"if (");
				decompile(root->son[0]);
				fprintf(output,") ");
				decompile(root->son[1]);
				decompile(root->son[2]);				
				break;
			case AST_CMD_THEN:	 
				fprintf(output,"then "); 
				break;
			case AST_CMD_ELSE:	 
				fprintf(output,"else "); 
				break;
			case AST_CMD_LOOP:	 
				fprintf(output,"loop "); 
				break;				
			
			/* DECLARATIONS */
			case AST_DEC:	
				decompile(root->son[0]);
				decompile(root->son[1]);
				fprintf(output,";\n");			      	
				break;
			case AST_DECL:		
				decompile(root->son[0]);
   				decompile(root->son[1]);
				fprintf(output,";\n");					
				break;
			case AST_FUN_DEF:	 
				decompile(root->son[0]);
				fprintf(output,"%s (",root->symbol->text); 
				decompile(root->son[1]);
				fprintf(output,")");
				fprintf(output,"\n");
				decompile(root->son[2]); 		
				break;		
			case AST_NDEC:  
				decompile(root->son[0]);
				fprintf(output,"%s:",root->symbol->text);
				decompile(root->son[1]);
				break;
			case AST_POINTER_DEC: 	
				decompile(root->son[0]);
				fprintf(output,"$%s:",root->symbol->text); 
				decompile(root->son[1]);					
				break;
			case AST_ARRAY_DEC: 	
				decompile(root->son[0]);
				fprintf(output,"%s[",root->symbol->text);
				decompile(root->son[1]);
				fprintf(output,"]");
				if(root->son[2] !=0)
					fprintf(output,":");
				decompile(root->son[2]);					
				break;	
			case AST_INDEX:		 
				fprintf(output,"[");
				decompile(root->son[0]);
				fprintf(output,"]");
				break;					
				
			/* POINTERS */
			case AST_POINTER: 	 
				fprintf(output,"$%s",root->symbol->text);
				break;				
			case AST_POINTER_ADDR:	 
				fprintf(output,"&%s",root->symbol->text);
				break;
				
			/* FUNCTIONS AND PARAMETERS */
			case AST_PARAM:	
				decompile(root->son[0]);
				fprintf(output,"%s",root->symbol->text); 
				if(root->son[1] !=0)
					fprintf(output,",");
				decompile(root->son[1]);					
				break;
			case AST_PASS_PARAM:	
				decompile(root->son[0]);
				if(root->son[1]!=0)
					fprintf(output,",");
				decompile(root->son[1]);		
				break;	
			case AST_PARAM_REF:	
				fprintf(output,"$");
				decompile(root->son[0]);
				if(root->son[1]!=0)
					fprintf(output,",");
				decompile(root->son[1]);		
				break;						
			case AST_FUNC_CALL:	 
				fprintf(output,"%s",root->symbol->text);
				fprintf(output,"(");
				decompile(root->son[0]);
				fprintf(output,")");
				break;										
			case AST_RETURN:	 
				fprintf(output,"return ");
				decompile(root->son[0]);			
				break;					
				
			/* ATRIBUITIONS */
			case AST_ATRR: 
				decompile(root->son[0]);
				fprintf(output," = ");
				decompile(root->son[1]);
				break;				
			case AST_ATRR_LIT:	
				decompile(root->son[0]);
				if(root->son[1])fprintf(output," ");
				decompile(root->son[1]);					
				break;

			/* DEFAULT ACTION */
			default:		 
				printf("END"); 
				break;      
	    }
    }
}



