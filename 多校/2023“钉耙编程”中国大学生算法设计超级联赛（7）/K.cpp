#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;

long long x,a,b;
map<long long,long long>mp;
long long dfs(long long x){
	long long ans=x;
	if(a<x) ans=min(ans,dfs((x+a)/2)+1);
	long long val=sqrtl(x+b);
	if((long long)val<x) ans=min(ans,dfs(val)+1);
	return ans;
}

void solve(){
	
	cin>>x>>a>>b;
	cout<<dfs(x)<<'\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
