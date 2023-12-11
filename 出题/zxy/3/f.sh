#/bin/bash
g++ gen.cpp -o gen
g++ main.cpp -o main
./gen 10 20 5 5 > 1.in
./main < 1.in > 1.out
