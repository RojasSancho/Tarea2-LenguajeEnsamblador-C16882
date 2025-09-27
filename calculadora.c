#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

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
    while (getchar() != '\n'); // Limpiar el buffer de entrada
    getchar(); // Esperar a que el usuario presione Enter
}

int leer_entero(char *mensaje) {
    int numero;
    char c;

    while (1) {
        printf("%s", mensaje);
        if (scanf("%d", &numero) == 1) {
            while ((c = getchar()) != '\n' && c != EOF); // limpiar buffer
            return numero;
        } else {
            printf("Entrada inválida. Por favor, ingrese un número entero.\n");
            while ((c = getchar()) != '\n' && c != EOF); // limpiar buffer
        }
    }
}

// --- Menús ---
int pedir_opcion_menu(){
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

int pedir_op_aritmetica(){
    limpiar_consola();
    int opcion_op_aritmetica;
    printf("CALCULADORA\n\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. División\n");
    printf("5. Volver al menú principal\n");

    opcion_op_aritmetica = leer_entero("\nDigite el numero de su elección: ");

    return opcion_op_aritmetica;
}

// --- Operaciones aritméticas ---
int sumar(int numero1, int numero2){
    int resultado = numero1 + numero2;
    return resultado;
}

int restar(int numero1, int numero2){
    int resultado = numero1 - numero2;
    return resultado;
}

int multiplicar(int numero1, int numero2){
    int resultado = numero1 * numero2;
    return resultado;
}

float dividir(int numero1, int numero2){
    float resultado = (float)numero1 / (float)numero2;
    return resultado;
}

// --- Programa principal ---
int main(void) {
    #ifdef _WIN32
    // Configura la consola a UTF-8 en sistemas Windows
    SetConsoleOutputCP(CP_UTF8); 
    #endif
    while(1){
        int opcion_menu = pedir_opcion_menu();
        switch(opcion_menu){
        case 1:{
            int opcion_aritmetica;
            do {
                /*OPERACIONES ARITMETICAS*/
                opcion_aritmetica = pedir_op_aritmetica();
                switch(opcion_aritmetica){
                    case 1:{
                        /*OPERACION DE SUMA*/
                        limpiar_consola();
                        int numero1, numero2;
                        printf("CALCULADORA: Suma\n\n");
                        printf("Digite el primer número: ");
                        scanf("%d", &numero1);
                        printf("Digite el segundo número: ");
                        scanf("%d", &numero2);
                        printf("El resultado de la suma es: %d\n", sumar(numero1, numero2));
                        esperar_enter();
                        break;
                    }
                    case 2: {
                        /*OPERACION DE RESTA*/
                        limpiar_consola();
                        int numero1, numero2;
                        printf("CALCULADORA: Resta\n\n");
                        printf("Digite el primer número (minuendo): ");
                        scanf("%d", &numero1);
                        printf("Digite el segundo número (sustraendo): ");
                        scanf("%d", &numero2);
                        printf("El resultado de la resta es: %d\n", restar(numero1, numero2));
                        esperar_enter();
                        break;
                    }
                    case 3: {
                        /*OPERACION DE MULTIPLICACION*/
                        limpiar_consola();
                        int numero1, numero2;
                        printf("CALCULADORA: Multiplicación\n\n");
                        printf("Digite el primer número: ");
                        scanf("%d", &numero1);
                        printf("Digite el segundo número: ");
                        scanf("%d", &numero2);
                        printf("El producto de la multiplicación es: %d\n", multiplicar(numero1, numero2));
                        esperar_enter();
                        break;
                    }
                    case 4: {
                        /*OPERACION DE DIVISION*/
                        limpiar_consola();
                        int numero1, numero2;
                        printf("CALCULADORA: División\n\n");
                        printf("Digite el primer número (dividendo): ");
                        scanf("%d", &numero1);
                        printf("Digite el segundo número (divisor): ");
                        scanf("%d", &numero2);
                        if (numero2 == 0){
                            printf("Error: No se puede dividir un número entre cero.\n");
                            esperar_enter();
                            break; //vuelve al menu
                        }
                        printf("El cociente de la división es: %.2f\n", dividir(numero1, numero2));
                        esperar_enter();
                        break;
                    }
                    case 5:
                        break;
                    }
            }while(opcion_aritmetica != 5); //5 es volver al menu principal
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
    }
    

    return 0;
}