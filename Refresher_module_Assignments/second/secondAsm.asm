         global  _add
        
         section .text
 _add:
        mov     rax, rdi                ; result (rax) initially holds x
        add     rax, rsi                ; is x less than y?
        ret                             ; 

