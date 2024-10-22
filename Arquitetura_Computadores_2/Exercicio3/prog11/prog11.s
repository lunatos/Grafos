.text
.globl _start
_start:
    la $t0, x1
    lw $t1, 0($t0)

    la $t2, x2
    lw $t3, 0($t2)

    la $t4, x3
    lw $t5, 0($t4)

    la $t6, x4
    lw $t7, 0($t6)

    li $v0, 10
    syscall

.data
x1: .word 15
x2: .word 25
x3: .word 13
x4: .word 17