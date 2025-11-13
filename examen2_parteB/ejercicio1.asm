; ==========================================================================================
; Universidad de Costa Rica
; Curso: Lenguaje Ensamblador
; Examen 2 - PARTE B 
;
; Problema 1. Controlador de cursor simple
; Programa en lenguaje ensamblador (DOS,8086) que permite al usuario mover un caracter
; asterisco ('*') por la pantalla utilizando las teclas WASD y cambiar su color al presionar
; la tecla con la letra 'c'. El programa se finaliza el presionar ESC.  
;
; Autores: Hermes Rojas Sancho, Donifer Campos Parra y Jose Ignacio Goldoni 
; ==========================================================================================

; Modelo de memoria SMALL y pila de 256 bytes para llamadas y operaciones temporales
.MODEL SMALL
.STACK 100h

; --- Seccion de declaracion de variables del programa ---
.DATA
    fila            DB 12               ; Guarda fila actual del caracter '*' (inicia en el centro de la pantalla)
    columna         DB 40               ; Guarda la columna actual del caracter '*' (inicia en el centro de la pantalla)      
    filaAnterior    DB 12               ; Guarda fila anterior del caracter (para borrar rastro)
    columnaAnterior DB 40               ; Guarda columna anterior del caracter (para borrar rastro)
    color           DB 0Fh              ; Color del caracter (inicia con texto blanco sobre fondo negro) 
    asteriscoChar   DB '*'              ; Caracter o simbolo a mostrar en pantalla    
    
.CODE
MAIN PROC
    mov ax, @data                       ; Carga la direccion del segmento de datos en AX 
    mov ds, ax                          ; Registro DS listo para acceder las variables definidas
    
    ; --- Establecer el modo de video texto 80x25 ---
    mov ah, 00h                         ; Funcion 00h de INT 10h (modo de video)
    mov al, 03h                         ; Modo 03h (texto a color, 80x25)
    int 10h                             ; Llamada a interrupcion de video del BIOS    
    
    ; --- Inicializar la posicion del cursor en el centro de la pantalla --- 
    mov ah, 02h                         ; Funcion 02h de INT 10h (posicionar cursor)  
    mov bh, 0                           ; Numero de pagina de video (0)
    mov dh, fila                        ; Fila inicial del cursor (12)
    mov dl, columna                     ; Columna inicial del cursor (40)  
    int 10h                             ; Llamada a interrupcion BIOS para mover el cursor a la posicion inicial  
    
    ; --- Mostrar el asterisco en la posicion inicial con el color actual ---
    mov ah, 09h                         ; Funcion 09h de INT 10h (mostrar caracter con atributo)   
    mov al, asteriscoChar               ; Caracter a mostrar ('*')
    mov bh, 0                           ; Numero de pagina de video (0) 
    mov bl, color                       ; Color inicial (texto blanco sobre fondo negro)
    mov cx, 1                           ; Numero de repeticiones (1 caracter)
    int 10h                             ; Llamada al BIOS para escribir el caracter en pantalla (posicion inicial)       
        
    buclePrincipal:
        ; --- Verificar si hay una tecla presionada sin esperar a que se pulse ENTER ---
        mov ah, 01h                     ; Funcion 01h de INT 16h (comprobar si hay tecla disponible)
        int 16h                         ; Llamada a interrupcion del BIOS que revisa el buffer del teclado
        jz buclePrincipal               ; Si no hay tecla, volver a iniciar el bucle (zero flag = 1) 
        
        ; --- Leer la tecla presionada (sin eco en pantalla) ---
        mov ah, 00h                     ; Funcion 00h de INT 16h (leer tecla desde el buffer)
        int 16h                         ; Llamada a interrupcion del BIOS para leer tecla
                                        ; (se almacena codigo ASCII en registro AL y codigo de escaneo en registro AH)
        
        ; --- Comprobar si ESC fue presionada (salir del programa) --- 
        cmp al, 27                      ; Comparar con la tecla ESC (ASCII 27)
        je salir                        ; Si es ESC, saltar a la rutina de salida
        
        ; --- Comprobar si tecla 'C' o 'c' fue presionada para cambio de color de caracter ---
        cmp al, 'C'                     ; Comparar con el caracter C mayuscula (ASCII 67) 
        je cambiarColor                 ; Si coincide, saltar a rutina para cambiar color
        cmp al, 'c'                     ; Comparar con el caracter c minuscula (ASCII 99)
        je cambiarColor                 ; Si coincide, saltar a rutina para cambiar color 
        
        ; --- Verificar si una tecla de direccion fue presionada --- 
        ; ((se implementa utilizando las teclas WASD para la direccion)  
        
        ; tecla 'W' o 'w' = Mover arriba
        cmp al, 87                      ; W mayuscula (ASCII 87) 
        je moverArriba
        cmp al, 119                     ; w minuscula (ASCII 119)
        je moverArriba 
        
        ; tecla 'S' o 's' = Mover abajo
        cmp al, 83                      ; S mayuscula (ASCII 83) 
        je moverAbajo
        cmp al, 115                     ; s minuscula (ASCII 115)
        je moverAbajo
        
        ; tecla 'A' o 'a' = Mover izquierda
        cmp al, 65                      ; A mayuscula (ASCII 65) 
        je moverIzquierda
        cmp al, 97                      ; a minuscula (ASCII 97)
        je moverIzquierda 
        
        ; tecla 'D' o 'd' = Mover derecha
        cmp al, 68                      ; D mayuscula (ASCII 68) 
        je moverDerecha
        cmp al, 100                     ; d minuscula (ASCII 100)
        je moverDerecha
        
        jmp buclePrincipal              ; Si no coincide con ninguna, repetir el bucle  

    ; --- Mover hacia arriba ---
    moverArriba:
        mov al, fila
        mov filaAnterior, al
        mov al, columna
        mov columnaAnterior, al
        cmp fila, 0                     ; Verifica si ya esta en el borde superior de la pantalla
        je buclePrincipal               ; Si ya esta en la fila de mas arriba visible no se mueve mas
        dec fila                        ; Resta 1 a la fila (sube una linea)
        jmp actualizarPosicion          ; Actualizar pantalla con nueva posicion del asterisco
    
    ; --- Mover hacia abajo ---
    moverAbajo:
        mov al, fila
        mov filaAnterior, al
        mov al, columna
        mov columnaAnterior, al
        cmp fila, 24                    ; Verifica si ya esta en el borde inferior de la pantalla
        je buclePrincipal               ; Si ya esta en la fila de mas abajo visible no se mueve mas
        inc fila                        ; Suma 1 a la fila (baja una linea)
        jmp actualizarPosicion
    
    ; --- Mover hacia la izquierda ---
    moverIzquierda:
        mov al, fila
        mov filaAnterior, al
        mov al, columna
        mov columnaAnterior, al         ; Mover columna actual de registro AL a variable de columnaAnterior
        cmp columna, 0                  ; Verifica si ya esta en el borde izquierdo de la pantalla
        je buclePrincipal               ; Si ya esta en la columna de mas a la izquierda visible no se mueve mas
        dec columna                     ; Resta 1 a la columna (se mueve a la izquierda)
        jmp actualizarPosicion
    
    ; --- Mover hacia la derecha ---
    moverDerecha:
        mov al, fila
        mov filaAnterior, al
        mov al, columna
        mov columnaAnterior, al         ; Mover columna actual de registro AL a variable de columnaAnterior
        cmp columna, 79                 ; Verifica si ya esta en el borde derecho de la pantalla
        je buclePrincipal               ; Si ya esta en la columna de mas a la derecha visible no se mueve mas
        inc columna                     ; Suma 1 a la columna (se mueve a la derecha)
        jmp actualizarPosicion
    
    ; --- Actualizar la posicion del asterisco en pantalla (borrar anterior y escribir el nuevo) ---
    actualizarPosicion:
        ; Borrar el asterisco anterior (evitar rastro)
        mov ah, 02h                     ; Funcion 02h de INT 10h (posicionar cursor)
        mov bh, 0                       ; Pagina de video 0
        mov dh, filaAnterior            ; Fila anterior
        mov dl, columnaAnterior         ; Columna anterior
        int 10h                         ; Llamada a interrupcion BIOS para mover el cursor a la posicion anterior
    
        mov ah, 09h                     ; Funcion 09h de INT 10h (mostrar caracter con atributo)
        mov al, ' '                     ; Caracter espacio (para poder borrar)
        mov bh, 0                       ; Pagina de video 0
        mov bl, color                   ; Color actual (se mantiene)
        mov cx, 1                       ; Escribir solo 1 caracter
        int 10h                         ; Llamada a interrupcion BIOS para escribir el espacio para borrar
    
        ; Dibujar el nuevo asterisco en la posicion actual
        mov ah, 02h                     ; Funcion 02h de INT 10h (posicionar cursor)
        mov bh, 0
        mov dh, fila                    ; Nueva fila
        mov dl, columna                 ; Nueva columna
        int 10h                         ; Llamada a interrupcion BIOS para mover el cursor a la nueva posicion
    
        mov ah, 09h                     ; Funcion 09h de INT 10h (mostrar caracter con atributo)
        mov al, asteriscoChar           ; Dibujar el asterisco
        mov bh, 0
        mov bl, color                   ; Color actual (puede haber cambiado)
        mov cx, 1
        int 10h                         ; Llamada a interrupcion BIOS para escribir el asterisco en pantalla
    
        jmp buclePrincipal              ; Regresar al bucle principal     

    ; --- Cambiar color ---
    cambiarColor:
        inc color                       ; aumenta el color
        cmp color, 0Fh                  ; si supera el blanco (15)
        jbe continuarColor
        mov color, 1                    ; reinicia al primer color 
    continuarColor: 
        ; --- Redibujar el asterisco con el nuevo color ---
        ; Posicionar cursor en posicion actual
        mov ah, 02h
        mov bh, 0
        mov dh, fila
        mov dl, columna
        int 10h
            
        ; Escribir el asterisco con el nuevo color
        mov ah, 09h
        mov al, asteriscoChar
        mov bh, 0
        mov bl, color
        mov cx, 1
        int 10h
    
        jmp buclePrincipal        

    
    ; --- Salir del programa (tecla ESC) ---
    salir:
        mov ax, 4C00h                   ; funcion DOS para terminar programa
        int 21h  
        
MAIN ENDP
END MAIN    