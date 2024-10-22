.data
x: .word 3
y: .word 6
m: .word 0

.text
.globl _start
_start:
lw $t0, x
lw $t1, y

la $t2, m

bgt $t0, $t1, assing_great
sw $t0, 0($t2)


assing_great:
sw $t1, 0($t2)

end:
li $v0, 10
syscall