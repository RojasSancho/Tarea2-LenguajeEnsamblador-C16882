# Capitulo 1 - Conceptos basicos
Se utiliza Microsoft Macro Assembler 8.0 en este libro
## Compilar y ejecutar algun programa
```
ml /c /coff nombre.asm
link nombre.obj
nombre.exe
```
## Conceptos basicos nuevos
* Un **enlazador** es un programa utilitario que **combina los archivos individuales creados por un ensamblador, en un solo
programa ejecutable.**
* Utilizar OllyDbg para debuggear o depurar
> Ejecutar con permisos de administrador, para evitar problemas
* Existen dos clases de programas
    - Modo de direccionamiento real de 16 bits
    - Modo protegido de 32 bits:  Por lo general son más fáciles de escribir y de comprender que los
programas en modo real.
* Cada una de las instrucciones en lenguaje ensamblador corresponden a una sola instrucción en lenguaje máquina.
* Los lenguajes de alto nivel tienen una relación de uno a varios con el lenguaje ensamblador y el lenguaje máquina.
* El lenguaje ensamblador **no es portable**:  está diseñado para una familia de procesadores específica.
* 
