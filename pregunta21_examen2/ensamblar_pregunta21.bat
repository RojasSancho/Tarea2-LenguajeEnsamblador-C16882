@echo off
:: Borrar compilación anterior si existe
if exist pregunta21_examen2.exe del pregunta21_examen2.exe
if exist pregunta21_examen2.obj del pregunta21_examen2.obj
    
:: Variables del proyecto
set SRC=pregunta21_examen2.asm
set OBJ=pregunta21_examen2.obj
set EXE=pregunta21_examen2.exe

:: Ensamblar
ml /c /coff %SRC% 
if %errorlevel% neq 0 (
    echo Error en el ensamblado.
    pause
    exit /b
)

:: Linkear con las dependencias
link /subsystem:console %OBJ% deps\Irvine32.lib deps\kernel32.lib deps\user32.lib
if %errorlevel% neq 0 (
    echo Error en el linkeo.
    pause
    exit /b
)

:: Ejecutar el programa
%EXE%

pause