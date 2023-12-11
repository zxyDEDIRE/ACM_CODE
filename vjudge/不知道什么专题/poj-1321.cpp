/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=10;
char mp[N][N];
int X[N];
int n,m,cnt;
void dfs(int x,int step)
{
	if(step==m){
		cnt++;
		return ;
	}
	if(x>n)return ;
	dfs(x+1,step);
	for(int i=1;i<=n;i++)
	{
		if(X[i])continue;
		if(mp[x][i]!='#')continue;
		X[i]=1;
		dfs(x+1,step+1);
		X[i]=0;
	}
}
void solve()
{
	cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j];
	dfs(1,0);
	cout<<cnt<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>n>>m&&m!=-1)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}