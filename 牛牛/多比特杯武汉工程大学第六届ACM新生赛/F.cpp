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
ll dp[maxn];
int p[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	dp[0]=1;
	for(int i=1;i<=m;i++)
		dp[i]=0;
	for(int i=1;i<=n;i++)
		for(int j=m;j>=p[i];j--)
			dp[j]+=dp[j-p[i]],dp[j]%=66;
	ll ans=0;
	for(int i=0;i<=m;i++)
		ans=(ans+1ll*dp[i]*dp[m-i])%66;
	if(ans==0)cout<<"There's nothing left!\n";
	else cout<<(ans%66)<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}