CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -Wall -O3 -std=c++11 -I include/

all: main

$(shell mkdir -p $(BUILDDIR))

#fogao:
fogao:
	@mkdir src/fogao
	$(CC) $(CFLAGS) -c src/fogao.cpp -o $(BUILDDIR)/fogao.o
#geladeira:
geladeira:
	@mkdir src/geladeira
	$(CC) $(CFLAGS) -c src/geladeira.cpp -o $(BUILDDIR)/geladeira.o
#estoque:
estoque:
	@mkdir src/estoque
	$(CC) $(CFLAGS) -c src/estoque.cpp -o $(BUILDDIR)/estoque.o
# Modifique a funcao main
main: estoque geladeira fogao
	$(CC) $(CFLAGS) $(BUILDDIR)/estoque.o $(BUILDDIR)/geladeira.o $(BUILDDIR)/fogao.o src/main.cpp -o $(TARGET)

clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
