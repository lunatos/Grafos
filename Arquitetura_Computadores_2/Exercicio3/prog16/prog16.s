.text
.globl _start
_start:
    lw $t0, a
    lw $t1, b

    li $t2, 0
    sw $t2, x 

    bltz $t0, end_if

    li $t3, 50
    bgt $t1, $t3, end_if

    li $t2, 1
    sw $t2, x

end_if:
    li $v0, 10
    syscall
    
.data
a: .word 5
b: .word 7
x: .word 0