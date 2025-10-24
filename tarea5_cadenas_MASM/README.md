# Tarea 5 - Copia y transformación de cadenas

## Estudiante: Hermes Josué Rojas Sancho

Número de carné: C16882

### Entorno de compilación

- Sistema operativo: Windows 11 (64 bits)
- Ensamblador: MASM
- Editor/IDE: Visual Studio 2022 (usando x86)

> Nota: Se recomienda usar este mismo entorno para evitar problemas de compilación.

### Descripción

Programa de consola (CLI) hecho con lenguaje ensamblador MASM, que permite:

- Copiar una cadena de caracteres de origen a una cadena de destino invirtiendo el orden de los caracteres.

### Estructura de archivos

tarea5_cadenas_MASM/

    tarea5_cadenas_MASM.asm # Codigo fuente en ensamblador MASM
    bonus_tarea5_cadenas_MASM.asm # Enunciado BONUS / Codigo fuente en ensamblador MASM

    ensamblar.bat  # Script para ensamblar, linkear y ejecutar
    ensamblar_bonus.bat # Script para ensamblar, linkear y ejecutar
    
    deps/   # Dependencias del proyecto
        *.inc
        *.lib
        

### Instrucciones de compilación

1. Abrir la terminal o consola.
2. Ubicarse en la carpeta en la cual se encuentra el archivo llamado `ensamblar.bat`.
3. Ejecutar el comando:

```
.\ensamblar.bat
```

> Esto ensambla el archivo `.asm` y linkea las dependencias `.lib` y `.inc` que están dentro de `deps/`. Luego ejecuta el programa `(tarea5_cadenas_MASM.exe)` automáticamente.

## Enunciado Bonus (opcional)

### Descripción (Bonus)

Programa de consola (CLI) hecho con lenguaje ensamblador MASM, que permite:

- Copiar una cadena de caracteres de origen a una cadena de destino invirtiendo el orden de los caracteres.
- Además, identificar si cada letra de la cadena es minúscula o mayúscula y convertirla en su inversa (utilizando procesamiento condicional).

### Instrucciones de compilación (Bonus)

1. Abrir la terminal o consola.
2. Ubicarse en la carpeta en la cual se encuentra el archivo llamado `ensamblar_bonus.bat`.
3. Ejecutar el comando:

```
.\ensamblar_bonus.bat
```

> Esto ensambla el archivo `.asm` y linkea las dependencias `.lib` y `.inc` que están dentro de `deps/`. Luego ejecuta el programa `(bonus_tarea5_cadenas_MASM.exe)` automáticamente.
