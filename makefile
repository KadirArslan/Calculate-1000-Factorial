hepsi: derle calistir
	
derle:	
	@echo Calistiriliyor...
	g++ -I ./include/ -o ./lib/Number.o -c ./src/Number.cpp
	g++ -I ./include/ -o ./bin/test ./lib/Number.o ./src/test.cpp
calistir:
	./bin/test