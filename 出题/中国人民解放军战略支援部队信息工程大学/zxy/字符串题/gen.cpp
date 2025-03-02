// #include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());//ull  大概率生成不相同数据
ll getRand(ll l,ll r){
    uniform_int_distribution < ll > uid(l,r);
    return uid(rng);
}

const int maxn=2e6+10;
char s[maxn];
// main 需要接收命令行参数
int main(int argc, char *argv[])
{
    // 初始化 checker 环境 —— 解析命令行参数、打开文件……
    // registerTestlibCmd(argc, argv, 1);
    // registerGen(argc, argv, 1);//初始化数据生成器

    int n=atoi(argv[1]);
    int r=atoi(argv[2]);
    int T=atoi(argv[3]);
    cout<<n<<endl;
    for(int i=1;i<=26;i++)
    {
        if(i<=10)cout<<getRand(0,r)<<" ";
        else cout<<getRand(-r,r)<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
        s[i]='a'+getRand(0,25);
    while(T--)
    {
        int mid=getRand(1,n);
        int l=getRand(1,n/2);
        for(int i=1;i<=l && mid+i<=n && mid-i>=1 ;i++)
            s[mid+i]=s[mid-i]='a'+getRand(0,25);
    }
    for(int i=1;i<=n;i++)
        cout<<s[i];
    cout<<endl;

    return 0;
}
