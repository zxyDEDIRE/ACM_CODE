#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int maxn=1e6+100;

struct node{
	int x,y,w;
	node(){}
	node(int a,int b,int c):x(a),y(b),w(c){}
};
node p[maxn];
int f[maxn];
int n,m;
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int r){
	return f[r]==r?f[r]:find(f[r]);
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		p[i]=node(x,y,w);
	}
	sort(p+1,p+1+n,cmp);
	int ma=0;
	for(int i=1;i<=m;i++)
	{
		int x=p[i].x;
		int y=p[i].y;
		int w=p[i].w;
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
			f[fa]=fb,ma=max(ma,w);
	}
	cout<<ma<<endl;

	return 0;
}