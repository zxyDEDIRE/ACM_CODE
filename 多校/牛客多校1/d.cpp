/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const double pi=acos(-1);
const int maxn=1e6;
double r,x,y,d;
double f()
{
	double len=sqrt(x*x+y*y);
	double sum;
	if(len<=d)
	{
		sum=(pi-acos(1.0*(d-len)/r)-acos(1.0*(d+len)/r))*r;
	}
	else
	{
		sum=(acos(1.0*(len-d)/r)-acos(1.0*(len+d)/r))*r;
	}
	return sum;
}
void solve()
{
	
	scanf("%lf%lf%lf%lf",&r,&x,&y,&d);
	double sum_1=(pi-2*acos(1.0*d/r))*r;
	double sum_2=f();

	//printf("%.6lf\n%.6lf\n",sum_1,sum_2);
	printf("%.6lf\n",max(sum_1,sum_2));
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}