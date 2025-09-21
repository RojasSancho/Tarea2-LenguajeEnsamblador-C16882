# Nombre del ejecutable
TARGET = calculadora

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra

# Archivos fuente
SRC = calculadora.c

# Regla por defecto: compila y ejecuta
all: $(TARGET)
	./$(TARGET)

# Compila el ejecutable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Limpieza de archivos generados
clean:
	rm -f $(TARGET)