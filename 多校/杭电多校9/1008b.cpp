/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int prime[maxn];
int vis[maxn];
int phi[maxn];
void doit()
{
    for(int i=2;i<=maxn;i++){
        if(!vis[i])prime[++prime[0]]=i,phi[i]=i-1;
        for(int j=1;j<=prime[0]&&prime[j]*i<=maxn;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
}
void solve()
{
    int n=1e7;
    int x=1;
    doit();
    for(int i=1;i<=n;i++)
    {
        if(x*prime[i]>n)break;
        x*=prime[i];
    }
    cout<<x<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
//  fclose(stdin);
//  fclose(stdout);
    return 0;
}