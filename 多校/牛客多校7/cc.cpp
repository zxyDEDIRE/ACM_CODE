#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int n;
struct node
{
    int x,id,ans;
}t[maxn];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i].x;
        t[i].id=i;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cnt+=t[i].x==t[1].x;
    }
    if(cnt==n)
    {
        cout<<"NO"<<endl;
        return;
    }
    sort(t+1,t+1+n,[&](node a,node b){
        return a.x>b.x;
    });
    int now=1;
    for(int i=1;i<=n;i++)
    {
        if(t[i].x==now)
        {
            t[i].ans=t[1].ans;
            t[1].ans=now;
        }
        else
        {
            t[i].ans=now;
        }
        now++;
    }
    sort(t+1,t+1+n,[&](node a,node b){
        return a.id<b.id;
    });
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
        cout<<t[i].ans<<" \n"[i==n];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
        solve();
}
/*
1
4
2 2 2 1
1 3 4 2
*/