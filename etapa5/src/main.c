/*
 *
 * Author: Miller Biazus
 *		   Pedro Henrique Pinto Morales
 * UFRGS - Instituto de Informática
 * Etapa 4 - Compiladores - Prof. Marcelo de Oliveira Johann
 * 2014/2
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/tac.h"
#include "../include/semantic.h"
#include "../include/gv.h"           
#include "../include/ast.h"
#include "../include/hash.h"
#include "../include/y.tab.h"

extern FILE* yyin;
extern FILE *outputAST;
extern FILE *outputTAC;
extern int yylex();
extern char *yytext;

extern int isRunning( void );
extern int lineNumber;
extern int semanticFlag;

int main(int argc, char *argv[]) {
    //int simb;

    initMe();

    if (argc < 2) {
        fprintf(stderr, "Ops! Call me with the filename. Try typing 'etapa1 <nome_do_arquivo>'\n");
        exit(1);
    }
    if (!(yyin = fopen(argv[1], "r"))) {
        fprintf(stderr, "There is an error. It is not possible to open the file!\n");
        fprintf(stderr, "Check if the file path is correct and try again!\n");
        exit(1);
    }

    system("clear");
    printf("\n-----------------------------------------");
    printf("\nUFRGS - INSTITUTE OF INFORMATICS");
    printf("\nINF01147 - COMPILERS 2014/2");
    printf("\nMiller Biazus");
    printf("\nPedro Morales");
    printf("\n-----------------------------------------\n");

    printf("\n-----------------------------------------");
    printf("\nSTARTING PART 5");
    printf("\nPLEASE WAIT, PROCESSING THE FILE...");
    printf("\n-----------------------------------------\n");

    outputAST = fopen(argv[2], "w");
    outputTAC = fopen(argv[3], "w+");

    gv_init("output/graph.dot");	

    while (isRunning()) {
        //Suprimido da etapa 1
        //simb = yylex();
        //if(simb)
        //	printf("LINE: [%d] - TOKEN: [%d] \n", LineNumber, simb);
        yyparse();
    }

    gv_close();	

    //printf("-----------------------------------------");
    //printf("\nTHE FILE WAS READ SUCCESSFULLY:");
    //printf("\n-----------------------------------------\n");

    //hashPrint(&hashTable);

	/* Semantic Warnings */
	if (semanticFlag > 0){
		printf("\nSome semantic error occured!\n");
		printf("There are/is %d semantic error/s!\n", semanticFlag);
		exit(4);	//existence of semantic errors signaled
	}

	fclose(outputAST);
	fclose(outputTAC);


    printf("\n-----------------------------------------");
    printf("\nPART 5 DONE!");
    printf("\n-----------------------------------------\n\n");

    return 0;
}
