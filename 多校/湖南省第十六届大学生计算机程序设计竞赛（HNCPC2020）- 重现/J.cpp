#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+100;
struct node{
	int x,y,a,b;
}p[maxn];
int f[maxn];
int n,m,l,r,now;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
int F()
{
	for(int i=1;i<=n;i++)
		f[i]=i;
	sort(p+1,p+1+m,[&](node a,node b){
		return a.a+a.b*now<b.a+b.b*now;
	});
	int ans=0;
	for(int i=1;i<=m ;i++)
	{
		int x=p[i].x;
		int y=p[i].y;
		int w=p[i].a+p[i].b*now;
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
		{
			f[fa]=fb;
			ans+=w; 
		}
	}
	return ans;
}
void solve()
{
	for(int i=1;i<=m;i++)
		cin>>p[i].x>>p[i].y>>p[i].a>>p[i].b;
	int mi=1e18;
	now=l;
	mi=min(mi,F());
	now=r;
	mi=min(mi,F());
	cout<<mi<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	while(cin>>n>>m>>l>>r)
		solve();
}
/*
5 6 1 5
1 2 1 1
2 3 1 2
3 4 1 -10
3 4 2 10
5 1 3 10
2 4 5 -10
*/
