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
bitset<maxn>vis,ok;
vector<int>v[maxn];
int dis[maxn];
int n,m;
void spfa(int s)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	queue<int>q;
	q.push(s);
	dis[s]=0,vis[s]=1;
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
					q.push(y);
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(!x)ok[y]=1;
		else
		{
			v[x].push_back(y);
			v[y].push_back(x);
		}
	}
	spfa(1);
	for(int i=1;i<=n;i++)
	{
		 
	}
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
/*
3 2
0 2
1 2
*/