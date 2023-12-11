#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=5e6+10;
unordered_map<long long,int>f;
int dp[N];
int dfs1(long long n,int s){
	if(n<=N-10) return dp[n];
	if(s>70) return 100;
	if(n<=1) return 0;
	if(n<=3) return 1;
	if(f.count(n)) return f[n];
	int ans=1e9;
	if(n%3==0) ans=(min(dfs1(n/3,s+1)+1,ans));
	if(n%2==0) ans=(min(dfs1(n/2,s+1)+1,ans));
	int t=n%3;
	if(t) ans=(min(dfs1(n-t,s+1)+t,ans));
	if(n&1) ans=(min(dfs1(n-1,s+1)+1,ans));
	return f[n]=ans;
}
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());//ull  大概率生成不相同数据
// int getRand(int l,int r){
//     uniform_int_distribution < int > uid(l,r);
//     return uid(rng);
// }
void solve(){
	long long n;
	cin>>n;
	// n=getRand(1e9,1e18);
	int t=dfs1(n,0);
	cout<<t<<'\n';
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for(int i=2;i<=N-10;i++){
		dp[i]=dp[i-1]+1;
		if(i%2==0) dp[i]=min(dp[i],dp[i/2]+1);
		if(i%3==0) dp[i]=min(dp[i],dp[i/3]+1);
	}
	int t=1;
	cin>>t;
	// t=2000;
	while(t--){
		solve();
	}
	return 0;
}