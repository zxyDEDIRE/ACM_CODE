#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ll=long long;
const int maxn=1e6+100;

void solve()
{
    pp(3) p;
    for(int i=0;i<3;i++)
    {
        int x;cin>>x;
        p[i][0] = pow(10,x-1);
        p[i][1] = pow(10,x)-1;
    }
    int k;cin>>k;
    for(int i=p[0][0];i<=p[0][1];i++)
    {
        int l=p[2][0]-i;
        int r=p[2][1]-i;
        if(r<p[1][0]||l>p[1][1])continue;
        l=max(l,p[1][0]);
        r=min(r,p[1][1]);
        if(k>(r-l+1))k-=(r-l+1);
        else
        {
            l=l+k-1;
            cout<<i<<" + "<<l<<" = "<<i+l<<endl;
            return ;
        }
    }
    cout<<-1<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T;cin>>T;
    while(T--)
        solve();
    return 0;
}
