#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
long double n;
int main()
{
	cin>>n;
	long double a=1.0*(1+sqrt(5))/2;
	long double b=1.0*(1-sqrt(5))/2;
	long double x=1,y=1;
	for(int i=1;i<=n;i++)
	{
		x*=a;
		y*=b;
	}
	long double ans=(x-y)/sqrt(5);
	printf("%.2Lf",ans);
}