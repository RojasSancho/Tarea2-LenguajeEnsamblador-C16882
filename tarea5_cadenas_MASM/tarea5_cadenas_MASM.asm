INCLUDE deps\Irvine32.inc                       ; incluir WriteString, Crlf, DumpRegs, DumpMem
INCLUDELIB deps\Irvine32.lib                    ; enlazar la biblioteca

.data
    ; cadena original terminada en byte nulo ('\0')
    origen BYTE "Esta es la cadena de origen",0 

    ; reservar espacio en memoria para la cadena invertida
    ; SIZEOF origen devuelve la cantidad de caracteres en la cadena 'origen'
    ; DUP('') rellena SIZEOF origen caracteres con caracteres vacios
    destino BYTE SIZEOF origen DUP(?)

.code
main PROC
    ; inicializacion de registros
    mov esi, OFFSET origen + SIZEOF origen - 2  ; apuntar al ultimo caracter de la cadena origen (antes del byte nulo)      
    mov edi, OFFSET destino                     ; apuntar al inicio de la cadena destino
    mov ecx, LENGTHOF origen - 1                ; establecer el contador de caracteres (ignorando el byte nulo)

reverse_loop:
    cmp ecx, 0
    je end_loop
    mov al, [esi]                               ; cargar el caracter actual desde el final de la cadena origen   
    mov [edi], al                               ; almacenar el caracter en la cadena destino
    dec esi                                     ; retroceder al caracter anterior en la cadena origen
    inc edi                                     ; avanzar al siguiente caracter en la cadena destino
    dec ecx                                     ; decrementar el contador de caracteres
    jmp reverse_loop

end_loop:
    mov byte ptr [edi], 0                       ; finalizar la cadena destino con un byte nulo (0)

    ; parte que se encarga de la impresion de texto en consola
    mov edx, OFFSET destino                     ; cargar en EDX la dirección de 'destino'
    call WriteString                            ; imprimir en consola lo que apunte EDX
    call Crlf                                   ; salto de línea
    call DumpRegs                               ; muestra el contenido de los registros (paradepuración)
    exit          
main ENDP

END main