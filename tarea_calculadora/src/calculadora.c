#include <stdio.h>
#include <stdlib.h>
#include "utilidades.h"
#include "operaciones_aritmeticas.h"
#include "menus.h"

// --- Calculadora ---
void ejecutar_calculadora(){
    while (1)
    {
        int opcion_menu = pedir_opcion_menu();
        switch (opcion_menu)
        {
        case 1:
        {
            int opcion_aritmetica;
            do
            {
                int numero1, numero2;
                /*OPERACIONES ARITMETICAS*/
                opcion_aritmetica = pedir_op_aritmetica();
                switch (opcion_aritmetica)
                {
                case 1:
                {
                    /*OPERACION DE SUMA*/
                    limpiar_consola();
                    printf("CALCULADORA: Suma\n\n");
                    numero1 = leer_entero("Digite el primer número: ");
                    numero2 = leer_entero("Digite el segundo número: ");
                    printf("El resultado de la suma es: %d\n", sumar(numero1, numero2));
                    esperar_enter();
                    break;
                }
                case 2:
                {
                    /*OPERACION DE RESTA*/
                    limpiar_consola();
                    printf("CALCULADORA: Resta\n\n");
                    numero1 = leer_entero("Digite el primer número (minuendo): ");
                    numero2 = leer_entero("Digite el segundo número (sustraendo): ");
                    printf("El resultado de la resta es: %d\n", restar(numero1, numero2));
                    esperar_enter();
                    break;
                }
                case 3:
                {
                    /*OPERACION DE MULTIPLICACION*/
                    limpiar_consola();
                    printf("CALCULADORA: Multiplicación\n\n");
                    numero1 = leer_entero("Digite el primer número: ");
                    numero2 = leer_entero("Digite el segundo número: ");
                    printf("El producto de la multiplicación es: %d\n", multiplicar(numero1, numero2));
                    esperar_enter();
                    break;
                }
                case 4:
                {
                    /*OPERACION DE DIVISION*/
                    limpiar_consola();
                    printf("CALCULADORA: División\n\n");
                    numero1 = leer_entero("Digite el primer número (dividendo): ");
                    numero2 = leer_entero("Digite el segundo número (divisor): ");
                    if (numero2 == 0)
                    {
                        printf("Error: No se puede dividir un número entre cero.\n");
                        esperar_enter();
                        break; // vuelve al menu
                    }
                    printf("El cociente de la división es: %.2f\n", dividir(numero1, numero2));
                    esperar_enter();
                    break;
                }
                case 5:
                    break;
                }
            } while (opcion_aritmetica != 5); // 5 es volver al menu principal
            break;
        }
        case 2:
            /*CONVERSION ENTRE SISTEMAS NUMERICOS*/
            limpiar_consola();
            printf("CALCULADORA: Sistemas númericos\n\n");
            int numero = leer_entero("Digite el número que desea convertir a otra base: ");
            int base_numerica = pedir_base_numerica();

            break;
        case 3:
            /*COMPLEMENTO A 1*/
            break;
        case 4:
            /*COMPLEMENTO A 2*/
            break;
        case 5:
            printf("Saliendo del programa...\n");
            exit(0);
        }
    }
}
