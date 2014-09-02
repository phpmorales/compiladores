etapa1:	clean hash.o lex.yy.o
	gcc -o etapa1 lex.yy.o hash.o -Wall

lex.yy.c: scanner.l
	lex scanner.l

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c -Wall

hash.o:	hash.c 
	gcc -c hash.c -Wall

clean:
	rm -rf *.o
	rm ./lex.yy.c
	rm ./etapa1	
