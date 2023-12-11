/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
double x,y,xa,ya;
double r1,r2,l1,l2;
double A()
{
	double a=x*y+xa*ya;
	double b=min(x,xa)*min(y,ya);
	a-=b;
	return 1.0*b/a;
}
double B()
{
	double a=x*y+abs(x-xa)*ya;
	double b=max(1.0*0,1.0*x-xa)*min(1.0*y,1.0*ya);
	a-=b;
	return 1.0*b/a;
}
double C()
{
	double a=x*y+abs(y-ya)*xa;
	double b=1.0*min(x,xa)*max(0*1.0,y-ya);
	a-=b;
	return 1.0*b/a;
}
double D()
{
	double a=x*y+abs(x-xa)*abs(y-ya);
	double b=max(0.0,x-xa)*max(0.0,y-ya);
	a-=b;
	return 1.0*b/a;
}
void solve()
{
	scanf("%lf%lf%lf%lf",&x,&y,&xa,&ya);
	double ans_1=x*y;
	double ans_2=0;
	if(xa<=x&&ya<=y)
	{
		double xx=max(1-(1.0*xa/x),1.0*xa/x);
		double yy=max(1-(1.0*ya/y),1.0*ya/y);
		ans_2=xx*yy;
	}
	else
	{
		ans_2=max(ans_2,A());
		ans_2=max(ans_2,B());
		ans_2=max(ans_2,C());
		ans_2=max(ans_2,D());
	}
	printf("%.5lf\n",ans_2);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}