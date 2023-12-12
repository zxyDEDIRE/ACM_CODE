#include<bits/stdc++.h>
using namespace std;
int cases;

int main(){
    system("g++ main.cpp -o main");
    system("g++ main_1.cpp -o main_1");
    system("g++ gen.cpp -o gen");
    while(1){
        printf("The result of No. %d Case is:  ",++cases);
        system("./gen 5 10 4 1 > a.in");
        system("./main < a.in > AC.out");
        system("./main_1 < a.in > WA.out");
        if(system("diff AC.out WA.out")){
            puts("Wrong Answer\n");
            return 0;
        }
        puts("Accepted");
        // exit(0);
    }
    return 0;
}