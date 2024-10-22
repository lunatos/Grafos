li s0 0
li t0 -1
xor s0, s0, t0 # valor de X

li s1 1 
slli s1 s1 13 # valor de Y

#4Y == Y + Y + Y + Y
add s1 s1 s1 # Y = 2Y
add s1 s1 s1 # Y = 2Y

sub s2 s0 s1

nop