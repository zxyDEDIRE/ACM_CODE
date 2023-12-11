// #include "testlib.h"
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// main 需要接收命令行参数
#define int long long
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());   //uint
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());//ull  大概率生成不相同数据
int getRand(int l,int r){
    uniform_int_distribution < int > uid(l,r);
    return uid(rng);
}
signed main(int argc, char *argv[])
{
    // 初始化 checker 环境 —— 解析命令行参数、打开文件……
    // registerTestlibCmd(argc, argv, 1);
    // registerGen(argc, argv, 1);//初始化数据生成器
    long long n = atoll(argv[1]);

    // // printf("%d %d\n", n, n+1);
    // std::cout<<n<<std::endl;
    // while(n--){
    //     int T=1e9+7;
    //     std::cout<<rnd.next(T)<<std::endl;
    // }
    int n=10;
    long long T1=1e18,T2=10,T3=1e9;
    cout<<n<<endl;
    while(n--)
        cout<<getRand(1,T3)<<endl;
    // cout<<getRand(1e9,T1)<<" "<<getRand(1,T2)<<" "<<getRand(10,T3)<<endl;
    // std::cout<<rnd.next(T1)<<" "<<rnd.next(T2)<<" "<<rnd.next(10ll,T3)<<std::endl;
    return 0;
}
/*
gen.exe 10
gen.exe 1000000

*/