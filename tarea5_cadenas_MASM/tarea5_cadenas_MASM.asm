;.MODEL flat, stdcall
;.STACK 4096

INCLUDE deps\Irvine32.inc    ; incluye WriteString, Crlf, DumpRegs, DumpMem
INCLUDELIB deps\Irvine32.lib ; enlaza la biblioteca

.data
    ; cadena original terminada en byte nulo ('\0')
    origen BYTE "Esta es la cadena de origen",0 

    ; reserva espacio en memoria para la cadena invertida
    ; SIZEOF origen devuelve la cantidad de caracteres en la cadena 'origen'
    ; DUP('') rellena SIZEOF origen caracteres con caracteres vac�os
    destino BYTE SIZEOF origen DUP(?)

.code
main PROC
    mov esi, OFFSET origen + SIZEOF origen - 2 ; apuntar al �ltimo car�cter de la cadena origen (antes del byte nulo)      
    mov edi, OFFSET destino ; apuntar al inicio de la cadena destino
    mov ecx, LENGTHOF origen - 1 ; establecer el contador de caracteres (excluyendo el byte nulo)

reverse_loop:
    cmp ecx, 0
    je end_loop
    mov al, [esi]           ; cargar el car�cter actual desde el final de la cadena origen   
    mov [edi], al           ; almacenar el car�cter en la cadena destino
    dec esi                 ; mover al car�cter anterior en la cadena origen
    inc edi                 ; mover al siguiente car�cter en la cadena destino
    dec ecx                 ; decrementar el contador de caracteres
    jmp reverse_loop

end_loop:
    mov byte ptr [edi], 0   ; agregar el byte nulo al final de la cadena destino
    ; parte que se encarga de la impresi�n
    mov edx, OFFSET destino ; apuntar a la cadena destino
    call WriteString
    call Crlf
    call DumpRegs
    ;call DumpMem
    exit          
main ENDP

END main