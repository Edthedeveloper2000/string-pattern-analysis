# Variáveis para o compilador e flags
CC = gcc
CFLAGS = -Wall

# Regra para compilar os arquivos
All: src/main.c 
	$(CC) $(CFLAGS) src/main.c -o exec

# Regra para executar o código após compilar
Run: All
	./exec

# Tornar o alvo padrão o "Run"
.DEFAULT_GOAL := Run

# Regra para limpar os arquivos gerados
clean:
	rm -f exec