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
string str;
ll n,k;
void solve()
{
	cin>>n>>k>>str;
	ll x=0,y=0,ans=0;
	ll _x=0,_y=0;
	for(auto i:str)
	{
		if(i=='U')y++;
		else if(i=='D')y--;
		else if(i=='L')x--;
		else x++;
		ans=max(ans,abs(x)+abs(y));
	}
	_x=x*(k-1);
	_y=y*(k-1);
	x=0,y=0;
	for(auto i:str)
	{
		if(i=='U')y++;
		else if(i=='D')y--;
		else if(i=='L')x--;
		else x++;
		ans=max(ans,abs(x+_x)+abs(y+_y));
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
1
4 1
ULRD
*/