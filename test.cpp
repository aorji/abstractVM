#include <iostream>
#include <string>
#include <regex>
int main(){
std::regex("S := INSTR [SEP INSTR]* #
2
3 INSTR :=
4 push VALUE
5 | pop
6 | dump
7 | assert VALUE
8 | add
9 | sub
10 | mul
11 | div
12 | mod
13 | print
14 | exit
15
16 VALUE :=
17 int8(N)
18 | int16(N)
19 | int32(N)
20 | float(Z)
21 | double(Z)
22
23 N := [-]?[0..9]+
24
25 Z := [-]?[0..9]+.[0..9]+
26
27 SEP := '\n'+")
}

