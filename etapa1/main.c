int main(int argc, char *argv[])
{	
	int simb;
	
	initMe();
	
	if (argc<2)
	{
		fprintf(stderr, "Ops! Call me with the filename. Try type 'etapa1 <nome_do_arquivo>'\n");
		exit (1);
	}
	if (!(yyin = fopen(argv[1], "r")))
	{
		fprintf(stderr, "There is some error. It is not possible open the file!\n");
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
	printf("\nNOW WILL THE FILE WILL BE READ");
	printf("\nPLEASE WAIT, MAKING THE PARSER...");
	printf("\n-----------------------------------------\n");
	
	while (isRunning())
	{
		simb = yylex();
		if(simb)
			printf("LINE: [%d] - TOKEN: [%d] \n", LineNumber, simb);
	}
	printf("-----------------------------------------");
	printf("\nTHE FILE WAS READ SUCCESSFULLY:");
	printf("\n-----------------------------------------\n");

   	hashPrint(&hashTable);

        printf("\n-----------------------------------------");
	printf("\nPART 1 DONE!");
	printf("\n-----------------------------------------\n\n");

	return 0;
}
