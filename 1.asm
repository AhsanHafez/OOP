[org 0x0100]

jmp start
message: db 'HELLO WORLD'
length: dw 11

clrscr:
    push ax
    push es
    push si

    mov ax,0xb800
    mov es,ax
    mov si ,0

        loop1:
        mov [es:si],0x0720
        add si,2
        cmp si,4000
        jnz loop1
    
    pop si
    pop es
    pop ax 

ret

printscr:

    push bp
    mov bp,sp

    push ax 
    push si 
    push di
    push es 
    push cx 

    mov cx,[bp-4]
    mov si,[bp+6]
    mov di,0

    mov ah,0x07

        loop2:
        mov al,[si]
        mov [es:di],ax 
        add si,1
        add di,2
        dec cx 
        jnz loop2 

    pop cx 
    pop es 
    pop di 
    pop si 
    pop ax 
    pop bp 

ret 4
start:

call clrscr
push message
push [length]
call printscr

mox ah,0x1
int 0x21

mov ax,0x21
int 0x21