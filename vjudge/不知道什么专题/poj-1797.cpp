#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=1e6+10;
struct node{
	int x,y,w;
	node(){}
	node(int _x,int _y,int _w):x(_x),y(_y),w(_w){}
}p[maxn];
int f[maxn];
int n,m;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
bool check(int mid)
{
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x=p[i].x;
		int y=p[i].y;
		int w=p[i].w;
		if(w<mid)continue;
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)f[fa]=fb;
	}
	int fa=find(1);
	int fb=find(n);
	return fa==fb;
}
void solve()
{
	cin>>n>>m;
	int l=0,r=0,ans=0;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		r=max(r,w);
		p[i]=node(x,y,w);
	}
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	while(check(ans+1))ans++;
	cout<<ans<<"\n\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	for(int i=1;i<=__;i++){
		cout<<"Scenario #"<<i<<":\n";
		solve();
	}
	return 0;
}
/*

*/