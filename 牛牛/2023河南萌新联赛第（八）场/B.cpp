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
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int t1[maxn],t2[maxn];
int a[maxn],b[maxn];
int n;
void add1(int l,int r){
	t1[l]++;
	t1[r+1]--;
}
void add2(int l,int r){
	t2[l]++;
	t2[r+1]--;
}
ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		pii a,b;
		cin>>a.first>>a.second>>b.first>>b.second;
		if(a>b)swap(a,b);
		if(a.second>=b.first)
		{
			add1(min(a.first,b.first),max(a.second,b.second));
			add2(max(a.first,b.first),min(a.second,b.second));
		}
		else
		{
			add1(a.first,a.second);
			add1(b.first,b.second);
		}
	}
	int ans=0;
	for(int i=1;i<=5e5;i++)
	{
		a[i]=a[i-1]+ t1[i];
		b[i]=b[i-1]+ t2[i];
		// cout<<a[i]<<" "<<b[i]<<endl;
		if(a[i]==n){
			ans=(ans+ksm(2,b[i]))%mod;
		}
	}
	cout<<ans<<endl;
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
/*


0 1 0 -1 0
0 1 1 0 0 
*/