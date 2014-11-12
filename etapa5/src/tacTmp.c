void tacPrintSingle(tac_t* tac){

	if(!tac) return;
	
	printf("TAC(");
	fprintf(outputTAC,"\nTAC(");
	switch(tac->type){
		case TAC_ADD: 		
			printf("TAC_ADD");
			fprintf(outputTAC,"TAC_ADD");
			break;
		case TAC_SUB:
			printf("TAC_SUB");
			fprintf(outputTAC,"TAC_SUB");
			break;
		case TAC_MUL:
	 		printf("TAC_MUL");
			fprintf(outputTAC,"TAC_MUL");
			break;
		case TAC_DIV:
	 		printf("TAC_DIV");
			fprintf(outputTAC,"TAC_DIV");
			break;

		case TAC_DATAINT:
		 	printf("TAC_DATAINT");
			fprintf(outputTAC,"TAC_DATAINT");
			break;

		case TAC_DATABOOL:
		 	printf("TAC_DATABOOL");
			fprintf(outputTAC,"TAC_DATABOOL");
			break;

		case TAC_INTEGER:
		     	printf("TAC_INTEGER");
			fprintf(outputTAC,"TAC_INTEGER");
			break;
	
		case TAC_BOOLEAN:
		     	printf("TAC_BOOLEAN");
			fprintf(outputTAC,"TAC_BOOLEAN");
			break;
		case TAC_CHARACTER:
		   	printf("TAC_CHARACTER");
			fprintf(outputTAC,"TAC_CHARACTER");
			break;
		case TAC_STRING:
		 	printf("TAC_STRING");
			fprintf(outputTAC,"TAC_STRING");
			break;

		case TAC_INPUT:
		       	printf("TAC_INPUT");
			fprintf(outputTAC,"TAC_INPUT");
			break;
		case TAC_OUTPUT:
		      	printf("TAC_OUTPUT");
			fprintf(outputTAC,"TAC_OUTPUT");
			break;
		case TAC_RETURN:
		      	printf("TAC_RETURN");
			fprintf(outputTAC,"TAC_RETURN");
			break;

		case TAC_LE:
	 		printf("TAC_LE");
			fprintf(outputTAC,"TAC_LE");
			break;
		case TAC_GE:
	 		printf("TAC_GE");
			fprintf(outputTAC,"TAC_GE");
			break;
		case TAC_EQ:
	 		printf("TAC_EQ");
			fprintf(outputTAC,"TAC_EQ");
			break;
		case TAC_NE:
	 		printf("TAC_NE");
			fprintf(outputTAC,"TAC_NE");
			break;
		case TAC_AND:
	 		printf("TAC_AND");
			fprintf(outputTAC,"TAC_AND");
			break;
		case TAC_OR:
	 		printf("TAC_OR");
			fprintf(outputTAC,"TAC_OR");
			break;

		case TAC_MOV:
			printf("TAC_MOV");
			fprintf(outputTAC,"TAC_MOV");
			break;
		case TAC_MOV_VET:
			printf("TAC_MOV_VET");
			fprintf(outputTAC,"TAC_MOV_VET");
			break;
		case TAC_MAIOR:
			printf("TAC_MAIOR");
			fprintf(outputTAC,"TAC_MAIOR");
			break;
		case TAC_MENOR:
		   	printf("TAC_MENOR");
			fprintf(outputTAC,"TAC_MENOR");
			break;

		case TAC_LABEL:
			printf("TAC_LABEL");
			fprintf(outputTAC,"TAC_LABEL");
			break;
		case TAC_BEGINFUN:
			printf("TAC_BEGINFUN");
			fprintf(outputTAC,"TAC_BEGINFUN");
			break;
		case TAC_ENDFUN:
			printf("TAC_ENDFUN");
			fprintf(outputTAC,"TAC_ENDFUN");
			break;
		case TAC_CALL:
			printf("TAC_CALL");
			fprintf(outputTAC,"TAC_CALL");
			break;
		case TAC_JUMP:
			printf("TAC_JUMP");
			fprintf(outputTAC,"TAC_JUMP");
			break;
		case TAC_VETOR:
			printf("TAC_VETOR");
			fprintf(outputTAC,"TAC_VETOR");
			break;
		case TAC_VARIABLE:
			printf("TAC_VARIABLE");
			fprintf(outputTAC,"TAC_VARIABLE");
			break;
        case TAC_VAR_VET:
			printf("TAC_VAR_VET");
			fprintf(outputTAC,"TAC_VAR_VET");
			break;
		case TAC_JFALSE:
			printf("TAC_JFALSE");
			fprintf(outputTAC,"TAC_JFALSE");
			break;
		case TAC_SALTO:
			printf("TAC_SALTO");
			fprintf(outputTAC,"TAC_SALTO");
			break;
		case TAC_DECLARE:
		 	printf("TAC_DECLARE");
			fprintf(outputTAC,"TAC_DECLARE");
			break;
        case TAC_DEC_POINTER:
		 	printf("TAC_DEC_POINTER");
			fprintf(outputTAC,"TAC_DEC_POINTER");
			break;
		case TAC_DECLAREVET:
			printf("TAC_DECLAREVET");
			fprintf(outputTAC,"TAC_DECLAREVET");
			break;
		case TAC_LISTAPARAM:
			printf("TAC_LISTAPARAM");
			fprintf(outputTAC,"TAC_LISTAPARAM");
			break;
		case TAC_PARAMETRO:
			printf("TAC_PARAMETRO");
			fprintf(outputTAC,"TAC_PARAMETRO");
			break;

		default:
	 		printf("UNKNOWN");
			fprintf(outputTAC,"UNKNOWN");
			break;
	}
	
	if(tac->target){
	 	printf(", %s ",tac->target->text);
		fprintf(outputTAC,", %s ",tac->target->text);
	}
	/*else{
	 	printf(",");
		fprintf(outputTAC,",");
	}*/
	if(tac->op1){
	 	printf(", %s ",tac->op1->text);
		fprintf(outputTAC,", %s ",tac->op1->text);
	}
	/*else{
	 	printf(",");
		fprintf(outputTAC,",");
	}*/
	if(tac->op2){
	 	printf(", %s ",tac->op2->text);
		fprintf(outputTAC,", %s ",tac->op2->text);
	}
	/*else{
	 	printf(",");
		fprintf(outputTAC,",");
	}*/
	
	printf(")\n");
	fprintf(outputTAC,")\n");

}


