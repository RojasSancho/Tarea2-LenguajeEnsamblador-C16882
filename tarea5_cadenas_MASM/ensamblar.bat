@echo off
:: Borra compilación anterior si existe
if exist tarea5_lenguajeensamblador.exe del tarea5_cadenas_MASM.exe
if exist tarea5_lenguajeensamblador.obj del tarea5_cadenas_MASM.obj

:: Variables del proyecto
set SRC=tarea5_cadenas_MASM.asm
set OBJ=tarea5_cadenas_MASM.obj
set EXE=tarea5_cadenas_MASM.exe

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

:: Ejecuta el programa
%EXE%

pause