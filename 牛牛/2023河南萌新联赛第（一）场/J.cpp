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
int a[maxn];
int b[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];

	double ma=-1,mi=1e9;
	for(int j=1;j<=100;j++)
	{
		for(int i=1;i<=n;i++)
			b[i]=a[i];
		b[n+1]=j;
		sort(b+1,b+2+n);
		double sum=0;
		for(int i=2;i<=n;i++)
			sum+=b[i];
		sum=1.0*sum/(n-1);
		mi=min(mi,sum);
		ma=max(ma,sum);
	}
	cout << fixed << setprecision(6) <<mi<<" "<<ma<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}