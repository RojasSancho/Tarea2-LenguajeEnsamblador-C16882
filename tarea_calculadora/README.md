# Calculadora: Operaciones Aritméticas y Conversión Sistemas Numéricos
## Estudiante: Hermes Josué Rojas Sancho

Número de carné: C16882

### Entorno de compilación
- Sistema operativo: Windows 11 (64 bits)
- Compilador: GCC incluido en MinGW
- Editor/IDE: Visual Studio Code

> Nota: Se recomienda usar este mismo entorno para evitar problemas de compilación.

### Descripción
Programa de consola (CLI) que permite:
- Realizar operaciones aritméticas básicas: suma, resta, multiplicación y división.
- Convertir números entre sistemas binario, octal, decimal y hexadecimal.
- Calcular complementos a 1 y 2.

### Estructura de archivos
tarea_calculadora/

    include/      # Archivos .h
    
        *.h
        
    src/          # Archivos .c
    
        *.c
        
    compilar.bat  # Script para compilar y ejecutar

### Instrucciones de compilación
1. Abrir la terminal o consola.
2. Ubicarse en la carpeta en la cual se encuentra el archivo compilar llamado `compilar.bat`.
3. Ejecutar el comando:

```
.\compilar.bat
```
> Esto compila todos los archivos `.c` dentro de `src/` e incluye los `.h` de `include/`. Luego ejecuta el programa automáticamente.

### Uso
- Ingresar los números y la operación según las indicaciones en pantalla.
- Para conversiones, ingresar número y su base.
