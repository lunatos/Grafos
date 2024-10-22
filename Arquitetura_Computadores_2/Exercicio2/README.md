Escrever programas em risc-v utilizando apenas comandos basicos:
li, add, sub, and, or, xor, slli, srli

PARTE 1
# Programa 1
a = 2;
b = 3;
c = 4;
d = 5;
x = (a+b)-(c+d);
y = a-b+x;
b = x-y;
# Programa 2
x=1;
y=5-x+15;
# Programa 3
x=3;
y=4;
z=(15-x)+(67-y)+4;

PARTE 2
# Programa 4
x=1;
y=5*x+15;
# Programa 5
x=3;
y=4;
z=((15*x)+(67*y))*4;
# Programa 6
# ATENÇÃO: Use os shifts para gerar os valores muito grandes
x = 1048576; // 2 a 20
y = 4096; // 2 a 12
z = x + y;
# Programa 7
x = o maior inteiro possível; // Ou seja, uma palavra de 32 bits com todos os bits igual a 1
y = 8192;
z = x - 4y;
# Programa 8
# Considere a seguinte instrução iniciando um programa:
ori x8, x0, 0x01
# Usando apenas instruções lógicas e instruções de deslocamento, continue o programa de forma que ao final, tenhamos o seguinte conteúdo no registrador x8:
x8 = 0xFFFFFFFF
# Programa 9
# Inicialmente escreva um programa que faça:
x8 = 0x12345678.
# A partir do registrador x8 acima, usando apenas instruções lógicas (or, ori, and, andi, xor, xori) e instruções de deslocamento (sll, srl e sra),
# você deverá obter os seguintes valores nos respectivos registradores:
x9 = 0x12
x10 = 0x34
x11 = 0x56
x12 = 0x78