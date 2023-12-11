/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn],G[maxn];
set<int>s[maxn];
bitset<maxn>vis;
int dis[maxn];
int mp[555][555];
int n,m;
int spfa()
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	queue<int>q;
	vis.reset();
	q.push(1);
	vis[1]=1;
	dis[1]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		for(auto y:G[x])
		{
			if(dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				if(!vis[y])
				{
					q.push(y);
					vis[y]=1;
				}
			}
		}
	}
	return dis[n];
}
int spfa1()
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	queue<int>q;
	vis.reset();
	q.push(1);
	vis[1]=1;
	dis[1]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		for(auto y:v[x])
		{
			if(dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				if(!vis[y])
				{
					q.push(y);
					vis[y]=1;
				}
			}
		}
	}
	return dis[n];
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		s[x].insert(y);
		s[y].insert(x);
		mp[x][y]=1;
		mp[y][x]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(mp[i][j])
				G[i].push_back(j),G[j].push_back(i);
			else v[i].push_back(j),v[j].push_back(i);
	int ans_1=spfa();
	int ans_2=spfa1();
	if(max(ans_1,ans_2)>=INF)cout<<-1<<endl;
	else cout<<max(ans_1,ans_2)<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}