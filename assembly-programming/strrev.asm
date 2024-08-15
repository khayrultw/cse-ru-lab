.model huge
.stack 100h
.data
    str db 100 dup(?)
    revstr db 100 dup(?)
    inMsg db 'Enter: $'

.code
    MAIN proc
        mov ax, @DATA
        mov ds, ax 
         
        lea si, str
        call ReadStr  
        
        lea si, str
        mov ax, '$'
        push ax
        BEGIN:
        cmp [si], '$'
        jz REV
        push [si]
        inc si 
        jmp BEGIN
        
        REV:
        lea si, revstr
        HEI:
        pop dx
        mov [si], dl 
        cmp dl, '$'
        jz NEXT
        inc si
        jmp HEI
               
               
        NEXT:
        mov ah, 09h
        lea dx, revstr  
        int 21h
        call NewLine
        
        mov ah, 4ch
        int 21h
        
    MAIN endp
    
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
       
end MAIN