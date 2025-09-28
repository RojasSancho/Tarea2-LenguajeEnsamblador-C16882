#include <stdio.h>
#include <stdlib.h>

// --- Utilidades ---
void limpiar_consola()
{
#ifdef _WIN32
    system("cls"); // Windows
#else
    system("clear"); // Linux o Mac
#endif
}

void esperar_enter()
{
    printf("Presione Enter para continuar...");
    getchar(); // Esperar a que el usuario presione Enter
}

int leer_entero(char *mensaje)
{
    int numero;
    char c;

    while (1)
    {
        printf("%s", mensaje);
        if (scanf("%d", &numero) == 1) {
            while ((c = getchar()) != '\n' && c != EOF); // limpiar buffer
            return numero;
        }
        else {
            printf("Entrada inválida. Por favor, ingrese un número entero.\n\n");
            while ((c = getchar()) != '\n' && c != EOF); // limpiar buffer
        }
    }
}

int leer_entero_positivo(char *mensaje) {
    int numero;
    do {
        numero = leer_entero(mensaje); // Llama a tu función existente
        if (numero < 0) {
            printf("Error: ingrese un número positivo.\n");
        }
    } while (numero < 0);

    return numero;
}

int validar_entero_positivo(const char *numero_str) {
    int i = 0;
    if (numero_str[0] == '\0') return 0; // string vacío no válido

    while (numero_str[i] != '\0') {
        if (numero_str[i] < '0' || numero_str[i] > '9') {
            return 0; // carácter no numérico
        }
        i++;
    }
    return 1; // todos los caracteres son dígitos
}
