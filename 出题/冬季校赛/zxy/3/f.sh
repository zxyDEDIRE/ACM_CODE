#/bin/bash
g++ main.cpp -o main
g++ main_1.cpp -o main_1
./main    < ./data/1.in > AC.out
./main_1  < ./data/1.in > WA.out
diff  AC.out WA.out
