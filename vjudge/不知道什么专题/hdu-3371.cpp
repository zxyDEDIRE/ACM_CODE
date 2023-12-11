/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
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
int n,m,k;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].x>>a[i].y>>a[i].w;
	sort(a+1,a+1+m,[&](node a,node b){
		return a.w<b.w;
	});
	for(int i=1;i<=n;i++)
		p[i]=i;
	int num=1;
	while(k--)
	{
		int cnt,x,y;
		cin>>cnt;
		for(int i=1;i<=cnt;i++)
		{
			cin>>y;
			if(i!=1)
			{
				int fa=find(x);
				int fb=find(y);
				if(fa!=fb)p[fa]=fb,num++;
			}
			x=y;
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int fa=find(a[i].x);
		int fb=find(a[i].y);
		if(fa!=fb)
		{
			num++;
			p[fa]=fb;
			ans+=a[i].w;
		}
	}
	if(num!=n)cout<<-1<<endl;
	else cout<<ans<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}