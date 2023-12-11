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
const ll INF=1e18+7;
const int maxn=1e6+100;
const int N=5111;
ll dp[N];
int p[maxn];
int a[maxn];
int n;
void solve()
{
	cin>>n;
	memset(a,0,sizeof a);
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]<=n)a[p[i]]++;
	}
	sort(p+1,p+1+n);
	for(int i=0;i<=n;i++)
			dp[i]=INF;
	int top=0;
	while(a[top])top++;
	dp[top]=0;
	for(int i=top;i>=0;i--)
	{
		for(int j=i-1;j>=0;j--)
		{
			dp[j]=min(dp[j],dp[i]+i*(a[j]-1)+j);
		}
	}
	cout<<dp[0]<<endl;
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
/*
8
0 0 0 1 2 3 4 5
*/