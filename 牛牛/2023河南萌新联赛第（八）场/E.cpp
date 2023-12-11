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
double n;
pii f(double &x1,double &y1,double x0,double y0,double d)
{
	d=d/180*acos(-1);//如果是360一周
	double x=(x1-x0)*cos(d)-(y1-y0)*sin(d)+x0;
	double y=(x1-x0)*sin(d)+(y1-y0)*cos(d)+y0;
	cout<<x<<" "<<y<<endl;
	x1=x,y1=y;
	return {x,y};
}
void solve()
{
	cin>>n;
	double l1=1.0*n*sin(18);
	double l2=1.0*l1/tan(36);
	double sx=0,sy=-l2;
	double tx=0,ty=1.0*n*cos(18);
	f(tx,ty,sx,sy,-72);
	f(tx,ty,sx,sy,-72);
	f(tx,ty,sx,sy,-72);
	f(tx,ty,sx,sy,-72);
	f(tx,ty,sx,sy,-72);
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}