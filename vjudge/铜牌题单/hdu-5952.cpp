/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=200;
vector<int>v[maxn];
bool mp[maxn][maxn];
bitset<maxn>vis;
bool ok[maxn];
int st[maxn];
int n,m,s,ans;
void dfs(int x,int fl,int num)
{
	if(num==s-1)
	{
		ans++;
		return ;
	}
	for(int i=fl;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(ok[y])continue;
		st[num+1]=y;
		int flag=1;
		for(int j=1;j<=num;j++)
			if(mp[y][st[j]]==0)
				flag=0;
		if(flag)
		{
			dfs(x,i+1,num+1);
		}
	}
}
void solve()
{
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			mp[i][j]=0;
		ok[i]=0;
		v[i].clear();
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		mp[x][y]=1;
		mp[y][x]=1;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	ans=0;
	for(int i=1;i<=n;i++)
	{
		dfs(i,0,0);
		ok[i]=1;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\Users\tob\Desktop\P4391_9.in.txt","r",stdin);
 // freopen("C:\Users\tob\Desktop\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}