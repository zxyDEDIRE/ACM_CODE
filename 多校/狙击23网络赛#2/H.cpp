/*！*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
char  ch[maxn];
int dp[maxn][2];
int a[maxn];
int n,cnt;
void solve()
{
	cin>>n;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>ch[i];
		if(ch[i]=='1')a[++cnt]=i;
	}
	for(int i=1;i<=cnt;i++)
		dp[i][0]=dp[i][1]=INF;
	dp[1][0]=a[1]-1;
	dp[1][1]=a[1]-1+1;
	// cout<<dp[1][0]<<" "<<dp[1][1]<<endl;
	for(int i=2;i<=cnt;i++)
	{
		int len=(a[i]-a[i-1]-1);
		if(len==0)
		{
			dp[i][0]=min(dp[i-1][0], dp[i-1][1]);
			dp[i][1]=min(dp[i-1][0], dp[i-1][1]);
			continue;
		}

		dp[i][0] = min(dp[i][0], max(dp[i-1][0], (len+1-1)/2+1 ));
		dp[i][0] = min(dp[i][0], max(dp[i-1][1], (len+1-2)/2+1 ));

		dp[i][1] = min(dp[i][1], max(dp[i-1][0], (len+1)/2+1 ));
		dp[i][1] = min(dp[i][1], max(dp[i-1][1], (len+1-1)/2+1 ));
	}
	int ans=INF;
	int len=n-a[cnt];
	if(len)
	{
		ans = min(ans, max(dp[cnt][0], (len) +1 ));
		ans = min(ans, max(dp[cnt][1], (len-1) + 1));
		// cout<<dp[cnt][1]<<" "<<len<<endl;
	}
	else ans=dp[cnt][0];

	cout<<ans<<endl;
	

}

signed main(){
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1001
*/