#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
string str;
int dis[maxn];
int n,ma;
void solve()
{
    cin>>n;
    ma=0;
    for(int i='a';i<='z';i++)dis[i]=0;
    for(int i=1;i<=n;i++){
        cin>>str;
        int len=str.size();
        int s=str[0];
        int t=str[len-1];
        
        dis[t]=max(dis[t],dis[s]+len);
        dis[t]=max(dis[t],len);
        ma=max(ma,dis[t]);
    }
    cout<<ma<<endl;
}
signed main()
{
    int __;cin>>__;
    while(__--)solve();
}