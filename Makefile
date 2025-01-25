# Variáveis para o compilador e flags
CC = gcc
CFLAGS = -Wall

# Regra para compilar os arquivos
All: src/main.c src/algorithms/pattern-matching/brute-force/brute-force.c src/algorithms/pattern-matching/shift-and/shift-and.c src/algorithms/cipher/cipher.c src/io/file-reader.c src/menu/menu.c
	$(CC) $(CFLAGS) src/main.c src/algorithms/pattern-matching/brute-force/brute-force.c src/algorithms/pattern-matching/shift-and/shift-and.c src/algorithms/cipher/cipher.c src/io/file-reader.c src/menu/menu.c -o exec

# Regra para executar o código após compilar
Run: All
	./exec

# Tornar o alvo padrão o "Run"
.DEFAULT_GOAL := Run

# Regra para limpar os arquivos gerados
clean:
	rm -f exec