#ifdef _WIN32
#include <windows.h>
#endif

#include "calculadora.h"

// --- Programa principal ---
int main(void) {
    #ifdef _WIN32
    // Configura la consola a UTF-8 en sistemas Windows
    SetConsoleOutputCP(CP_UTF8); 
    #endif

    // Llama al ciclo while con la ejecucion de la calculadora
    ejecutar_calculadora();

    return 0;
}