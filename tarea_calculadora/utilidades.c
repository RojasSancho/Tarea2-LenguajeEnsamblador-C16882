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
        if (scanf("%d", &numero) == 1)
        {
            while ((c = getchar()) != '\n' && c != EOF)
                ; // limpiar buffer
            return numero;
        }
        else
        {
            printf("Entrada inválida. Por favor, ingrese un número entero.\n");
            while ((c = getchar()) != '\n' && c != EOF)
                ; // limpiar buffer
        }
    }
}