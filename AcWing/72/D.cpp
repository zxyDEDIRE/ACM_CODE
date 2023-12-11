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
vector<int>v[maxn];
bitset<maxn>vis;
int dis[111][111];
int n,mi=INF,now;
void dfs(int x,int now,int d)
{
	if(vis[x])
	{
		if(d)mi=min(mi,d);
		return ;
	}
	vis[x]=1;
	dis[now][x]=d;
	for(auto y:v[x])
	{
		dfs(y,now,d+1);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		v[i].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		vis.reset();
		dfs(i,i,0);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dis[i][j]&&dis[i][j]==dis[j][i])
				mi=min(mi,dis[i][j]);
		}
	}
	cout<<mi<<endl;
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
4
2 3 1 4
1 2 3 1


5
2 4 3 1 2
1 2 4 1 
3 3 3 
5 2 4 1 2 4 1
*/