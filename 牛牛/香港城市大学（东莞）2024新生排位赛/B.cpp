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
struct point{
	long double x,y,z;
	point(){
		cin>>x>>y>>z;
	}
	point(long double a,long double b,long double c):x(a),y(b),z(c){}
};
point h(point a,point b)
{ 
	point t(b.x-a.x,b.y-a.y,b.z-a.z);
	return t;
}
point f(point a,point b,point c)
{
	point x=h(a,b);
	point y=h(a,c);
	point t(0,0,0);
	t.x = x.y*y.z - y.y*x.z;
	t.y = x.z*y.x - y.z*x.x;
	t.z = x.x*y.y - y.x*x.y;
	return t;
}
long double mo(point a)
{
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}
int er (long double n)
{
  // 若为负数，则先化为正数再进行四舍五入
  if (n > 0)
    return n - int(n) >= 0.5 ? int(n)+1 : int(n);
  else
    return -n - int(-n) >= 0.5 ? -(int(-n) + 1) : -int(-n);
}
void solve()
{
	point a,b,c,d;
	point x = f(a,b,c);
	point y = f(b,c,d);

	long double ra = x.x*y.x + x.y*y.y + x.z*y.z;
	long double rb = mo(x) * mo(y);
	long double ans = (ra/rb);
	ans = acos(ans)*180/3.1415;
	cout<<er(ans)<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}