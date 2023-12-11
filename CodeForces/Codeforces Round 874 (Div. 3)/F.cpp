/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
map<ll,ll>mp;
ll p[maxn];
ll n,m;
ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
void solve()
{
	cin>>n>>m;
	mp.clear();
	for(int i=1;i<=n;i++)
		cin>>p[i],mp[p[i]]++;
	sort(p+1,p+1+n);
	n=unique(p+1,p+1+n)-p-1;
	ll ans=0;
	ll now=1;
	for(int i=1;i<=m;i++){
		now*=mp[p[i]];
		now%=mod;
	}
	for(int i=1;i+m-1<=n;i++)
	{
		if(p[i+m-1]-p[i]<m)ans+=now,ans%=mod;
		now*=ksm(mp[p[i]],mod-2);now%=mod;
		now*=mp[p[i+m]];now%=mod;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
7 4
8 10 10 9 6 11 7
*/