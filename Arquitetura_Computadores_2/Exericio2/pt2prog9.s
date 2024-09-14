# Inicialmente escreva um programa que faça: x8 = 0x12345678.
ori x8, x0, 0x078
ori x9, x0, 0x056
slli x9, x9, 8
or  x8, x8, x9
ori  x9, x0, 0x034
slli x9, x9, 16
or   x8, x8, x9
ori x9, x0, 0x012
slli x9, x9, 24
or x8, x8, x9

srli x9, x8, 24
srli x10, x8, 16
andi x10, x10, 0xFF
srli x11, x8, 8
andi x11, x11, 0xFF
andi x12, x8, 0xFF
nop