.section .data
output: .ascii  "Hello world  \n"
.section .text
.globl _start
_start:

movq $4, %rax
movq $1, %rbx
movq $output, %rcx
movq $11, %rdx
int $0x80
