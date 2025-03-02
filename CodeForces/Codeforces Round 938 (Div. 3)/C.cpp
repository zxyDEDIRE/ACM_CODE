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
ll a[maxn];
ll n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	int l=1,r=n;
	while(k)
	{
		if(l>=r)break;
		ll mi=min(a[l],a[r]);
		if(mi*2<=k)
		{
			a[l]-=mi;
			a[r]-=mi;
			if(a[l]==0)ans++,l++;
			if(a[r]==0)ans++,r--;
			k-=mi*2;
		}
		else break;
	}
	if(k&&l<r)
	{
		int B=k/2;
		int A=k-B;
		a[l]-=A;
		a[r]-=B;
		if(a[l]==0)ans++;
		else if(a[r]==0)ans++;
	}
	if(l==r&&a[l])
	{
		if(a[l]<=k)ans++;
	}
	
	cout<<ans<<endl;
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
1 2
2 1
*/