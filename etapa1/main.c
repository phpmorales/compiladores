int main(int argc, char *argv[])
{	
	int simb;
	
	initMe();
	
	if (argc<2)
	{
		fprintf(stderr, "call with the file name...\n");
		exit (1);
	}
	if (!(yyin = fopen(argv[1], "r")))
	{
		fprintf(stderr, "Cannot open file\n");
		exit(1);
	}
	
	while (running)
	{
		simb = yylex();
		if(simb)
			printf("linha %d token %d \n", LineNumber, simb);
	}
	

   	hashPrint(&hashTable);
	return 0;
}
