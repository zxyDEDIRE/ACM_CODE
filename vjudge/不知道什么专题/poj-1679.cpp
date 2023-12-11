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
const int maxn=111;
int mp[maxn][maxn];
bitset<maxn>vis;
int dis[maxn];
int cnt[maxn];
int n,m;
int prime()
{
	vis.reset();
	for(int i=1;i<=n;i++)
		dis[i]=INF,cnt[i]=0;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int t=-1;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&(t==-1||dis[j]<dis[t]))t=j;
		vis[t]=1;
		if(i)ans+=dis[t];
		for(int j=1;j<=n;j++)
		{
			if(t==j)continue;
			if(dis[j]==mp[t][j])cnt[j]++;
			if(dis[j]>mp[t][j])dis[j]=mp[t][j],cnt[j]=1;
		}
	}
	return ans;
}
void solve()
{
	cin>>n>>m;
	memset(mp,INF,sizeof(mp));
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		mp[x][y]=min(mp[x][y],w);
		mp[y][x]=min(mp[y][x],w);
	}
	int t=prime();
	int fl=1;
	for(int i=1;i<=n;i++){
		if(cnt[i]>1)fl=0;
	}
	if(fl==1)cout<<t<<endl;
	else cout<<"Not Unique!"<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}