#include <iostream>
#include <cmath>
#include <string.h>
#include<bits/stdc++.h>
using namespace std;
int prime[1000000], isPrime[1000000];
void shai() { //线性筛法 
    int i, j, num = 0;
    for(i = 2; i < 1000000; i++) {
        if(isPrime[i])
            prime[num++] = i;
        for(j = 0; j < num && i * prime[j] < 1000000; j++) {
            isPrime[i * prime[j]] = 0;
            if(i % prime[j] == 0) break;
        }
    }
}
bool cmp(int a,int b)
{
    return a>b;
}
int main() {
    int p[]={0,3,6,3,5,3,2};
    sort(p+1,p+7,cmp);
    for(int i=1;i<=6;i++)
        cout<<p[i]<<" ";
    /*
    int i, j, k, t, temp = 0;
    memset(prime, 0, sizeof(prime)); //存储素数 
    memset(isPrime, 1, sizeof(isPrime));  //1代表是素数 0代表不是素数 
    shai();
    for (i = 0; i < 1000000; i++) {
        t = prime[i];
        for (j = 1; j < 100000; j++) { //从1到100000，枚举公差j
            for (k = 1; k < 10; k++) { //k为序列的数的个数
                if (isPrime[t+j*k] == 0)
                    break;
            }
            if (k == 10) { //当满足k为10时，返回最小公差j即可
                cout << j;
                return 0;
            }
        }
    }
    return 0;
    */
    
}