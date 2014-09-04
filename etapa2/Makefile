etapa2: y.tab.o lex.yy.o hash.o 
	gcc -o etapa2 hash.o y.tab.o lex.yy.o -Wall

y.tab.c: parser.y
	yacc parser.y -d

lex.yy.c:	scanner.l
	lex scanner.l

lex.yy.o:	lex.yy.c
	gcc -c lex.yy.c -Wall

y.tab.o: y.tab.c
	gcc -c y.tab.c -Wall

hash.o:	hash.c 
	gcc -c hash.c -Wall

clean:
	rm -rf *.o
	rm -rf lex.yy.*
	rm -rf y.tab.*
	rm ./etapa2
