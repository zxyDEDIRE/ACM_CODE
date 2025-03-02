#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int head[maxn],cnt;
bool vis[maxn];
int dis[maxn];
int in[maxn];
int t[maxn];
int n;
struct Edge{
	int to,next,w1,w2;
}edge[maxn];
void add(int from,int to,int w1,int w2){
	edge[++cnt].w1=w1;edge[cnt].w2=w2;edge[cnt].to=to;edge[cnt].next=head[from];head[from]=cnt;
}
void dfs(int x)
{
	if(vis[x])return;
	cout<<x<<endl;
	vis[x]=1;
	t[x]=1;
	
	for(int i=1;i<=n;i++)cout<<dis[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++)cout<<t[i]<<" ";cout<<endl;
	for(int i=head[x];i;i=edge[i].next){
		int y=edge[i].to;
		int w1=edge[i].w1;
		int w2=edge[i].w2;
		if(dis[x]%w1!=0){
			dis[x]*=w1;
			t[x]*=w1;
			dis[y]=dis[x]/w1*w2;
		}
		else dis[y]=dis[x]/w1*w2;
		dfs(y);
		dis[x]*=t[y];
	}
}
void solve()
{
	cin>>n;
	for(int i=1,a,b,c,d,e;i<n;i++){
		cin>>a>>b>>c>>d;e=__gcd(c,d);
		c/=e;d/=e;
		add(a,b,c,d);in[a]++;
		add(b,a,d,c);in[b]++;
	}
	for(int i=1;i<=n;i++)dis[i]=1;
	for(int i=1;i<=n;i++)
		if(in[i]==1&&!vis[i])dfs(i);
	for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
}
signed main(){
	int __;cin>>__;
	while(__--)solve();
}
/*
1
4
3 2 3 4
1 2 4 3
1 4 2 4

1
8
5 4 2 3
6 4 5 4
1 3 5 2
6 8 2 1
3 5 3 4
3 2 2 5
6 7 4 3
*/
