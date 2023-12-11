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
const int maxn=1e7+100;
ll t[maxn];
ll f[maxn];
int n;
ll division_block(ll n){
	ll res = 0;
	for(ll l = 1, r; l <= n; l = r + 1){
		r = n / (n / l);
		res += n / l * (r - l + 1);
	}
	return res;
}
void solve()
{
	ll n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=1,mx=n/i;j<=mx;j++)
			ans+=(n+1-i*j),cnt+=(n+1-i*j);
		// cout<<i<<" "<<n/i<<" "<<cnt<<endl;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
9+4*2+2

*/