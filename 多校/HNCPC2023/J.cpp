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
const int mod=1e9+9;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=200;
bitset<N>ok;
pii a[maxn];
int p[maxn];
int n,m,k,d;
struct matrix{
	ll a[N][N];
	int l,r;
	matrix(){
		memset(a,0,sizeof(a));
	}
	void build()
	{
		for(int i=1;i<=n;i++)
			a[i][i]=1;
	}
};
matrix operator*(const matrix&x,const matrix&y)
{
	matrix z;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
	return z;
}
matrix pow(matrix b,int p)
{
	matrix r;r.build();
	while(p)
	{
		if(p&1)r=r*b;
		b=b*b;
		p>>=1;
	}
	return r;
}


ll calc()
{
	matrix mt;
	for(int i=1;i<=n;i++)
		mt.a[i][i]=1;
	for(int i=1;i<=m;i++)
	{
		auto [x,y]=a[i];
		if(ok[x]||ok[y])continue;
		mt.a[x][y]=1;
		mt.a[y][x]=1;
	}
	matrix ans=pow(mt,2);
	ll sum=0;
	for(int i=1;i<=n;i++)
		sum+=ans.a[i][i];
	return sum;
}
void solve()
{
	cin>>n>>m>>k>>d;
	for(int i=1;i<=k;i++)
		cin>>p[i];
	for(int i=1;i<=m;i++)
		cin>>a[i].first>>a[i].second;
	ll ans=calc();
	cout<<ans<<endl;
	// for(int j=1;j<(1<<k);j++){
	// 	ok.reset();
	// 	for(int i=1;i<=k;i++)
	// 		if(j&(1<<((p[i])-1)))ok[i]=1;
	// 	int now=calc();
	// 	for(int i=1;i<=n;i++)
	// 		cout<<ok[i];cout<<" ";
	// 	ans=(ans-now+mod)%mod;
	// }
	// cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}