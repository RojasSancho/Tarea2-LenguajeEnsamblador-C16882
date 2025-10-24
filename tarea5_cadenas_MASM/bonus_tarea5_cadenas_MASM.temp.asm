INCLUDE deps\Irvine32.inc                       ; incluir WriteString, Crlf, DumpRegs, DumpMem
INCLUDELIB deps\Irvine32.lib                    ; enlazar la biblioteca

.data
    ; cadena original terminada en byte nulo ('\0')
    origen BYTE "Esta es la cadena de origen",0 

    ; reservar espacio en memoria para la cadena invertida
    ; SIZEOF origen devuelve la cantidad de caracteres en la cadena 'origen'
    ; DUP(?) rellena SIZEOF origen caracteres con caracteres vacios
    destino BYTE SIZEOF origen DUP(?)

.code
main PROC
    ; inicializacion de registros
    mov esi, OFFSET origen + SIZEOF origen - 2  ; apuntar al ultimo caracter de la cadena origen (antes del byte nulo)      
    mov edi, OFFSET destino                     ; apuntar al inicio de la cadena destino
    mov ecx, LENGTHOF origen - 1                ; numero de caracteres a copiar (ignorando el byte nulo)

reverse_loop:
    mov al, [esi]                               ; cargar el caracter actual del origen

    cmp al, 'A'                                 ; comparar AL con 'A'
    jl copiar_caracter                          ; si el caracter actual es menor que 'A', no es letra
    cmp al, 'Z'                                 ; comparar AL con 'Z'
    jle mayuscula                               ; si es <= 'Z', es mayúscula
    cmp al, 'a'                                 ; comparar AL con 'a'
    jl copiar_caracter                          ; si es menor que 'a', no es letra
    cmp al, 'z'                                 ; comparar AL con 'z'
    jle minuscula                               ; si es <= 'z', es minúscula
    jmp copiar_caracter                         ; no es letra, saltar a copiar_caracter

mayuscula:
    add al, 32                                  ; convertir a minúscula sumando 32
    jmp copiar_caracter                                  

minuscula:
    sub al, 32                                  ; convertir a mayúscula restando 32
    jmp copiar_caracter         

copiar_caracter:
    mov [edi], al                               ; copiarlo a la cadena destino
    dec esi                                     ; retroceder en la cadena origen (ESI)
    inc edi                                     ; avanzar en la cadena destino (EDI)
    loop reverse_loop                           ; repetir hasta que ECX sea 0

    mov BYTE PTR [edi], 0                       ; finalizar la cadena destino con un byte nulo (0)

    ; parte que se encarga de la impresion de texto en consola
    mov edx, OFFSET destino                     ; cargar en EDX la dirección de 'destino'
    call WriteString                            ; imprimir en consola lo que apunte EDX
    call Crlf                                   ; salto de línea
    exit          
main ENDP

END main