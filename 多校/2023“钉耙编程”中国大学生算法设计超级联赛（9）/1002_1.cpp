#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,mod=1e9+7;
unordered_map<long long,int>f;
int dfs1(long long n){
	if(n==1) return 0;
	if(f.count(n)) return f[n];
	int ans=1e9;
	if(n%3==0) ans=(min(dfs1(n/3)+1,ans));
	if(n%2==0) ans=(min(dfs1(n/2)+1,ans));
	if(n%3||n%2) ans=(min(dfs1(n-1)+1,ans));
	return f[n]=ans;
}
int op=0;
void solve(){
	long long n;
	cin>>n;
	cout<<dfs1(n)<<'\n';
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