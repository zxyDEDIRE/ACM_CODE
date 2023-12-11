/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
struct node{
	int id;
	double p,num;
}dp[maxn];
int out[maxn];
int in[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		out[x]++;
		in[y]++;
	}
	queue<node>q;
	q.push({1,1.0,0.0});
	while(!q.empty())
	{
		auto [x,p,num]=q.front();q.pop();
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			dp[y].id=y;
			dp[y].p+=1.0*p/out[x];
			double t=1.0*p/out[x];
			dp[y].num+=num+edge[i].w*t;

			if(x==1)
			{
				dp[y].num+=num+edge[i].w*t;
			}
			else dp[y].num+=num+

			in[y]--;
			if(in[y]==0)q.push(dp[y]);
			
		}
	}
	printf("%.2f",dp[n].num);
}
int main()
{	

		solve();
	return 0;
}