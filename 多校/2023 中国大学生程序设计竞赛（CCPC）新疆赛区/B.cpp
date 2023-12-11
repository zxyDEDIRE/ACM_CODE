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
int dp[maxn],tot;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	ll ans=abs(p[1]-p[n])+n-1;
	if(p[1]>p[n])
	{
		int l=1,r=n;
		while(l<r){
			swap(p[l],p[r]);
			l++,r--;
		}
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]>=dp[tot])dp[++tot]=p[i],res=tot;
		else{
			int fl=upper_bound(dp+1,dp+1+tot,p[i])-dp;
			if(fl==1)continue;
			dp[fl]=p[i];
			res=fl;
		}
	}
	cout<<ans<<" "<<res-1<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
7
4 1 2 3 4 5 6 

4
4 4 4 4
*/