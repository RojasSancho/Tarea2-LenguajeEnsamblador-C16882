@echo off
:: Borrar compilación anterior si existe
if exist calculadora.exe del calculadora.exe

:: Compilar el código y busca los headers
gcc -Iinclude src\main.c src\utilidades.c src\operaciones_aritmeticas.c src\operaciones_sistemas_numericos.c src\operaciones_complemento.c src\menus.c src\calculadora.c -o calculadora.exe
if %errorlevel% neq 0 (
    echo Hubo un error de compilacion
    pause
    exit /b
)

:: Ejecutar el programa
calculadora.exe

pause