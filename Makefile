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

# Detecta o sistema operacional
ifeq ($(OS),Windows_NT)
    RM = del /Q
    TARGET := $(TARGET).exe
else
    RM = rm -f
endif

# Regra padrão
all: $(TARGET)

# Linkagem do executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

# Compilação dos .o
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Rodar o programa
run: $(TARGET)
	./$(TARGET)

clean:
ifeq ($(OS),Windows_NT)
	- del /Q main.o clinica.o bd_clinica.o clinica.exe 2>nul || exit 0
else
	- rm -f main.o clinica.o bd_clinica.o clinica
endif