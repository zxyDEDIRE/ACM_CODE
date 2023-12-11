#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
struct node{
    long long  x,y;
}a[maxn],b[maxn];
int n,m;
bool cmp(node a,node b)
{
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}
int main()
{
    cin>>n;
    long long a_y=1e10,a_x=-1e10;
    long long b_y=1e10,b_x=-1e10;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
        a_y=min(a_y,a[i].y);
        a_x=max(a_x,a[i].x);
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>b[i].x>>b[i].y;
        b_y=min(b_y,b[i].y);
        b_x=max(b_x,b[i].x);
    }
    long long ans=0;
    ans=max(ans,b_x-a_y);
    ans=max(ans,a_x-b_y);
    cout<<ans<<endl;
}












