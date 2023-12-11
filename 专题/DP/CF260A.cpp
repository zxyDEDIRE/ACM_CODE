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
int dp[maxn][2];
int w[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n);
	vector<pii>v;
	for(int i=1;i<=n;i++)
	{
		if(v.size()==0||p[i]!=v.back().first)
			v.push_back({p[i],1});
		else if(p[i]==v.back().first)
			v.back().second++;
	}
	for(auto [x,y]:v)
		w[x]+=x*y;
	for(int i=1;i<=1e5;i++)
	{
		dp[i][0]+=max(dp[i-1][0],dp[i-1][1]);
		dp[i][1]+=dp[i-1][0]+w[i];
	}
	int N=1e5;
	cout<<max(dp[N][0],dp[N][1])<<endl;
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