#include<bits/stdc++.h>
using namespace std;

void solve()
{
	long long h,m,a;
	cin>>h>>m>>a;
	long long t=h*m;
	if(t%2==0&&t/2==a){
		cout<<t<<'\n';
	}
	else{
		long long gc=__gcd(h-1,t);
		long long w=(a)/gc;
		cout<<gc+(w)*gc*2<<'\n';
	}
}
int main(){
	solve();
	return 0;
}