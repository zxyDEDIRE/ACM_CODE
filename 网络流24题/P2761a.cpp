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
const int INF=1e10+7;
const int maxn=1e7;
struct node{
	int di,dis;
	bool operator<(const node &a)const{
		return a.dis<dis;
	}
};
int b1[maxn],b2[maxn],f1[maxn],f2[maxn];
int dis[maxn];
int w[maxn];
int n,m;
void dij()
{
	int s=(1<<n)-1;
	int t=0;
	for(int i=0;i<=s;i++)
		dis[i]=INF;
	bitset<maxn>vis;

	dis[s]=0;
	priority_queue<node>q;
	q.push({s,0});
	while(!q.empty())
	{
		auto [x,X]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=1;i<=m;i++)
		{
			if((x&b1[i])==b1[i]&&(x&b2[i])==0)
			{
				int y=(((x|f1[i])^f1[i])|f2[i]);
				if(dis[y]>dis[x]+w[i])
				{
					dis[y]=dis[x]+w[i];
					q.push({y,dis[y]});
				}
			}
		}
	}
	if(dis[t]!=INF)cout<<dis[t]<<endl;
	else cout<<0<<endl;
}
void spfa()
{
	int s=(1<<n)-1;
	int t=0;
	for(int i=0;i<=s;i++)
		dis[i]=INF;
	bitset<maxn>vis;
	queue<int>q;
	dis[s]=0;
	vis[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		for(int i=1;i<=m;i++)
		{
			if((x&b1[i])==b1[i]&&(x&b2[i])==0)
			{
				int y=(((x|f1[i])^f1[i])|f2[i]);
				if(dis[y]>dis[x]+w[i])
				{
					dis[y]=dis[x]+w[i];
					if(!vis[y]){
						q.push(y);
						vis[y]=1;
					}
				}
			}
		}
	}
	if(dis[t]!=INF)cout<<dis[t]<<endl;
	else cout<<0<<endl;
}
//((x  or  f1)  xor  f1)  or  f2
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		string a,b;
		cin>>a>>b;
		for(int j=0;j<n;j++)
		{
			if(a[j]=='+')b1[i]|=(1<<j);
			if(a[j]=='-')b2[i]|=(1<<j);
			if(b[j]=='-')f1[i]|=(1<<j);
			if(b[j]=='+')f2[i]|=(1<<j);
		}
	}
	spfa();
	//dij();
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}