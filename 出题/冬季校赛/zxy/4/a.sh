#/bin/bash
g++ gen.cpp -o gen.exe
g++ main.cpp -o main.exe
time ./gen.exe > test.in
time ./main.exe < test.in