@echo off
:: Borra compilación anterior si existe
if exist calculadora.exe del calculadora.exe

:: Compila el código
gcc src\main.c src\calculadora.c src\utilidades.c src\operaciones_aritmeticas.c src\menus.c -o calculadora.exe
if %errorlevel% neq 0 (
    echo Hubo un error de compilacion
    pause
    exit /b
)

:: Ejecuta el programa
calculadora.exe

pause