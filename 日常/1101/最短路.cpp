#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;




int n;
void Floyd()
{
	int dis[111][111];// dis[x][y] x到y的最短路
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}


int dis[maxn];
int vis[maxn];
int mp[111][111];

// n:点数 s:起点
void dijkstra(int n, int s) {
	memset(dis, 63, sizeof(dis));
	dis[s] = 0;
	for (int i = 1; i <= n; i++) {
		int u = 0, mind = 0x3f3f3f3f;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && dis[j] < mind) u = j, mind = dis[j];
		vis[u] = true;
		for(int v=1;v<=n;v++)
		{
			if(!mp[u][v])continue;
			int w = mp[u][v];
			if (dis[v] > dis[u] + w) dis[v] = dis[u] + w;
		}
	}
}


signed main(){
	return 0;
}