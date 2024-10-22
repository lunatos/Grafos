.text
.globl _start
_start:
lw $s0, x
lw $s1, i
 
loop:

beq $s0, $s1, end

addi $s0, $s0, 1

j loop

end:
li $v0, 10
syscall

.data
x: .word 0
i: .word 8