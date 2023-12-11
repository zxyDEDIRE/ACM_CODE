#include<bits/stdc++.h>
using namespace std;
long long get(long long h,long long m,long long a)
{
	long long t=h*m;
	if(t%2==0&&t/2==a){
		return t;
	}
	else{
		long long gc=__gcd(h-1,t);
		long long w=(a)/gc;
		return gc+gc*2*w;
	}
	return 0;
}
void solve()
{
	long long h,m,a;
	// cin>>h>>m>>a;
	long long ans=0;
	for(h=2;h<=50;h++){
		for(m=2;m<=50;m++){
			for(a=0;a<=h*m/2;a++){
				for(long long k=0;k<h*m;k++){
					long long val=(h-1)*k%(h*m);
					long long val1=h*m-val%(h*m);
					val1%=(h*m);
					if(val<=a||val1<=a){
						ans++;
					}
				}
				if(ans!=get(h,m,a)){
					cout<<h<<" "<<m<<" "<<a<<" "<<ans<<" "<<get(h,m,a)<<'\n';
				}
				ans=0;
			}
		}
	}
}
int main(){
	solve();
	return 0;
}