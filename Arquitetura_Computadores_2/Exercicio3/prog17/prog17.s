.data
x: .word 2
result: .word 0

.text
.globl _start
_start:
lw $t0, x

beq $t0, 17, case1
beq $t0, 22, case2
beq $t0, 33, case3
j default_case

case1:
li $t2, 25
sw $t2, result
j end

case2:
li $t2, 56
sw $t2, result
j end

case3:
li $t2, 39
sw $t2, result
j end

default_case:
li $t2, 1
sw $t2, result
j end

end:
li $v0, 10
syscall 