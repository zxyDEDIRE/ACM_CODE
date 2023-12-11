/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
vector<int>v[maxn];
int dp[maxn];
string str;
stack<char>s;
int n;
void dfs(int x,int tmp)
{
	dp[x]=tmp;
	int flag=0;
	if(str[x]==')'&&s.size()&&s.top()=='(')
		flag=1,s.pop();
	else s.push(str[x]);
	dp[x]+=flag;
	for(auto y:v[x])
		dfs(y,dp[x]);
	if(flag)
		s.push('(');
	else s.pop();
}
void solve()
{
	cin>>n>>str;
	str=" "+str;
	for(int i=2;i<=n;i++)
	{
		int x;cin>>x;
		v[x].push_back(i);
	}
	dfs(1,0);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		// cout<<i<<" "<<dp[i]<<endl;
		ans=(ans^(dp[i]*i));
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}