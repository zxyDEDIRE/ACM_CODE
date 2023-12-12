// #include "testlib.h"
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// main 需要接收命令行参数
using ll=long long;
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

    ll  T=getRand(1e9,1e11);
    vector<ll>pr;
    for(int i=1;1ll*i*i<=T;i++){
        if(T%i==0){
            pr.push_back(i);
            if(T/i!=i){
                pr.push_back(T/i);
            }
        }
    }
    ll n=(ll)pr.size();
    cout<<n<<'\n';
    for(auto v:pr){
        cout<<v<<'\n';
    }


    return 0;
}
/*
gen.exe 10
gen.exe 1000000

*/