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
const int dx[]={0,1,-1};
const int dy[]={1,0,0};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=3e5;
string mp[3];
bool vis[3][maxn];
int cnt[maxn];
int n;
bool dfs(int x,int y,int num)
{
	if(num<cnt[y-1])return 0;
	if(mp[x][y]=='B')num++;
	if(num==cnt[n])return 1;
	int flag=0;
	for(int i=0;i<3;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<1||xx>2||yy>n)continue;
		if(vis[xx][yy])continue;
		if(mp[xx][yy]!='B')continue;
		vis[xx][yy]=1;
		flag|=dfs(xx,yy,num);
		vis[xx][yy]=0;
	}
	return flag;
}
void solve()
{
	cin>>n>>mp[1]>>mp[2];
	mp[1]=" "+mp[1];
	mp[2]=" "+mp[2];
	for(int i=1;i<=n;i++)
	{
		vis[1][i]=vis[2][i]=0;
		cnt[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		if(mp[1][i]=='B')cnt[i]++;
		if(mp[2][i]=='B')cnt[i]++;
		cnt[i]+=cnt[i-1];
	}
	int flag=0;
	vis[1][1]=1;
	flag=dfs(1,1,0);
	vis[1][1]=0;
	if(flag)
	{
		cout<<"YES"<<endl;
		return ;
	}
	vis[2][1]=1;
	flag=dfs(2,1,0);
	vis[2][1]=0;
	if(flag)
	{
		cout<<"YES"<<endl;
		return ;
	}
	cout<<"NO"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}