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
const int maxn=1e5+100;
vector<int>v[33];
int dp[maxn];
int p[maxn];
int n,m;
int f(int s,int x)
{
	int t=s+v[x].size()-1;
	int len=v[x].size();
	int fl_a=lower_bound(v[x].begin(),v[x].end(),s)-v[x].begin();
	int fl_b=lower_bound(v[x].begin(),v[x].end(),t+1)-v[x].begin();
	return len-(fl_b-fl_a);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		v[x].push_back(i);
	}
	for(int j=0;j<=n;j++)
		dp[j]=INF;
	dp[0]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=n;j>=0;j--)
		{
			if(j+v[i].size()<=n&&dp[j]!=INF)
			{
				dp[j+v[i].size()]=min(dp[j+v[i].size()],dp[j]+f(j,i));
				cout<<j+v[i].size()<<" "<<j<<" "<<i<<endl;
				cout<<dp[j+v[i].size()]<<" "<<dp[j]<<" "<<f(j,i)<<endl;
				cout<<endl;
			}
		}
	}
	// cout<<3<<" "<<dp[3]<<endl;
	// cout<<5<<" "<<dp[5]<<endl;
	// cout<<8<<" "<<dp[8]<<endl;
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
/*

*/