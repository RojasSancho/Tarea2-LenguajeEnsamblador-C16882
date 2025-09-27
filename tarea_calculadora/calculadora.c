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

    opcion_op_aritmetica = leer_entero("\nDigite el número de su elección: ");

    return opcion_op_aritmetica;
}

int pedir_base_numerica(){
    int base_numerica;
    printf("");
    printf("Binario: Digite 2\n");
    printf("Octal: Digite 8\n");
    printf("Decimal: Digite 10\n");
    printf("Hexadecimal: Digite 16\n");
    
    base_numerica = leer_entero("Digite el número para elegir la base en la que viene el número a convertir: ");

    return base_numerica;
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

// --- Operaciones Sistemas numericos ---

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
                int numero1, numero2;
                /*OPERACIONES ARITMETICAS*/
                opcion_aritmetica = pedir_op_aritmetica();
                switch(opcion_aritmetica){
                    case 1:{
                        /*OPERACION DE SUMA*/
                        limpiar_consola();
                        printf("CALCULADORA: Suma\n\n");
                        numero1 = leer_entero("Digite el primer número: ");
                        numero2 = leer_entero("Digite el segundo número: ");
                        printf("El resultado de la suma es: %d\n", sumar(numero1, numero2));
                        esperar_enter();
                        break;
                    }
                    case 2: {
                        /*OPERACION DE RESTA*/
                        limpiar_consola();
                        printf("CALCULADORA: Resta\n\n");
                        numero1 = leer_entero("Digite el primer número (minuendo): ");
                        numero2 = leer_entero("Digite el segundo número (sustraendo): ");
                        printf("El resultado de la resta es: %d\n", restar(numero1, numero2));
                        esperar_enter();
                        break;
                    }
                    case 3: {
                        /*OPERACION DE MULTIPLICACION*/
                        limpiar_consola();
                        printf("CALCULADORA: Multiplicación\n\n");
                        numero1 = leer_entero("Digite el primer número: ");
                        numero2 = leer_entero("Digite el segundo número: ");
                        printf("El producto de la multiplicación es: %d\n", multiplicar(numero1, numero2));
                        esperar_enter();
                        break;
                    }
                    case 4: {
                        /*OPERACION DE DIVISION*/
                        limpiar_consola();
                        printf("CALCULADORA: División\n\n");
                        numero1 = leer_entero("Digite el primer número (dividendo): ");
                        numero2 = leer_entero("Digite el segundo número (divisor): ");
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
    

    return 0;
}