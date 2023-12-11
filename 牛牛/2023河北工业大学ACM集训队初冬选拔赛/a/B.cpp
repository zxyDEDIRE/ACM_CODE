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
int p[maxn];
int n,L,k;
int f(int x,int y){
	return (y-x+L)%L;
}
void solve()
{
	cin>>n>>L>>k;
	for(int i=0;i<n;i++)
		cin>>p[i];
	sort(p,p+n);
	ll ma=0;
	ll ans=0;
	int l=0,r=k-1;
	for(int i=0;i<=k-1;i++)
		ans+=f(p[i],p[i+1]);
	ans+=f(p[n-1],p[0]);
	ma=max(ma,ans);
	for(int i=1;i<=n;i++)
	{
		ans-=f(p[(l-1+n)%n],p[l]);
		l=(l+1)%n;
		r=(r+1)%n;
		ans+=f(p[r],p[(r+1)%n]);
		ma=max(ma,ans);
	}
	cout<<ma<<endl;

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