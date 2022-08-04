#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int a[maxn],b[maxn];
int p[maxn];
int n,k,cnt;
void solve()
{
    cin>>n>>k;
    cnt=1;
    a[0]=0;
    for(int i=1;i<=n;i++)a[i]=b[i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        a[cnt]++;
        if(p[i])cnt++,a[cnt]=a[cnt-1];
    }
    cnt--;
    if(k>cnt){
        cout<<-1<<endl;
        return ;
    }
    int ans=1;
    b[0]=0;
    for(int i=n;i>=1;i--)
    {
        b[ans]++;
        if(p[i])ans++,b[ans]=b[ans-1];
    }


    ans=INT_MAX;
    int t=cnt-k;
    for(int i=0;i<=t;i++){
        // cout<<i<<" "<<t-i<<endl;
        // cout<<a[i]<<" "<<b[t-i]<<endl;
        ans=min(ans,a[i]+b[t-i]);
    }
    if(t==0)ans=0;
    cout<<ans<<endl;

}
int main()
{    ios
    int __;cin>>__;
    while(__--)solve();
}
/*
*/