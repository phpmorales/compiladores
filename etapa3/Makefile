etapa3: y.tab.c y.tab.o lex.yy.c lex.yy.o gv.o hash.o ast.o 
	gcc -o etapa3 bin/ast.o bin/gv.o bin/hash.o bin/y.tab.o bin/lex.yy.o -Wall 

y.tab.o:
	gcc -c src/y.tab.c -Wall
	mv y.tab.o bin

y.tab.c:
	yacc tool/parser.y -d
	mv y.tab.c src
	mv y.tab.h include

lex.yy.o:
	gcc -c src/lex.yy.c -Wall
	mv lex.yy.o bin

lex.yy.c:
	lex tool/scanner.l
	mv lex.yy.c src

gv.o:
	gcc -c src/gv.c -Wall
	mv gv.o bin

hash.o:
	gcc -c src/hash.c -Wall
	mv hash.o bin
 
ast.o:
	gcc -c src/ast.c -Wall
	mv ast.o bin

clean:
	rm -rf etapa3
	rm -rf bin/*.o
	rm -rf src/lex.yy.*
	rm -rf src/y.tab.*
	rm -rf outpu/*
