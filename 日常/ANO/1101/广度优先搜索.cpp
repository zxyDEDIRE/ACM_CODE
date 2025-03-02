#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
int mp[111][111];
bool vis[111];
int q[maxn]; // 队列
int s=0,t=1;
int n,m;
// n个点 m条边

void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		mp[x][y]=1;
	}


	// queue<int>q;
	q[++s]=1;
	while(s>=t)
	{
		int x=q[t];t++;

		if(vis[x])continue;
		vis[x]=1;

		cout<<x<<endl;

		for(int i=1;i<=n;i++)
			if(!vis[i] && mp[x][i])
				q[++s]=i;
	}
}
signed main(){
		solve();
	return 0;
}