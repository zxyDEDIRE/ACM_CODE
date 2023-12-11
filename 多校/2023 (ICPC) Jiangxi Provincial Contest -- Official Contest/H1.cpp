#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int q=a[1],res=1;
	vector<int>v;
	map<int,int>mp;
	for(int i=2;i<=n;i++){
		if(a[i]<q){
			res++;
		}
		else{
			mp[res]++;
			res=1;
			q=a[i];
		}
	}
	mp[res]++;
	for(auto [x,y]:mp){
		int cnt=1;
		while(cnt<y){
			v.push_back(x*cnt);
			y-=cnt;
			cnt<<=1;
		}
		v.push_back(x*y);
	}
	vector<bool>dp(n/2+2,false);
	dp[0]=true;
	for(auto i:v)
	{
		for(int j=n/2;j>=i;j--)
		{
			dp[j]=dp[j]|dp[j-i];
		}
	}
	cout<<(dp[n/2]?"Yes\n":"No\n");
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