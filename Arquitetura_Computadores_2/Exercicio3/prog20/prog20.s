.data
A:      .word 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 

.text
.globl main
main:
    li t0, 0

loop:
    li t1, 10
    bge t0, t1, end_loop


    slli t2, t0, 2
    la t3, A
    add t3, t3, t2

    lw t4, 0(t3)
    addi t4, t4, 1

    sw t4, 0(t3)

    addi t0, t0, 1

    j loop

end_loop:
    li a0, 10
    ecall