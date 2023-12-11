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
int n;
int mex(int l,int r)
{
	set<int>s;
	for(int i=l;i<=r;i++)
		s.insert(p[i]);
	int now=0;
	while(s.count(now))now++;
	return now;
}
int _gcd(int l,int r){
	int now=0;
	for(int i=l;i<=r;i++)
		now=__gcd(now,p[i]);
	return now;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int ans=mex(1,n);
	for(int i=1;i+2<=n;i++)
		ans=max(ans,mex(i,i+2)*_gcd(i,i+2));
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}