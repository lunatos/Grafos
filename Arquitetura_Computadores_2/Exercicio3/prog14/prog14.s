.text
.globl _start
_start:
    la $t0, A                
    la $t1, B                 

    lw $t2, 0($t1)            
    mul $t2, $t2, 1           
    lw $t3, 0($t0)            
    add $t3, $t3, $t2         
    sw $t3, 0($t0)            

    lw $t2, 4($t1)            
    mul $t2, $t2, 2           
    lw $t3, 4($t0)            
    add $t3, $t3, $t2         
    sw $t3, 4($t0)            

    
    lw $t2, 8($t1)
    mul $t2, $t2, 3
    lw $t3, 8($t0)
    add $t3, $t3, $t2
    sw $t3, 8($t0)

    lw $t2, 12($t1)
    mul $t2, $t2, 4
    lw $t3, 12($t0)
    add $t3, $t3, $t2
    sw $t3, 12($t0)

    lw $t2, 16($t1)
    mul $t2, $t2, 5
    lw $t3, 16($t0)
    add $t3, $t3, $t2
    sw $t3, 16($t0)

    li $v0, 10                
    syscall
    
.data
A: .word 1, 3, 5, 7, 9      
B: .word 2, 4, 6, 8, 10