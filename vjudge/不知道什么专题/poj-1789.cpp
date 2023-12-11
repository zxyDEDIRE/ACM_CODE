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
const int maxn=2000+111;
string mp[maxn];
int p[maxn][maxn];
bitset<maxn>vis;
int dis[maxn];
int n;
int f(int x,int y)
{
	int ans=0;
	for(int i=0;i<7;i++)
		ans+=(mp[x][i]!=mp[y][i]);
	return ans;
}
int prime()
{
	int ans=0;
	vis.reset();
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	for(int i=0;i<n;i++)
	{
		int s=-1;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&(s==-1||dis[j]<dis[s]))s=j;
		vis[s]=1;
		if(i)ans+=dis[s];
		for(int j=1;j<=n;j++)
			dis[j]=min(dis[j],p[s][j]);
		
	}
	return ans;
}
void solve()
{
	while(cin>>n)
	{
		if(n==0)break;
		for(int i=1;i<=n;i++)
			cin>>mp[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				p[i][j]=p[j][i]=f(i,j);
		}
		int t=prime();
		cout<<"The highest possible quality is 1/"<<t<<".\n";
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
		solve();
	return 0;
}