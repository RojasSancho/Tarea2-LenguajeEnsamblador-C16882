#include <stdio.h>
#include <stdlib.h>
#include "utilidades.h"
#include "operaciones_aritmeticas.h"
#include "operaciones_sistemas_numericos.h"
#include "operaciones_complemento.h"
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
                        printf("\nError: No se puede dividir un número entre cero.\n");
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
            char numero_str[32];
            int base_numerica;

            // Pedir el número y su base
            printf("Ingrese el número a convertir: ");
            scanf("%31s", numero_str); // Leer como string
            base_numerica = pedir_base_numerica(numero_str);

            int numero_en_decimal;

            if (base_numerica == 2) {
                numero_en_decimal = binario_a_decimal(numero_str);
            } else if (base_numerica == 8) {
                numero_en_decimal = octal_a_decimal(numero_str);
            } else if (base_numerica == 10) {
                if (!validar_entero_positivo(numero_str)) {
                    printf("\nError: Número decimal inválido.\n");
                    esperar_enter();
                    break;
                }
                numero_en_decimal = atoi(numero_str); // Convertir string decimal a int
            } else if (base_numerica == 16) {
                numero_en_decimal = hexadecimal_a_decimal(numero_str);
            }

            if (numero_en_decimal == -1) {
                esperar_enter();
                break;
            }

            mostrar_conversiones(numero_en_decimal);
            esperar_enter();
            break;
        case 3:
            printf("Saliendo del programa...\n");
            exit(0);
        }
    }
}
