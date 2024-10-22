.text
.globl _start
_start:
    li $s0, 10

    li $t0, 10
    beq $s0, $t0, case_10

    li $t1, 25
    beq $s0, $t1, case_25

    j default_case

case_10:
    li $s1, 10
    j end_switch

case_25:
    li $s1, 25
    j end_switch

default_case:
    li $s1, 0

end_switch:
    li $v0, 10
    syscall