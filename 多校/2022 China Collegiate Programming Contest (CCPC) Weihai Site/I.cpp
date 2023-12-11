#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
int in[66];
int b[66];
int n,k;
bool check(int mid)
{
	for(int i=0;i<k;i++)
		in[i]=b[i];
	for(int i=1;i<=n;i++)
	{
		int now=mid*a[i];
		cout<<"I "<<now<<endl;
		vector<int>p(k+1,0);
		for(int j=0;j<k-1;j++)
			if(now&(1ll<<j))p[j]++,now-=(1ll<<j);
		p[k-1]=(now/(1ll<<(k-1)));
		for(int j=0;j<k;j++)
			cout<<p[j]<<" ";cout<<endl;
		for(int j=0;j<k;j++)
			in[j]-=p[j];
		for(int j=0;j<k;j++)
			cout<<



	}
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=k;i++)
		cin>>b[i];

	// int l=0,r=1e9,ans=0;
	// while(l<r-1)
	// {
	// 	int mid=(l+r)>>1;
	// 	if(check(mid))ans=mid,l=mid;
	// 	else ans=mid;
	// }
	// while(check(ans+1))ans++;
	// cout<<ans<<endl;
	cout<<check(2)<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}