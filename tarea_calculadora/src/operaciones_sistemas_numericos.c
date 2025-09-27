#include <stdio.h>
#include <string.h> 
#include <math.h>
#include <ctype.h>

// --- Hacia decimal ---
int binario_a_decimal(const char *binario) {
    int decimal = 0;
    int longitud = strlen(binario); // Número de dígitos

    // Se recorre cada dígito de izquierda a derecha
    for (int i = 0; i < longitud; i++) {
        // Validar que realmente sea un numero en binario
        if (binario[i] != '0' && binario[i] != '1') {
            printf("Error: carácter inválido '%c' en binario.\n", binario[i]);
            return -1; // Retorna -1 para indicar error
        }

        //Conversion a decimal
        int digito = binario[i] - '0'; // Convertir '0' y '1' de caracteres a enteros
        int potencia = longitud - 1 - i; // Posición del dígito (de derecha a izquierda)
        decimal += digito * (int)pow(2, potencia); // Sumar el digito * 2^potencia
    }
    return decimal; // Se devuelve el resultado final en decimal
}

int octal_a_decimal(const char *octal) {
    int decimal = 0;
    int longitud = strlen(octal); // Número de dígitos

    // Se recorre cada dígito de izquierda a derecha
    for (int i = 0; i < longitud; i++) {
        // Validar que realmente sea un numero en octal
        if (octal[i] < '0' || octal[i] > '7')
        {
            printf("Error: carácter inválido '%c' en octal.\n", octal[i]);
            return -1; // Retorna -1 para indicar error
        }

        //Conversion a decimal
        int digito = octal[i] - '0'; // Convertir '0'a'7' de caracteres a enteros
        int potencia = longitud - 1 - i; // Posición del dígito (de derecha a izquierda)
        decimal += digito * (int)pow(8, potencia); // Sumar el digito * 8^potencia
    }
    return decimal;
}

int hexadecimal_a_decimal(const char *hexadecimal) {
    int decimal = 0;
    int longitud = strlen(hexadecimal); // Número de dígitos

    // Se recorre cada dígito de izquierda a derecha
    for (int i = 0; i < longitud; i++) {
        char digito_char = toupper(hexadecimal[i]); // Se convierte a mayusculas
        int digito;

        // Validación y conversión del carácter a valor numérico
        if (digito_char >= '0' && digito_char <= '9') {
            digito = digito_char - '0';
        } else if (digito_char >= 'A' && digito_char <= 'F') {
            digito = 10 + (digito_char - 'A');
        } else {
            printf("Error: carácter inválido '%c' en hexadecimal.\n", hexadecimal[i]);
            return -1; // Retorna -1 para indicar error
        }

        // Conversion a decimal
        int potencia = longitud - 1 - i; // Posición del dígito (de derecha a izquierda)
        decimal += digito * (int)pow(16, potencia); // Sumar digito * 16^potencia
    }
    return decimal;
}

// --- Desde decimal ---
void decimal_a_binario(int decimal, char *resultado) {
    //Caso en que numero decimal es 0
    if (decimal == 0) {
        resultado[0] = '0';
        resultado[1] = '\0';
        return;
    }

    char temp[32];  // Almacena los dígitos temporalmente
    int i = 0;
    int numero = decimal; // Copia local del decimal original (para evitar modificarlo)

    // Dividir el número por 2 repetidamente y guardar los restos
    while (numero > 0) {
        temp[i] = (numero % 2) + '0'; // Convertir dígito a carácter
        numero /= 2;
        i++;
    }

    // Invertir los dígitos para que queden en orden correcto
    int j;
    for (j = 0; j < i; j++) {
        resultado[j] = temp[i - j - 1];
    }
    resultado[i] = '\0';  // Terminar string
}