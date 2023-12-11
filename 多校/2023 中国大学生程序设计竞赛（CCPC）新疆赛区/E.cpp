#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define double long double
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
class Point{
public:
	double x,y;
	Point(){}
	Point(double _a,double _b):x(_a),y(_b){}
	void in(){
		cin>>x>>y;
		// x=rand();
		// y=rand();
	}
}p[110];
class Round{
public:
	double x,y,r;bool ok;
	double eps=1e-6;
	Round(){}
	Round(Point a,Point b,Point c){
		double _A=a.x*(b.y-c.y)-a.y*(b.x-c.x)+b.x*c.y-c.x*b.y;
		double _B=(a.x*a.x+a.y*a.y)*(c.y-b.y)+(b.x*b.x+b.y*b.y)*(a.y-c.y)+(c.x*c.x+c.y*c.y)*(b.y-a.y);
		double _C=(a.x*a.x+a.y*a.y)*(b.x-c.x)+(b.x*b.x+b.y*b.y)*(c.x-a.x)+(c.x*c.x+c.y*c.y)*(a.x-b.x);
		double _D=(a.x*a.x+a.y*a.y)*(c.x*b.y-b.x*c.y)+(b.x*b.x+b.y*b.y)*(a.x*c.y-c.x*a.y)+(c.x*c.x+c.y*c.y)*(b.x*a.y-a.x*b.y);
		x=-_B/(2*_A);
		y=-_C/(2*_A);
		r=sqrt((_B*_B+_C*_C-4*_A*_D)/(4*_A*_A));
		ok=(_A!=0);
	}
	bool on(Point a){
		double dis=hypot(a.x-x,a.y-y);
		return abs(dis-r)<eps;
	}
	bool isok(){
		return ok;
	}
};
int n;
void solve()
{
	cin>>n;
	// n=100;srand(time(0));
	for(int i=1;i<=n;i++)
		p[i].in();
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++){
				Round now(p[i],p[j],p[k]);
				if(!now.isok())continue;
				int num=0;
				for(int l=1;l<=n;l++)
					if(now.on(p[l]))
						num++;
				ans=max(ans,num);
			}
	cout<<n-ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}