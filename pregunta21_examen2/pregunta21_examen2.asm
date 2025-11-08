INCLUDE deps\Irvine32.inc
INCLUDELIB deps\Irvine32.lib

.data
msg1 BYTE "El programa va a esperar hasta que se oprima la tecla CTRL...",0
msg2 BYTE "Se ha presionado CTRL, programa terminado.",0

.code
main PROC
    mov edx, OFFSET msg1
    call WriteString
    call Crlf

; RESPUESTA PREGUNTA 21 - SECCION 1
espera:
    mov ah,12h        ; obtener las banderas del teclado
    int 16h           ; interrupcion de BIOS para teclado
    test al,04h       ; verificar si se ha oprimido cualquier tecla CTRL
    jz espera         ; si no se ha oprimido, repetir el ciclo

    mov edx, OFFSET msg2
    call WriteString
    call Crlf

    exit
main ENDP
END main
