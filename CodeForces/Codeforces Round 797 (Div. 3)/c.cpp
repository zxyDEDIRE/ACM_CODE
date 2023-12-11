#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll a[maxn],b[maxn];
int n;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    ll t=0;
    for(int i=1;i<=n;i++)
    {
        t=max(t,a[i]);
        cout<<b[i]-t<<" ";
        t=max(t,b[i]);
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}
/*

#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int a[N];
int b[N];
void slove()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    int cnt=-1;
    int pos=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]>a[i])return void(cout<<"NO\n");
        if(b[i]==0)
        {
            pos=max(pos,a[i]);
        }
        else
        {
            if(cnt==-1)cnt=a[i]-b[i];
            else 
            {
                if(a[i]-b[i]!=cnt)return void(cout<<"NO"<<'\n');
            }
        }
        if(cnt!=-1)
        {
            if(pos>cnt)return void (cout<<"NO\n");
        }
    }
    cout<<"YES\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        slove();
}
*/