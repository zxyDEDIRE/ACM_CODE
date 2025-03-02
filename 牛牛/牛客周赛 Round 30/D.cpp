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
map<int,int>f(ll x)
{
	map<int,int>mp;
	for(int i=2;i*i<=x;i++)
		if(x%i==0){
			while(x%i==0)
				mp[i]++,x/=i;
		}
	if(x!=1)mp[x]++;
	return mp;
}
void solve()
{
	ll x,y,l,r;
	cin>>x>>y>>l>>r;
	map<int,int>mpa,mpb;
	set<int>s;
	mpa=f(x);
	mpb=f(y);
	ll _x=1,_y=1;
	for(auto [x,y]:mpa)
		s.insert(x);
	for(auto [x,y]:mpb)
		s.insert(x);
	for(auto i:s)
	{
		int a=mpa[i];
		int b=mpb[i];
		int c=min(a,b);
		a-=c;b-=c;
		if(a)_x*=a*i;
		if(b)_y*=b*i;
	}
	cout<<_x<<" "<<_y<<endl;
	ll _l=1,_r=INF;
	if(_x<l)
	{
		ll now=(l+_x-1)/_x;
		_l=max(_l,now);
	}
	if(_y<l)
	{
		ll now=(l+_y-1)/_y;
		_l=max(_l,now);
	}
	if(_x>r)_r=0;
	else _r=min(_r,r/_x);

	if(_y>r)_r=0;
	else _r=min(_r,r/_y);
	if(_r>=_l)cout<<_r-_l+1<<endl;
	else cout<<0<<endl;
	// cout<<_l<<" "<<_r<<endl;
	// cout<<max(0ll,_r-_l+1)<<endl;
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
18 27 2 6
*/