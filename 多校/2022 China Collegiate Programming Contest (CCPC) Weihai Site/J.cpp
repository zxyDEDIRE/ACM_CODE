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
ll pre[maxn];
int p[maxn];
pii q[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+p[i];
	map<int,int>mp;
	vector<int>f;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		mp[x]=y;
		if(y==0)
			f.push_back(x);
	}
	f.push_back(-1);
	sort(f.begin(),f.end(),[&](int a,int b){return a>b;});
	ll sum=0;
	int r=n;
	for(auto T:f)
	{
		int l=lower_bound(p+1,p+1+n,T)-p;
		int len=r-l+1;
		ll mi=T;
		for(int i=T+1;;i++)
		{
			if(!mp[i])break;
			if(len<mp[i])break;
			mi=i;
			sum+=mp[i]*i;
			len-=mp[i];
		}
		sum+=len*(mi+1);
		r=l-1;
	}
	ll ans=pre[n]-sum;
	if(ans&1)cout<<"Pico\n";
	else cout<<"FuuFuu\n";


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
5 4
6 7 8 12 17
1 1
2 1
9 0
10 1
*/