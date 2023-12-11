/*
	有多少个四元组(a,t,b,k)满足下面式子
	a^t+b^k=n
	且a,b,t,k>=2
	n<=1e9
*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	long long ans=0;
	map<long long,int>mp;
	for(int a=2;;a++){
		long long c=1ll*a*a;
		if(c>=n) break;
		for(int t=2;c<n;t++,c=c*a){
			mp[c]++;
			c=c*a;
		}
	}
	for(int a=2;;a++){
		long long c=1ll*a*a;
		if(c>=n) break;
		for(int t=2;c<n;t++,c=c*a){
			ans+=mp[n-c];
			c=c*a;
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}