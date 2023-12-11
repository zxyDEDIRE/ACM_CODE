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
struct ST{
	ll f[maxn][30];
	void init(ll *p,int n)
	{
		for(int i=1;i<=n;i++)//距离为0初始化 
			f[i][0]=p[i];
		int t=log(n)/log(2)+1;//j定位 
		for(int j=1;j<t;j++)
		{
			for(int i=1;i<=n-(1<<j)+1;i++)
			{
				f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
				//f[i][j-1]为f[i][j]的长为2^j-1的前半段，另一段为f[i+(1<<(j-1))][j-1] 
			}
		} 
	}
	ll query(int l,int r)
	{
		if(l>r)return INF;
		int k=log2(r-l+1);
		return min(f[l][k],f[r-(1<<k)+1][k]);
	}
}st;
ll p[maxn];
ll n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	st.init(p,n);
	for(int t=n;t>=1;t--)
	{
		ll now=st.query(t+1,n)-1;
		ll cnt=0;
		for(int i=t;i>=1;i--)
		{
			
		}
	}
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

*/