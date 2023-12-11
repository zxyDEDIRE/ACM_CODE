/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
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
const int N=1000;
vector<pii>v[N];
int dp[N][N];
int ans=0;
int n;
void dfs(int x,int num)
{
	if(x>=n){
		ans=max(ans,num);
		return ;
	}
	for(auto [y,w]:v[x])
		dfs(y+1,num+w);
}
void solve()
{
	string str;
	cin>>str;
	str=" "+str;
	n=str.size()-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(str[i]=='A'&&str[j]!='B')continue;
			if(str[i]=='B'&&str[j]!='A')continue;
			if(str[i]=='X'&&str[j]!='Y')continue;
			if(str[i]=='Y'&&str[j]!='X')continue;
			v[i].push_back({j,1});
			cout<<i<<" "<<j<<endl;
		}
	}
	for(int i=1;i<n;i++)
		v[i].push_back({i+1,0});
	dfs(1,0);
	cout<<ans<<endl;
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
dp[3][4]
dp[1][5]+=dp[3][4]
dp[6][7]+=dp[1][5]
*/