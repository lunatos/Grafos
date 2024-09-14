li s10 3 #valor de X
li s11 4 #valor de Y

#vamos começar realizando a primeira parte da multiplicação de Z (15 * X)
li s0, 15 #A
addi s1, s10, 0 #B
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

#vamos armazenar o valor da multiplicação em s3
addi s3, s2, 0


#vamos realizar a segunda multiplicação de Z (67 * Y)
#Como sabemos que Y-3 bits e 67-7 bits, vamos deixar nosso codigo menor para multiplicar esses 2 numeros
addi s0, s11, 0 #A carregamos o valor de Y
li s1, 67 #B
#pega o primeiro bit do multiplicador
andi t0, s1, 1
#pega os bits do multiplicando vamos deixar constantes esses valores
#os shifts são para deixar os valores como 0 ou 1 para realizarmos os ands
andi t1, s0, 1
andi t2, s0, 2 
srli t2, t2, 1
andi t3, s0, 4 
srli t3, t3, 2
#descobrimos o P0
and t4, t0, t1
and t5, t0, t2
slli t5, t5, 1
add t4, t4, t5
and t5, t0, t3
slli t5, t5, 2
add t4, t4, t5
#adicionamos ao resultado da multiplicação sem shift pois era o P0
addi s2, t4, 0

#pega o segundo bit do multiplicador
andi t0, s1, 2
srli t0, t0, 1
#descobrimos o P1
and t4, t0, t1
and t5, t0, t2
slli t5, t5, 1
add t4, t4, t5
and t5, t0, t3
slli t5, t5, 2
add t4, t4, t5
#adicionamos ao resultado da multiplicação shiftL(1) pois era o P1
slli t4, t4, 1
add s2, s2, t4

#pega o terceiro bit do multiplicador
andi t0, s1, 4
srli t0, t0, 2
#descobrimos o P2
and t4, t0, t1
and t5, t0, t2
slli t5, t5, 1
add t4, t4, t5
and t5, t0, t3
slli t5, t5, 2
add t4, t4, t5
#adicionamos ao resultado da multiplicação shiftL(2) pois era o P2
slli t4, t4, 2
add s2, s2, t4

#pega o quarto bit do multiplicador
andi t0, s1, 8
srli t0, t0, 3
#descobrimos o P3
and t4, t0, t1
and t5, t0, t2
slli t5, t5, 1
add t4, t4, t5
and t5, t0, t3
slli t5, t5, 2
add t4, t4, t5
#adicionamos ao resultado da multiplicação shiftL(3) pois era o P3
slli t4, t4, 3
add s2, s2, t4

#pega o quinto bit do multiplicador
andi t0, s1, 16
srli t0, t0, 4
#descobrimos o P4
and t4, t0, t1
and t5, t0, t2
slli t5, t5, 1
add t4, t4, t5
and t5, t0, t3
slli t5, t5, 2
add t4, t4, t5
#adicionamos ao resultado da multiplicação shiftL(4) pois era o P4
slli t4, t4, 4
add s2, s2, t4

#pega o sexto bit do multiplicador
andi t0, s1, 32
srli t0, t0, 5
#descobrimos o P5
and t4, t0, t1
and t5, t0, t2
slli t5, t5, 1
add t4, t4, t5
and t5, t0, t3
slli t5, t5, 2
add t4, t4, t5
#adicionamos ao resultado da multiplicação sem shiftL(5) pois era o P5
slli t4, t4, 5
add s2, s2, t4

#pega o sexto bit do multiplicador
andi t0, s1, 64
srli t0, t0, 6
#descobrimos o P6
and t4, t0, t1
and t5, t0, t2
slli t5, t5, 1
add t4, t4, t5
and t5, t0, t3
slli t5, t5, 2
add t4, t4, t5
#adicionamos ao resultado da multiplicação shiftL(6) pois era o P6
slli t4, t4, 6
add s2, s2, t4

add s3, s3, s2

#vamos realizar a terceira multiplicação de Z (313 * 4)
#Como sabemos que Y-3 bits e 67-7 bits, vamos deixar nosso codigo menor para multiplicar esses 2 numeros
li s0, 4 #A carregamos o valor 4
addi s1, s3, 0 #B carregamos o valor (15 * X)+(67 * Y) que esta armazenado em s3
#pega o primeiro bit do multiplicador
andi t0, s1, 1
#pega os bits do multiplicando vamos deixar constantes esses valores
#os shifts são para deixar os valores como 0 ou 1 para realizarmos os ands
andi t1, s0, 1
andi t2, s0, 2 
srli t2, t2, 1
andi t3, s0, 4 
srli t3, t3, 2
#descobrimos o P0
and t4, t0, t1
and t5, t0, t2
slli t5, t5, 1
add t4, t4, t5
and t5, t0, t3
slli t5, t5, 2
add t4, t4, t5
#adicionamos ao resultado da multiplicação sem shift pois era o P0
addi s2, t4, 0

#pega o segundo bit do multiplicador
andi t0, s1, 2
srli t0, t0, 1
#descobrimos o P1
and t4, t0, t1
and t5, t0, t2
slli t5, t5, 1
add t4, t4, t5
and t5, t0, t3
slli t5, t5, 2
add t4, t4, t5
#adicionamos ao resultado da multiplicação shiftL(1) pois era o P1
slli t4, t4, 1
add s2, s2, t4

#pega o terceiro bit do multiplicador
andi t0, s1, 4
srli t0, t0, 2
#descobrimos o P2
and t4, t0, t1
and t5, t0, t2
slli t5, t5, 1
add t4, t4, t5
and t5, t0, t3
slli t5, t5, 2
add t4, t4, t5
#adicionamos ao resultado da multiplicação shiftL(2) pois era o P2
slli t4, t4, 2
add s2, s2, t4

#pega o quarto bit do multiplicador
andi t0, s1, 8
srli t0, t0, 3
#descobrimos o P3
and t4, t0, t1
and t5, t0, t2
slli t5, t5, 1
add t4, t4, t5
and t5, t0, t3
slli t5, t5, 2
add t4, t4, t5
#adicionamos ao resultado da multiplicação shiftL(3) pois era o P3
slli t4, t4, 3
add s2, s2, t4

#pega o quinto bit do multiplicador
andi t0, s1, 16
srli t0, t0, 4
#descobrimos o P4
and t4, t0, t1
and t5, t0, t2
slli t5, t5, 1
add t4, t4, t5
and t5, t0, t3
slli t5, t5, 2
add t4, t4, t5
#adicionamos ao resultado da multiplicação shiftL(4) pois era o P4
slli t4, t4, 4
add s2, s2, t4

#pega o sexto bit do multiplicador
andi t0, s1, 32
srli t0, t0, 5
#descobrimos o P5
and t4, t0, t1
and t5, t0, t2
slli t5, t5, 1
add t4, t4, t5
and t5, t0, t3
slli t5, t5, 2
add t4, t4, t5
#adicionamos ao resultado da multiplicação sem shiftL(5) pois era o P5
slli t4, t4, 5
add s2, s2, t4

#pega o setimo bit do multiplicador
andi t0, s1, 64
srli t0, t0, 6
#descobrimos o P6
and t4, t0, t1
and t5, t0, t2
slli t5, t5, 1
add t4, t4, t5
and t5, t0, t3
slli t5, t5, 2
add t4, t4, t5
#adicionamos ao resultado da multiplicação shiftL(6) pois era o P6
slli t4, t4, 6
add s2, s2, t4

#pega o oitavo bit do multiplicador
andi t0, s1, 128
srli t0, t0, 7
#descobrimos o P7
and t4, t0, t1
and t5, t0, t2
slli t5, t5, 1
add t4, t4, t5
and t5, t0, t3
slli t5, t5, 2
add t4, t4, t5
#adicionamos ao resultado da multiplicação shiftL(6) pois era o P7
slli t4, t4, 7
add s2, s2, t4

#pega o nono bit do multiplicador
andi t0, s1, 256
srli t0, t0, 8
#descobrimos o P8
and t4, t0, t1
and t5, t0, t2
slli t5, t5, 1
add t4, t4, t5
and t5, t0, t3
slli t5, t5, 2
add t4, t4, t5
#adicionamos ao resultado da multiplicação shiftL(8) pois era o P8
slli t4, t4, 8
add s2, s2, t4

addi s3, s2, 0
nop