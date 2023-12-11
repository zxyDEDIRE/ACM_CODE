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
	double x,y,z;
}a[maxn];
double ansx,ansy,ansz,answ;
int n;
struct SaDown{
	//退火系数
	#define down 0.996
	//评估函数
	double energy(double x,double y,double z)
	{
		double r=0;
		for(int i=1;i<=n;i++)
		{
			r=max(r,sqrt((x-a[i].x)*(x-a[i].x)+(y-a[i].y)*(y-a[i].y)+(z-a[i].z)*(z-a[i].z)));
		}
		return r;
	}
	void sa()
	{
		double t=3000;
		while(t>1e-15)
		{
			double ex=ansx+(rand()*2-RAND_MAX)*t;
			double ey=ansy+(rand()*2-RAND_MAX)*t;
			double ez=ansz+(rand()*2-RAND_MAX)*t;
			double ew=energy(ex,ey,ez);
			double de=ew-answ;
			if(answ>ew)
			{
				ansx=ex;
				ansy=ey;
				ansz=ez;
				answ=ew;
			}
			else if(exp(-de/t)*RAND_MAX>rand())
			{
				ansx=ex;
				ansy=ey;
				ansz=ez;
			}
			t*=down;
		}
	}
	void doit(){
		for(int i=1;i<=1;i++)
			sa();
	}
}sa;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
		// cin>>a[i].x>>a[i].y>>a[i].z;
		ansx+=a[i].x;
		ansy+=a[i].y;
		ansz+=a[i].z;
	}
	ansx/=n;
	ansy/=n;
	ansz/=n;
	// cout<<ansx<<" "<<ansy<<" "<<ansz<<endl;
	answ=sa.energy(ansx,ansy,ansz);
	sa.doit();
	// cout<<ansx<<" "<<ansy<<" "<<ansz<<endl;
	// cout<<answ<<endl;
	printf("%.3lf\n",answ);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}