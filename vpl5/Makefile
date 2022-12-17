CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -Wall -std=c++11 -I include/

all: main

fogao:
	@mkdir build/fogao/
	$(CC) $(CFLAGS) -c src/fogao.cpp -o build/fogao/fogao.o

geladeira:
	@mkdir build/geladeira/
	$(CC) $(CFLAGS) -c src/geladeira.cpp -o build/geladeira/geladeira.o

estoque:
	@mkdir build/estoque/
	$(CC) $(CFLAGS) -c src/estoque.cpp -o build/estoque/estoque.o

main: fogao geladeira estoque
	$(CC) $(CFLAGS) build/fogao/fogao.o build/geladeira/geladeira.o build/estoque/estoque.o src/main.cpp -o $(TARGET)

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
