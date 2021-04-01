global _s, checkGreater

section .text

_s:
  mov rdi,10     	;x
  mov rsi,20		;y
  call checkGreater	;calling checkGreater

checkGreater:
  cmp rdi, rsi		; comparing x and y
  jg _greater		;jumpt to _greater if x>y
  jng _else			;else jmp to _else
 
_greater:
	mov rax, 1		;code for write syscall
	mov rdi, 1		
	mov rsi, ifGreater	;printing 1
	mov rdx, leng
	syscall
	mov rax, 60       ; exit(
	mov rdi, 0        ;   EXIT_SUCCESS
	syscall           ; );

_else:
	mov rax, 1
	mov rdi, 1
	mov rsi, else1	;printing 0
	mov rdx, leni
	syscall
    mov rax, 60       ; exit(
    mov rdi, 0        ;   EXIT_SUCCESS
    syscall           ; );
	

section .rodata 
  ifGreater: db "1",10
  leng: equ $-ifGreater
  else1: db "0",10
  leni: equ $-else1

