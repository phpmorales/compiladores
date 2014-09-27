#include <stdio.h>
#include <stdlib.h>
#include "../include/hash.h"
#include "../include/y.tab.h"
#include "../include/ast.h"
#include "../include/gv.h"

extern int isRunning(void);

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
    printf("\nSTARTING PART 3");
    printf("\nPLEASE WAIT, MAKING THE PARSER...");
    printf("\n-----------------------------------------\n");

    outputFile = fopen(argv[2], "w");

    gv_init("output/graph.dot");	

    while (isRunning()) {
        //simb = yylex();
        //if(simb)
        //	printf("LINE: [%d] - TOKEN: [%d] \n", LineNumber, simb);
        yyparse();
    }

    gv_close();	

    printf("-----------------------------------------");
    printf("\nTHE FILE WAS READ SUCCESSFULLY:");
    printf("\n-----------------------------------------\n");

    hashPrint(&hashTable);

    printf("\n-----------------------------------------");
    printf("\nPART 3 DONE!");
    printf("\n-----------------------------------------\n\n");

    fclose(outputFile);

    return 0;
}
