#include <stdio.h>

int main(void) {
    
    int numero1 = 0;
    int numero2 = 0;

    printf("Por favor, ingrese el primer numero: ");
    scanf("%d", &numero1);
    printf("Por favor, ingrese el segundo numero: ");
    scanf("%d", &numero2);

    int resultado = numero1 + numero2;
    
    printf("%d\n", resultado);

    return 0;
}