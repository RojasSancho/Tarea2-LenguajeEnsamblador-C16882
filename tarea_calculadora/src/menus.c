#include <stdio.h>
#include "utilidades.h"

    // --- Menús ---
    int
    pedir_opcion_menu()
{
    limpiar_consola();
    int opcion_menu_principal;
    // Menu de operaciones aritmeticas
    printf("CALCULADORA\n\n");
    printf("1. Operaciones Aritméticas\n");
    printf("2. Conversión entre Sistemas Númericos\n");
    printf("3. Salir\n");

    opcion_menu_principal = leer_entero("\nDigite el numero de su elección: ");

    return opcion_menu_principal;
}

int pedir_op_aritmetica()
{
    limpiar_consola();
    int opcion_op_aritmetica;
    printf("CALCULADORA\n\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. División\n");
    printf("5. Volver al menú principal\n");

    opcion_op_aritmetica = leer_entero("\nDigite el número de su elección: ");

    return opcion_op_aritmetica;
}

int pedir_base_numerica()
{
    int base_numerica;
    printf("\nBASE:");
    printf("\nBinario: Digite 2\n");
    printf("Octal: Digite 8\n");
    printf("Decimal: Digite 10\n");
    printf("Hexadecimal: Digite 16\n");

    base_numerica = leer_entero("\nDigite la opción que corresponda a la base original de su número: ");

    if (base_numerica != 2 || base_numerica != 8 || base_numerica != 10 || base_numerica != 16) {
        return -1; // Retorna -1 para indicar error
    }

    return base_numerica;
}