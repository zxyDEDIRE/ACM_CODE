#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
const int maxn=1e5;
struct node{
	int x,y,w;
}a[maxn];
int now;
int ans[40];
int p[40]; 
int n,m;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
int t=0;
int f()
{
	for(int i=1;i<=n;i++)
		p[i]=i;
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		auto [x,y,w]=a[i];
		if(!((now>>x)&1)||(!(now>>y)&1))continue;
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb){
			p[fa]=fb;
			sum+=w;
		}
	}
	int top=find(1);
	for(int i=1;i<=n;++i)
		if(((now>>i)&1)&&find(i)!=top)return INF;
	return sum;
}
void solve()
{
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		a[i]={x,y,w};
	}
	sort(a+1,a+1+m,[&](node a,node b){
		return a.w<b.w;
	});
	for(int i=1;i<=n;i++)
		ans[i]=INF;
	int res=1<<n;
	res-=1;
	res=res<<1;
	
	for(int i=n;i>=2;i--)
	{
		for(int j=0;j<1<<(n-i);j++)
		{
			now=j<<(i+1);
			now|=res;
			int x=f();
			ans[i]=min(x,ans[i]);
		}
		res=res^(1<<i);
	}
	for(int i=n-1;i>=2;i--) ans[i]=min(ans[i],ans[i+1]);
	for(int i=2;i<=n;i++)
		cout<<ans[i]<<'\n';
}
signed main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	while(cin>>n>>m)
		solve();
	return 0;
}