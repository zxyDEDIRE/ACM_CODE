/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct node{
	int x,y,w;
}a[maxn];
int p[maxn];
int n,m;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	while(cin>>n&&n)
	{
		m=n*(n-1)/2;
		int cnt=0,ans=0;
		for(int i=1;i<=n;i++)
			p[i]=i;
		for(int i=1;i<=m;i++)
		{
			int x,y,w,fl;
			cin>>x>>y>>w>>fl;
			if(fl==1)
			{
				int fa=find(x);
				int fb=find(y);
				if(fa!=fb)p[fa]=fb;
			}
			else
			{
				a[++cnt]={x,y,w};
			}
		}
		sort(a+1,a+1+cnt,[&](node a,node b){
			return a.w<b.w;
		});
		for(int i=1;i<=cnt;i++)
		{
			int fa=find(a[i].x);
			int fb=find(a[i].y);
			if(fa!=fb)
			{
				p[fa]=fb;
				ans+=a[i].w;
			}
		}
		cout<<ans<<endl;
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}