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
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int x,y,w;
}a[maxn];
double ansx,ansy,answ;
int n;
struct SaDown{
	#define down 0.996
	double energy(double x,double y)
	{
		double r=0,dx,dy;
		for(int i=1;i<=n;i++)
		{
			dx=x-a[i].x;
			dy=y-a[i].y;
			r+=sqrt(dx*dx+dy*dy)*a[i].w;
		}
		return r;
	}
	void sa()
	{
		// srand(time(0));
		double t=3000;
		while(t>1e-15)
		{
			double ex=ansx+(rand()*2-RAND_MAX)*t;
			double ey=ansy+(rand()*2-RAND_MAX)*t;
			double ew=energy(ex,ey);
			double de=ew-answ;
			if(de<0)
			{
				ansx=ex;
				ansy=ey;
				answ=ew;
			}
			else if(exp(-de/t)*RAND_MAX>rand())
			{
				ansx=ex;
				ansy=ey;
			}
			t*=down;
		}
	}
}sa;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].w;
		ansx+=a[i].x;
		ansy+=a[i].y;
	}
	ansx/=n;
	ansy/=n;
	answ=sa.energy(ansx,ansy);
	sa.sa();sa.sa(),sa.sa();sa.sa();
	printf("%.3lf %.3lf\n",ansx,ansy);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}