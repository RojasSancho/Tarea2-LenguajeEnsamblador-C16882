#include <string.h>

// --- OPERACIONES DE COMPLEMENTOS ---
void complemento_a_uno (const char *binario, char *resultado) {
    int i = 0; //indice para recorrer el arreglo de char -> binario
    while (binario[i] != '\0') {
        if (binario[i] == '0') {
            resultado[i] = '1'; // Intercambia caracter por '1' si era un '0'
        } else {
            resultado[i] = '0'; // Intercambia caracter por '0' si era un '1'
        }
        i++;
    }
    resultado[i] = '\0';
}

// Complemento a dos: 
// - Bit mas significativo es 1: numero negativo
// - Bit mas significativo es 0: numero positivo
void complemento_a_dos(const char *binario, char *resultado) {
    int i;

    // Utilizar funcion de complemento a uno
    complemento_a_uno(binario, resultado);

    // Sumar 1 al bit menos significativo
    int acarreo = 1;
    int longitud = strlen(resultado);

    for (i = longitud - 1; i >= 0; i--)
    {
        if (resultado[i] == '1' && acarreo == 1)
        {
            resultado[i] = '0'; // 1 + 1 = 0, acarreo sigue
        }
        else if (resultado[i] == '0' && acarreo == 1)
        {
            resultado[i] = '1'; // 0 + 1 = 1, acarreo se detiene
            acarreo = 0;
        }
        // Si carry es 0, no se hace nada mas
    }
}