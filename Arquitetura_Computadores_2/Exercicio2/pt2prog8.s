ori x8, x0, 0x01
slli x8, x8, 1
ori x8, x8, 0x01
slli x8, x8, 2
ori x8, x8, 0x03
slli x8, x8, 4
ori x8, x8, 0x0F
slli x8, x8, 8
ori x8, x8, 0xFF
slli x5, x8, 16
or x8, x8, x5
nop