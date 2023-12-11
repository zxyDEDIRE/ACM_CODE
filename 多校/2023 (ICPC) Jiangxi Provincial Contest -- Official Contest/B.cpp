#include<bits/stdc++.h>
using namespace std;

void solve(){
	int k;
	int n,m,x;
	cin>>k;
	vector<long long>a(k+1),sum(k+1,0);
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	cin>>n>>m>>x;
	for(int i=1;i<=k;i++){
		a[i]%=m;
		sum[i]=sum[i-1]+a[i];
	}
	x%=m;
	__int128 ans=sum[k];
	ans*=n/k;
	ans+=x;
	ans+=sum[n%k];
	cout<<(long long)(n-ans/m)<<'\n';
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	solve();
	return 0;
}