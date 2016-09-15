default: bin/lab1
bin/lab1: bin/algorithm.o bin/io.o bin/util.o bin/main.o
	mkdir -p $(CURDIR)/bin
	gcc bin/algorithm.o bin/io.o bin/util.o bin/main.o -o bin/lab1
bin/algorithm.o: src/algorithm.c headers/algorithm.h headers/io.h headers/util.h
	mkdir -p $(CURDIR)/bin
	gcc -c src/algorithm.c -I headers -o bin/algorithm.o
bin/io.o: src/io.c headers/io.h
	mkdir -p $(CURDIR)/bin
	gcc -c src/io.c -I headers -o bin/io.o
bin/util.o: src/util.c headers/io.h headers/util.h
	mkdir -p $(CURDIR)/bin
	gcc -c src/util.c -I headers -o bin/util.o
bin/main.o: src/main.c headers/algorithm.h headers/io.h headers/util.h
	mkdir -p $(CURDIR)/bin
	gcc -c src/main.c -I headers -o bin/main.o
clean:
	rm -Rf ./bin