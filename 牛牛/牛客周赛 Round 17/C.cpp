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
ll p[maxn],s[maxn],a[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	if(k==n){
		cout<<0<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		p[i]=p[i-1]+a[i];
		s[n-i+1]=s[n-i+2]+a[n-i+1];
	}
	double ans=a[n]-a[1];
	for(int i=1;i<=k;i++)
	{
		double sum=p[i]+s[n-(k-i)+1];
		sum=1.0*sum/k;
		double mi=min({sum,1.0*a[i+1]});
		double ma=max({sum,1.0*a[n-(k-i)]});
		ans=min(ans,ma-mi);
	}
	cout << fixed << setprecision(10)<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}