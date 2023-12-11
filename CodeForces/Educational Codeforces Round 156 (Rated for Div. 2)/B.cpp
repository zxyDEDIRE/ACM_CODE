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
pii p,a,b;
double A(pii a,pii b,pii c)
{
	double dis_1 = hypot(1.0*a.first-b.first,1.0*a.second-b.second);
	double dis_2 = hypot(1.0*a.first-c.first,1.0*a.second-c.second);
	return max(dis_1,dis_2);
}
double dis(pii a,pii b)
{
	return hypot(1.0*a.first-b.first,1.0*a.second-b.second);
}
double B(pii a,pii b,pii c,pii d)
{
	double dis_1=max( dis(a,b), 0.5*dis(a,c) );
	double dis_2=max( dis(c,d), 0.5*dis(a,c) );
	return max(dis_1,dis_2);
}
void solve()
{
	cin>>p.first>>p.second;
	cin>>a.first>>a.second;
	cin>>b.first>>b.second;
	double ans=INF;
	ans=min(ans,A(a,p,{0,0}));
	ans=min(ans,A(b,p,{0,0}));
	ans=min(ans,B(a,p,b,{0,0}));
	ans=min(ans,B(b,p,a,{0,0}));
	cout << fixed << setprecision(10) <<ans<<"\n";
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