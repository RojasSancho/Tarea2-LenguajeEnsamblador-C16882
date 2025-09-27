#ifndef OPERACIONES_SISTEMAS_NUMERICOS_H
#define OPERACIONES_SISTEMAS_NUMERICOS_H

// --- Operaciones con Sistemas Numericos ---
//Hacia decimal
int binario_a_decimal(const char *binario);
int octal_a_decimal(const char *octal);
int hexadecimal_a_decimal(const char *hexadecimal);

//Desde decimal
void decimal_a_binario(int decimal, char *resultado);
void decimal_a_octal(int decimal, char *resultado);
void decimal_a_hexadecimal(int decimal, char *resultado);

#endif