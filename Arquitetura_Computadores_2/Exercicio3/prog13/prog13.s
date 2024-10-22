.text
.globl _start
_start:
la $t0, x
lw $t1, 0($t0)

la $t2, z
lw $t3, 0($t2)

mul $t5, $t1, 127
mul $t6, $t3, -65

add $t7, $t6, $t5
add $t7, $t7, 1

la $t8, y
sw $t7, 0($t8)


.data
x: .word 5
z: .word 7
y: .word 0  # esse valor deverá ser sobrescrito após a execução do programa 