#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
#define double long double
double a[N],b[N];
double x=1e-18;
void solve()
{
	int n,m;
	cin>>n>>m;
	double ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		ans+=a[i]*log(1.0+b[i]*x)/pow(x,m);
	}
	printf("%.100Lf",ans);
}
/*
3 1
100 1
100 2
100 -3
*/
int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __=1;
	while(__--)
		solve();
	return 0;
}