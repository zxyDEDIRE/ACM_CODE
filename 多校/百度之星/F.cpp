#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6+100;
struct node{
	int x,y;
}p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y;
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.x!=b.x)
			return a.x>b.x;
		return a.y<b.y;
	});
	int ma=0;
	int cnt=1;
	int v=p[1].y;
	int x=p[1].x;
	for(int i=2;i<=n;i++)
	{
		if(p[i].x==x)cnt++,v=min(v,p[i].y),x=p[i].x;
		else if(p[i].y>v)cnt++,v=min(v,p[i].y),x=p[i].x;
		else cnt=1,v=p[i].y,x=p[i].x;
		ma=max(ma,cnt);
	}
	cout<<ma<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}