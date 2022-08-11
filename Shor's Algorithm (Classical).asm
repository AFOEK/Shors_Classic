section .data
    msg_in: db 'Insert a number to factorize: '
    msg_in_len: Equ $-msg_in
section .bss
    N: resb 8
section .text
global _start
_start:
    Mov EAX,4   ;call for sys_write -> ssize_t write(int fd, const void *buff, size_t count)
    Mov EBX,1   ;file descriptor (stdout)
    Mov ECX,msg_in  ;message
    Mov EDX,msg_in_len  ;buffer size
    Int 80h ;sys_call

    Mov EAX,3   ;call for sys_read -> ssize_t read(int fd, void *buf, size_t count)
    Mov EBX,1   ;file descriptor
    Mov ECX,N   ;buffer read
    Mov EDX,8   ;buffer size
    Int 80h ;sys_call

    Push ECX    ;Push ECX value into stack
    Jmp gen_a_val
gen_a_val:


gets_random_num:
    Mov EAX,13  ;call for sys_time -> time_t time(time_t *tloc)
    Xor EBX,EBX ; *tloc=0
    Int 80h     ;sys_call
    Pop EBX     ;Pop stack into EBX
    Cmp EBX,EAX ;Compare EBX and EAX
    
    
_exit:
    Mov EAX,1   ;call for sys_exit -> exit()
    Xor EBX,EBX ;just ensure exit(0)
    Int  80h    ;syscall