#/bin/bash
g++ Main.cpp -o Main -fno-asm -O2 -fmax-errors=10 -std=c++17 -Wall -lm --static -DONLINE_JUDGE
# ./Main
echo $0
echo $1
echo $#