li s0, 1 #A
li s1, 5 #B
#verificando o primeiro bit do resultado C(0) vamos considerar multiplicar 4 bits
#pega o primeiro bit do multiplicador
andi t0, s1, 1
#pega os bits do multiplicando vamos deixar constantes esses valores
#os shifts são para deixar os valores como 0 ou 1 para realizarmos os ands
andi t1, s0, 1
andi t2, s0, 2 
srli t2, t2, 1
andi t3, s0, 4 
srli t3, t3, 2
andi t4, s0, 8 
srli t4, t4, 3
#descobrimos o P0
and t5, t0, t1
and t6, t0, t2
slli t6, t6, 1
add t5, t5, t6
and t6, t0, t3
slli t6, t6, 2
add t5, t5, t6
and t6, t0, t4
slli t6, t6, 3
add t5, t5, t6
#adicionamos ao resultado da multiplicação sem shift pois era o P0
addi s2, t5, 0

#verificando o segundo bit do resultado C(1)
#pega o segundo bit do multiplicador
andi t0, s1, 2
srli t0, t0, 1
#os bits do multiplicando estão armazenados no t4, t3, t2, t1
#descobrimos o P1
and t5, t0, t1
and t6, t0, t2
slli t6, t6, 1
add t5, t5, t6
and t6, t0, t3
slli t6, t6, 2
add t5, t5, t6
and t6, t0, t4
slli t6, t6, 3
add t5, t5, t6
#adicionamos ao resultado da multiplicação com shiftL(1) pois era o P1
slli t5, t5, 1
add s2, s2, t5

#verificando o terceiro bit do resultado C(2)
#pega o terceiro bit do multiplicador
andi t0, s1, 4
srli t0, t0, 2
#descobrimos o P2
and t5, t0, t1
and t6, t0, t2
slli t6, t6, 1
add t5, t5, t6
and t6, t0, t3
slli t6, t6, 2
add t5, t5, t6
and t6, t0, t4
slli t6, t6, 3
add t5, t5, t6
#adicionamos ao resultado da multiplicação com shiftL(2) pois era o P2
slli t5, t5, 2
add s2, s2, t5

#verificando o quarto bit do resultado C(3)
#pega o quarto bit do multiplicador
andi t0, s1, 8
srli t0, t0, 3
#descobrimos o P3
and t5, t0, t1
and t6, t0, t2
slli t6, t6, 1
add t5, t5, t6
and t6, t0, t3
slli t6, t6, 2
add t5, t5, t6
and t6, t0, t4
slli t6, t6, 3
add t5, t5, t6
#adicionamos ao resultado da multiplicação com shiftL(3) pois era o P3
slli t5, t5, 3
add s2, s2, t5

addi s2, s2, 15
nop