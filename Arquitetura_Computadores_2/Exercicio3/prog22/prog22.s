.data
result: .word 0

.text
.globl _start
_start:
li t0, 1
li t1, 1 
li t2, 2 
li t3, 9

loop:
beq t2, t3, done

add t4, t0, t1

mv t0, t1
mv t1, t4

addi t2, t2, 1

j loop

done:
sw t1, result 

li a7, 10
ecall