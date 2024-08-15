                               .model huge

.stack 100h

.data
    InMsg db 'Enter: $'
    Prime db ' is a prime number.$' 
    NotPrime db ' is not a prime number.$'
    InOutNum dw 0h
    tmp dw 0h
    num dw 0h
    str db 255 dup(?)

.code 
    MAIN proc
    mov ax, @DATA
    mov ds, ax

    
    call READ
    mov ax, InOutNum
    mov num, ax
    
    mov cx, 2
    mov bl, 0
    PRIME_TEST: 
    cmp cx, num
    jge STOP_TEST
    mov bl, 1
    mov dx, 0
    mov ax, num
    div cx
    cmp dx, 0
    je STOP_TEST
    mov bl, 0
    inc cx
    jmp PRIME_TEST
    
    STOP_TEST:
    cmp bl, 1
    je NOT_PRIME
    mov ax, num
    mov InOutNum, ax
    call PRINT
    lea dx, Prime
    mov ah, 09h
    int 021h
    jmp FINISH
    
    NOT_PRIME:  
    mov ax, num
    mov InOutNum, ax
    call PRINT
    lea dx, NotPrime
    mov ah, 09h
    int 021h
    
    FINISH:
    call NEW_LINE
    mov ah, 4ch
    int 21h
    MAIN endp
    
    READ proc
        lea dx, InMsg
        mov ah, 09h
        int 21h
        mov InOutNum, 0
        mov ah, 1
        STARTInRead:
        int 21h
        cmp al, 0dh
        jz STOPInRead
        sub al, 48
        mov bl, al 
        mov bh, 0
        mov ax, InOutNum
        mov cx, 10
        mul cx
        add ax, bx
        mov InOutNum, ax
        mov ah, 1
        jmp STARTInRead 
        STOPInRead:
        call NEW_LINE
        ret
    READ endp
    
    PRINT proc  
        mov cx, 10
        lea si, str 
        mov [si], '$'
        inc si
        STARTR:    
        mov ax, InOutNum  
        mov dx, 0
        div cx
        mov bx, dx 
        mov InOutNum, ax
        add dx, 48
        mov [si], dx
        inc si
        cmp InOutNum, 0
        jnz STARTR
        dec si
        STARTP:
        mov dl, [si]
        mov ah, 02h
        int 21h  
        dec si
        cmp [si], '$'
        jnz STARTP
        ret  
    PRINT endp

    
    NEW_LINE proc
        mov ah, 2
        mov dl, 0dh       
        int 21h
        mov dl, 0ah 
        int 21h 
        ret
    NEW_LINE endp
   

end MAIN