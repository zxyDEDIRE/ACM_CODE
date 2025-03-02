// #include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());//ull  大概率生成不相同数据
ll getRand(ll l,ll r){
    uniform_int_distribution < ll > uid(l,r);
    return uid(rng);
}

// main 需要接收命令行参数
int main(int argc, char *argv[])
{
    // 初始化 checker 环境 —— 解析命令行参数、打开文件……
    // registerTestlibCmd(argc, argv, 1);
    // registerGen(argc, argv, 1);//初始化数据生成器

    int n=atoi(argv[1]);
    int q=atoi(argv[2]);
    int r=atoi(argv[3]);
    cout<<n<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<getRand(1,r)<<" "<<getRand(1,r)<<endl;
    }
    cout<<q<<endl;
    for(int i=1;i<=q;i++)
    {
        cout<<getRand(1,100)<<" "<<getRand(1,100)<<endl;
    }

    return 0;
}
