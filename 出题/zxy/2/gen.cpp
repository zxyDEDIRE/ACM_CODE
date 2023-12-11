
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
// main 需要接收命令行参数
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());//ull  大概率生成不相同数据
ll getRand(ll l,ll r){
    uniform_int_distribution < ll > uid(l,r);
    return uid(rng);
}
int main(int argc, char *argv[])
{
    // 初始化 checker 环境 —— 解析命令行参数、打开文件……
    // registerTestlibCmd(argc, argv, 1);
    // registerGen(argc, argv, 1);//初始化数据生成器

    int n = atoi(argv[1]);

    // printf("%d %d\n", n, n+1);
    std::cout<<n<<std::endl;
    while(n--){
        int T=1e9+7;
        std::cout<<getRand(1,T)<<std::endl;
    }

    return 0;
}