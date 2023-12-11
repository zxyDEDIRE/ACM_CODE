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
int p[maxn];
int a[maxn];
int b[maxn];
int n,m,k;
bool check(int mid)
{
	int K=k*mid;
	int ma=0;
	int now=0;
	for(int i=1;i<=n;i++)
	{
		now+=p[i];
		ma=max(ma,now);
	}
	return ma<=K;
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		if(x<=y)p[x]++,p[y]--;
		else p[x]++;
	}
	// int l=1,r=n,ans=n;
	// while(l<r-1)
	// {
	// 	int mid=(l+r)>>1;
	// 	if(check(mid))ans=mid,r=mid;
	// 	else l=mid;
	// }
	// while(ans>1&&check(ans-1))ans--;
	// cout<<ans<<endl;
	int ma=0;
	int now=0;
	for(int i=1;i<=n;i++)
	{
		now+=p[i];
		ma=max(ma,now);
	}
	cout<<(ma+k-1)/k<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*

*/