#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int head[maxn],cnt;
int h[maxn],ct;
int dis[maxn];
int out[maxn];
int in[maxn];
int t[maxn];
int n;
struct Edge{
	int to,next,w1,w2;
}edge[maxn],e[maxn];
void add(int from,int to,int w1,int w2){
	edge[++cnt].w1=w1;
	edge[cnt].w2=w2;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void bdd(int from,int to,int w1,int w2){
	e[++ct].w1=w1;
	e[cnt].w2=w2;
	e[cnt].to=to;
	e[cnt].next=h[from];
	h[from]=ct;
}
void dfs(int x)
{
	t[x]=1;
	cout<<x<<endl;
	/*
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";cout<<endl;
	*/
	for(int i=1;i<=n;i++)
		cout<<t[i]<<" ";cout<<endl;
	
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		int w1=edge[i].w1;
		int w2=edge[i].w2;
		if(dis[x]%w1!=0){
			t[x]*=w1;
			dis[x]*=w1;
			dis[y]=dis[x]/w1*w2;
		}
		else dis[y]=dis[x]/w1*w2;
		dfs(y);
	}
	
}
void solve()
{
	cin>>n;
	memset(edge,0,sizeof(edge));cnt=0;
	for(int i=1,a,b,c,d,e;i<n;i++){
		cin>>a>>b>>c>>d;e=__gcd(c,d);
		c=c/e;d=d/e;
		if(c>d)add(b,a,d,c),bdd(a,b,c,d),in[a]++,out[b]++;
		else add(a,b,c,d),bdd(b,a,d,c),in[b]++,out[a]++;
	}
	/*
	for(int i=1;i<=n;i++)
	{
		cout<<i<<"*"<<endl;
		for(int j=head[i];j;j=edge[j].next)cout<<edge[j].to<<" ";
		cout<<endl;
	}*/
	
	for(int i=1;i<=n;i++)dis[i]=1;
	for(int i=1;i<=n;i++)
		if(!in[i])cout<<i<<endl,dfs(i);
//	for(int i=1;i<=n;i++)
//		cout<<dis[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<t[i]<<" ";cout<<endl;
	
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
