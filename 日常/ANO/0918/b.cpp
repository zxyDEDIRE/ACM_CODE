#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);
#define int __int128_t
typedef long long ll;
typedef pair<int,int> P;
const int N=2e5+7;
const int INF=0x3f3f3f3f;
const int mod=998244353;
vector<map<int,int>>mp;
int n,x;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void write(int x)
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}
int dp[1003][1003];
void solve()
{
    n=read(),x=read();
    mp.resize(n+1);
    mp[0][1]=1;
    for(int i=1;i<=n;i++){
        int len=read();
        for(int j=1;j<=len;j++){
            int x=read();
            for(auto p:mp[i-1]){
                mp[i][p.first*x]+=p.second;
            }
        }
    }
    write(mp[n][x]);
    //cout<<endl;
}
signed main()
{
    //IOS
    int __=1;
    //cin >> __;
    while (__--)
        solve();
}