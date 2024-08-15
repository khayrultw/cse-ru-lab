.model huge
.stack 100h
.data
    str1 db 100 dup(?)
    str2 db 100 dup(?) 
    len1 db 0
    len2 db 0 
    flag db 0
    inMsg db 'Enter: $'
    outMsg db ' is substring of $' 
    finalMsg db 'They are not subtring of one another.$'
    

.code
    MAIN proc
        mov ax, @DATA
        mov ds, ax 
         
        lea si, str1
        call ReadStr  
        
        lea si, str2 
        call ReadStr
        
        lea si, str1
        call Len
        mov len1, cl
        
        lea si, str2
        call Len
        mov len2, cl
        
        mov al, len1 
        cmp al, len2
        jl TWO
     
        mov si, 0
        dec si
        BEGIN1: 
        inc si   
        mov bx, 0
        cmp str1[si], '$'
        jZ TWO  
        INNER1:
        cmp str2[bx], '$'
        jz FINISH1
        mov dl, str1[si+bx]
        cmp dl, str2[bx]
        jnz BEGIN1
        inc bx
        jmp INNER1
        
        FINISH1:
        lea dx, str2
        mov ah, 09h
        int 21h 
        
        lea dx, outMsg
        mov ah, 09h
        int 21h
        
        lea dx, str1
        mov ah, 09h
        int 21h
                
        jmp EXIT
        
        TWO:
        mov si, 0
        dec si
        BEGIN2:
        inc si   
        mov bx, 0
        cmp str2[si], '$'
        jZ THREE 
        INNER2:
        cmp str1[bx], '$'
        jz FINISH2
        mov dl, str2[si+bx]
        cmp dl, str1[bx]
        jnz BEGIN2
        inc bx
        jmp INNER2
        
        FINISH2:
        lea dx, str1
        mov ah, 09h
        int 21h 
        
        lea dx, outMsg
        mov ah, 09h
        int 21h
        
        lea dx, str2
        mov ah, 09h
        int 21h
        
        jmp EXIT
        
        THREE: 
        lea dx, finalMsg
        mov ah, 09h
        int 21h
        
        EXIT:
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
    
    Len proc  
        mov cl, 0
        BEGINLen:
        cmp [si], '$'
        jz ENDLen
        inc si
        inc cl
        jmp BEGINLen
        ENDLen:
        ret
    Len endp
           
end MAIN
