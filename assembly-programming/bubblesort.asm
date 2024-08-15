.model huge
.stack 100h
.data
    str db 100 dup(?)
    inMsg db 'Enter: $'
    
.code
    MAIN proc
        mov ax, @DATA
        mov ds, ax
        
        lea si, str
        call ReadStr
        mov bl, 1
        SORTBEGIN:
        mov bl, 0
        lea si, str
        INNERLOOP:
        mov dl,[si]
        inc si
        mov cl, [si]
        cmp cl, '$'
        jz NEXT
        cmp dl, cl
        jle INNERLOOP
        mov [si],dl
        mov [si-1], cl
        mov bl, 1
        NEXT:
        cmp bl, 1
        jz SORTBEGIN
        
        
        lea dx, str
        mov ah, 09h
        int 21h
        
        mov ah, 4ch
        int 21h
        
    NewLine proc
        mov ah, 02h
        mov dl, 0dh
        int 21h
        mov dl, 0ah
        int 21h
        ret
    NewLine endp
    
    ReadStr proc 
        lea dx, inMsg
        mov ah, 09h
        int 21h
        READBEGIN: 
        mov ah, 01h
        int 21h
        cmp al, 0dh
        jz READEND
        mov [si], al
        inc si
        jmp READBEGIN
        READEND:
        mov [si], '$'  
        call NewLine
        ret
    ReadStr endp
