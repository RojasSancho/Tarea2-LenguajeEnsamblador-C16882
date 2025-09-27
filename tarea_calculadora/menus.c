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
    printf("2. Conversión entre sistemas númericos\n");
    printf("3. Calcular complemento a 1 de un número\n");
    printf("4. Calcular complemento a 2 de un número\n");
    printf("5. Salir\n");

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
    printf("");
    printf("Binario: Digite 2\n");
    printf("Octal: Digite 8\n");
    printf("Decimal: Digite 10\n");
    printf("Hexadecimal: Digite 16\n");

    base_numerica = leer_entero("Digite el número para elegir la base en la que viene el número a convertir: ");

    return base_numerica;
}