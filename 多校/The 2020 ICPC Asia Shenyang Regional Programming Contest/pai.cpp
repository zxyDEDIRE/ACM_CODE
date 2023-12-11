    #include<bits/stdc++.h>
    using namespace std;
    int cases;

    int main(){
        system("g++ D.cpp -o AC.exe");
        system("g++ D_1.cpp -o WA.exe");
        for(int i=1;i<=1;i++){
            printf("The result of No. %d Case is:  ",i);
            system("echo  33 > a.in");
            system("./AC.exe < a.in > AC.out");
            system("./WA.exe < a.in > WA.out");
            if(system("diff AC.out WA.out")){
                puts("Wrong Answer\n");
                return 0;
            }
            puts("Accepted");
        }
        return 0;
    }