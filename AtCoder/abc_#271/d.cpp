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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=10000+10;
char step[maxn];
int dp[111][maxn];
int a[maxn];
int b[maxn];
int n,s;
int flag=0;
void dfs(int num,int x)
{
	if(flag)return ;
	if(x==0)
	{
		if(num==0)
		{
			for(int i=1;i<=n;i++)
				cout<<step[i];
			cout<<endl;
			flag=1;
		}
		return ;
	}
	if(dp[x-1][num-a[x]])
	{
		step[x]='H';
		dfs(num-a[x],x-1);
	}
	if(dp[x-1][num-b[x]])
	{
		step[x]='T';
		dfs(num-b[x],x-1);
	}
}
void solve()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=s;j>=0;j--)
		{
			if(j>=a[i])dp[i][j]+=dp[i-1][j-a[i]];
			if(j>=b[i])dp[i][j]+=dp[i-1][j-b[i]];
		}
	}
	if(!dp[n][s]){
		cout<<"No"<<endl;
		return ;
	}
	cout<<"Yes"<<endl;
	dfs(s,n);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}