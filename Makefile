# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I.
LDFLAGS = 

# Nome do executável
TARGET = clinica

# Arquivos fonte
SRCS = main.c clinica.c bd_clinica.c

# Arquivos objeto (gerados automaticamente a partir dos .c)
OBJS = $(SRCS:.c=.o)

# Arquivos de cabeçalho
HEADERS = clinica.h bd_clinica.h

# Regra padrão
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

# Regra genérica para compilar qualquer arquivo .c em .o
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	del /Q $(OBJS) $(TARGET).exe 2>nul

# Regra para rodar o programa
run: $(TARGET)
	./$(TARGET)

# Dependências específicas (se necessário)
main.o: main.c clinica.h bd_clinica.h
clinica.o: clinica.c clinica.h
bd_clinica.o: bd_clinica.c bd_clinica.h

.PHONY: all clean run