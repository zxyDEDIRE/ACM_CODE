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
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
ll dp[111][111][11111];
int p[maxn];
int n,k;
ll f(int l,int r,int w)
{
	if(l>r)return 0;
	if(l==r)
	{
		if(w==p[l])return 1;
		return 0;
	}
	ll ans_1 = f(l,r-1,w);
	ll ans_2 = f(l+1,r,w);
	ll res = f(l+1,r-1,w);
	ll ans_3 = 0;
	if(l+1<=r-1)
		ans_3 = f(l+1,r-1,w-p[l]-p[r]) + (w==(p[l]+p[r]));
	else
		ans_3 = (w==(p[l]+p[r]));

	dp[l][r][w+10000]=(((ans_1+ans_2)%mod-res%mod+mod)%mod+ans_3)%mod;
	return dp[l][r][w+10000];
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i],p[i]-=k;
	ll ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+2;j<=n;j++)
			ans+=f(i+1,j-1,0);
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;ci -)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}