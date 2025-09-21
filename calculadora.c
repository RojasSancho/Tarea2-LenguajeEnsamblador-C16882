#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

void limpiar_consola()
{
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // Linux o Mac
    #endif
}

int pedir_opcion_menu(){
    int opcion_menu_principal; 
    // Menu de operaciones aritmeticas
    printf("CALCULADORA\n\n");
    printf("1. Operaciones Aritméticas\n");
    printf("2. Conversión entre sistemas númericos\n");
    printf("3. Calcular complemento a 1 de un número\n");
    printf("4. Calcular complemento a 2 de un número\n");
    printf("5. Salir\n");

    printf("\nDigite el numero de su elección: ");
    scanf("%d", &opcion_menu_principal);

    return opcion_menu_principal;
}

int pedir_op_aritmetica(){
    limpiar_consola();
    int opcion_op_aritmetica;
    printf("CALCULADORA\n\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. División\n");
    printf("5. Volver al menú principal\n");

    printf("\nDigite el numero de su elección: ");
    scanf("%d", &opcion_op_aritmetica);

    return opcion_op_aritmetica;
}

int sumar(int numero1, int numero2){
    int resultado = numero1 + numero2;
    return resultado;
}

int main(void) {

    #ifdef _WIN32
    // Configura la consola a UTF-8 en sistemas Windows
    SetConsoleOutputCP(CP_UTF8); 
    #endif

    int opcion_menu = pedir_opcion_menu();
    switch(opcion_menu){
        case 1:{
            /*OPERACIONES ARITMETICAS*/
            int opcion_aritmetica = pedir_op_aritmetica();
            switch(opcion_aritmetica){
                case 1:{
                    /*OPERACION DE SUMA*/
                    limpiar_consola();
                    int numero1, numero2;
                    printf("CALCULADORA\n\n");
                    printf("Digite el primer número: ");
                    scanf("%d", &numero1);
                    printf("Digite el segundo número: ");
                    scanf("%d", &numero2);
                    printf("El resultado de la suma es: %d\n", sumar(numero1, numero2));
                    break;
                }
                case 2:
                    /*OPERACION DE RESTA*/
                    break;
                case 3:
                    /*OPERACION DE MULTIPLICACION*/
                    break;
                case 4:
                    /*OPERACION DE DIVISION*/
                    break;
                case 5:
                    break;
                }
            break;
        }
        case 2:
            /*CONVERSION ENTRE SISTEMAS NUMERICOS*/
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

    return 0;
}