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
const int INF=0x3f3f3f3f;
const int maxn=1e6;
map<string,int>Map;
int dis[30][30];
int mp[30][30];
int n,k,tot,t;
void Floyd()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=mp[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
void solve()
{
	cin>>n;
	memset(mp,INF,sizeof(mp));
	for(int i=1;i<=n;i++)
	{
		string a,b;int w;
		cin>>a>>b>>w;
		if(!Map[a])Map[a]=++tot;
		if(!Map[b])Map[b]=++tot;
		if(a=="Park")t=Map[a];
		if(b=="Park")t=Map[b];
		int x=Map[a];
		int y=Map[b];
		mp[x][y]=min(mp[x][y],w);
		mp[y][x]=min(mp[y][x],w);
	}cin>>k;
	Floyd();
	for(int i=1;i<=tot;i++)
	{
		for(int j=1;j<=tot;j++)
			cout<<dis[i][j]<<" ";
		cout<<endl;
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
        solve();
    return 0;
}