#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
double x[maxn],y[maxn];
int n,m,k;
double db(double x)
{
    return x*x;
}
double get(double x1,double y1,double x2,double y2)
{
    return sqrt(db(x1-x2)+db(y1-y2));
}
struct SaDown{
	//退火系数
	#define down 0.996
	double ansx,ansy,answ;
	//评估函数
	double energy(double xx,double yy){
	    double r=min(xx,n-xx);
		r=min(r,min(yy,m-yy));
		for(int i=1;i<=k;i++)
		{
		   r=min(r,get(x[i],y[i],xx,yy));
		}
		return r;
	}
	void sa()
	{
		double t=3000;
		while(t>1e-15)
		{
			// cout<<ansx<<" "<<ansy<<" "<<answ<<endl;
			double ex=ansx+(rand()*2-RAND_MAX)*t;
			double ey=ansy+(rand()*2-RAND_MAX)*t;
			double ew=energy(ex,ey);
			double de=ew-answ; 
			if(answ<ew)
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
	void doit(){
		//退火次数
		for(int i=1;i<=4;i++)
			sa();
	}
}sa,sb;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		scanf("%lf%lf",&x[i],&y[i]);
		sa.ansx+=x[i];
		sa.ansy+=y[i];
	}
	sa.ansx=n/2;
	sa.ansy=m/2;
	sa.answ=sa.energy(sa.ansx,sa.ansy);
	cout<<sa.ansx<<" "<<sa.ansy<<" "<<sa.answ<<endl;
	sa.doit();
	printf("%.3lf\n",sa.answ);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}