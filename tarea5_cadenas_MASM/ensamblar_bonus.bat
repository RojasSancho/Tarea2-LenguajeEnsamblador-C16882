@echo off
:: Borrar compilación anterior si existe
if exist bonus_tarea5_cadenas_MASM.exe del bonus_tarea5_cadenas_MASM.exe
if exist bonus_tarea5_cadenas_MASM.obj del bonus_tarea5_cadenas_MASM.obj
    
:: Variables del proyecto
set SRC=bonus_tarea5_cadenas_MASM.asm
set OBJ=bonus_tarea5_cadenas_MASM.obj
set EXE=bonus_tarea5_cadenas_MASM.exe

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