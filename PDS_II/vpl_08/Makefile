CC := g++
CFLAGS := -I include/ -Wall
BUILD := build/
SRC := src/
TARGET := main.out

all: main

$(shell mkdir -p $(BUILD))

acai:
	@mkdir -p $(BUILD)acai/
	$(CC) $(CFLAGS) -c $(SRC)acai.cpp -o $(BUILD)acai/acai.o

cachorro_quente:
	@mkdir -p $(BUILD)cachorro_quente/
	$(CC) $(CFLAGS) -c $(SRC)cachorro_quente.cpp -o $(BUILD)cachorro_quente/cachorro_quente.o

pedido:
	@mkdir -p $(BUILD)pedido/
	$(CC) $(CFLAGS) -c $(SRC)pedido.cpp -o $(BUILD)pedido/pedido.o

pizza:
	@mkdir -p $(BUILD)pizza/
	$(CC) $(CFLAGS) -c $(SRC)pizza.cpp -o $(BUILD)pizza/pizza.o

produto:
	@mkdir -p $(BUILD)produto/
	$(CC) $(CFLAGS) -c $(SRC)produto.cpp -o $(BUILD)produto/produto.o

venda:
	@mkdir -p $(BUILD)venda/
	$(CC) $(CFLAGS) -c $(SRC)venda.cpp -o $(BUILD)venda/venda.o

util:
	@mkdir -p $(BUILD)util/
	$(CC) $(CFLAGS) -c $(SRC)util.cpp -o $(BUILD)util/util.o

main: acai cachorro_quente pedido pizza produto venda util
	$(CC) $(CFLAGS) $(BUILD)util/util.o $(BUILD)venda/venda.o $(BUILD)produto/produto.o $(BUILD)pizza/pizza.o $(BUILD)acai/acai.o $(BUILD)cachorro_quente/cachorro_quente.o $(BUILD)pedido/pedido.o $(SRC)main.cpp -o $(TARGET)

clean:
	$(RM) -r $(BUILD)* $(TARGET)