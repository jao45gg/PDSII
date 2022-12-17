CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -Wall -std=c++11 -I include/

all: main

produto:
	@mkdir build/produto/
	$(CC) $(CFLAGS) -c src/produto.cpp -o build/produto/produto.o

acai:
	@mkdir build/acai/
	$(CC) $(CFLAGS) -c src/acai.cpp -o build/acai/acai.o

cachorro_quente:
	@mkdir build/cachorro_quente/
	$(CC) $(CFLAGS) -c src/cachorro_quente.cpp -o build/cachorro_quente/cachorro_quente.o

pizza:
	@mkdir build/pizza/
	$(CC) $(CFLAGS) -c src/pizza.cpp -o build/pizza/pizza.o

pedido:
	@mkdir build/pedido/
	$(CC) $(CFLAGS) -c src/pedido.cpp -o build/pedido/pedido.o

venda:
	@mkdir build/venda/
	$(CC) $(CFLAGS) -c src/venda.cpp -o build/venda/venda.o

util:
	@mkdir build/util/
	$(CC) $(CFLAGS) -c src/util.cpp -o build/util/util.o

main: produto acai cachorro_quente pizza pedido venda util
	$(CC) $(CFLAGS) build/produto/produto.o build/acai/acai.o build/cachorro_quente/cachorro_quente.o build/pizza/pizza.o build/pedido/pedido.o build/venda/venda.o build/util/util.o src/main.cpp -o $(TARGET)

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
