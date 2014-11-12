etapa5: y.tab.c y.tab.o lex.yy.c lex.yy.o hash.o ast.o gv.o semantic.o tac.o
	gcc -o etapa5 bin/tac.o bin/semantic.o bin/gv.o bin/ast.o bin/hash.o bin/y.tab.o bin/lex.yy.o -Wall

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

hash.o:
	gcc -c src/hash.c -Wall
	mv hash.o bin
 
ast.o:
	gcc -c src/ast.c -Wall
	mv ast.o bin

gv.o:
	gcc -c src/gv.c -Wall
	mv gv.o bin

semantic.o:
	gcc -c src/semantic.c -Wall
	mv semantic.o bin

tac.o:
	gcc -c src/tac.c -Wall
	mv tac.o bin

clean:
	rm -rf etapa5
	rm -rf bin/*.o
	rm -rf src/lex.yy.*
	rm -rf src/y.tab.*
	rm -rf output/*

execute:
	./etapa5 input/input output/output1
	./etapa5 output/output1 output/output2

exec:
	./etapa5 input/input output/outputAST output/outputTAC

compare:
	diff -a -y output/output1 output/output2 
	diff -q output/output1 output/output2 

graph:
	dot output/graph.dot -Tpng -o output/graph.png
	display output/graph.png
