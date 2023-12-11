/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int out[maxn];
int in[maxn];
int u[maxn];
int c[maxn];
int n,m;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void solve()
{
	cin>>n>>m;
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i]>>u[i];
		if(c[i])q.push(i);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		in[y]++;
		out[x]++;
	}
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			c[y]+=edge[i].w*c[x];
			in[y]--;
			if(!in[y])
			{
				c[y]-=u[y];
				if(c[y]>0)q.push(y);
			}
		}
	}
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(!out[i]&&c[i]>0)
		{
			flag=1;
			cout<<i<<" "<<c[i]<<endl;
		}
	}
	if(flag==0)cout<<"NULL"<<endl;

}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}