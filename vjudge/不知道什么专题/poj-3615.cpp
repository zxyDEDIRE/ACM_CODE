/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
const int maxn=333;
int dis[maxn][maxn];
int n,m,q;
void Floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],max(dis[i][k],dis[k][j]));
}
void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=INF;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		dis[x][y]=w;
	}
	Floyd();
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		int t=dis[x][y];
		if(t==INF)cout<<-1<<endl;
		else cout<<t<<endl;
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
        solve();
    return 0;
}