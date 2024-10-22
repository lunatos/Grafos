.data
A: .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

.text
.globl _start
_start:
li t0, 0

loop:
li t1, 10
bge t0, t1, end

slli t2, t0, 2
la t3, A
add t2, t3, t2
lw t4, 0(t2)

andi t5, t0, 1
beq t5, zero, even

odd:
slli t4, t4, 1
sw t4, 0(t2)
addi t0, t0, 1
j loop

even:
addi t5, t0, 1
slli t5, t5, 2
add t5, t3, t5
lw t6, 0(t5)

add t4, t4, t6
sw t4, 0(t2)
addi t0, t0, 1
j loop

end:
nop