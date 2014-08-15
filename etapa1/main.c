int main(int argc, char *argv[])
{	
	int simb;
	
	initMe();
	
	if (argc<2)
	{
		fprintf(stderr, "ops! faltou chamar o nome do arquivo. Exemplo: etapa1 <nome_do_arquivo>\n");
		exit (1);
	}
	if (!(yyin = fopen(argv[1], "r")))
	{
		fprintf(stderr, "Houve algum erro. Não é possível abrir o arquivo!\n");
		fprintf(stderr, "Verifique se o nome do arquivo está correto e tente novamente!\n");
		exit(1);
	}

	system("clear");
	printf("\n-----------------------------------------");
	printf("\nUFRGS - INSITITUTO DE INFORMATICA");
	printf("\nCOMPILADORES 2014/2");
	printf("\nMiller Biazus");
	printf("\nPedro Morales");
	printf("\n-----------------------------------------\n");

	printf("\n-----------------------------------------");
	printf("\nAGORA SERÁ REALIZADA A LEITURA DO ARQUIVO");
	printf("\nAGUARDE, REALIZANDO PARSER...");
	printf("\n-----------------------------------------\n");
	
	while (running)
	{
		simb = yylex();
		if(simb)
			printf("Linha: %d - Token: %d \n", LineNumber, simb);
	}
	printf("-----------------------------------------");
	printf("\nARQUIVO LIDO COM SUCESSO:");
	printf("\n-----------------------------------------\n");

   	hashPrint(&hashTable);

        printf("\n-----------------------------------------");
	printf("\nETAPA 1 FINALIZADA!");
	printf("\n-----------------------------------------\n\n");

	return 0;
}
