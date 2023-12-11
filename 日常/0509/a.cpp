#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2000;
bitset<maxn>a;
int vis[maxn];
int p[maxn];
int n,m,q;
bool bfs()
{
	queue<int>q;
	q.push(0);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(x==n)return 1;
		if(vis[x])continue;
		vis[x]=1;
		if(a[x])continue;

		int xx=x-1;
		if(xx>=0&&xx<=n)q.push(p[xx]);

		xx=x+1;
		if(xx>=0&&xx<=n)q.push(p[xx]);
	}
	return 0;
}
int main()
{
	cin>>n>>m>>q;
	for(int i=0;i<=n;i++)p[i]=i;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
	//	p[x]=y;p[y]=x;
		if(x<y)p[x]=y+1,p[y]=x-1;
		if(x>y)p[x]=y-1,p[y]=x+1;
	}
	for(int i=1,x;i<=q;i++){
		cin>>x;
		a[x]=1;
	}
	if(bfs())cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

}