#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n;
int a[N];
long long pw[65];
bool check(long long x){
	__int128 t=1;
	for(int i=0;i<n;i++){
		if(t%x!=a[i]) return false;
		t=t*2;
		if(t>=x) t-=x;
	}
	return true;
}
void solve(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int mx=1;
	int L=-1;
	for(int i=0;i<n;i++){
		if(pw[i]!=a[i]){
			L=i;break;
		}
		else{
			mx=pw[i]+1;
		}
	}
	if(L!=-1){
		if(pw[L]<a[L]){
			cout<<"-1\n";
			return ;
		}
		long long cnt=pw[L]-a[L];
		vector<long long>pr;
		vector<long long>ans;
		for(long long j=1;1ll*j*j<=cnt;j++){
			if(cnt%j==0){
				if(j>=mx&&check(j)){
					ans.push_back(j);
				}
				if(cnt/j!=j&&cnt/j>=mx&&check(cnt/j)){
					ans.push_back(cnt/j);
				}
			}
		}
		if((int)ans.size()!=1)
			cout<<-1<<'\n';
		else{
			cout<<ans[0]<<'\n';
		}
	}
	else
		cout<<-1<<'\n';
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cout.tie(0);
	pw[0]=1;
	for(int i=1;i<=60;i++){
		pw[i]=pw[i-1]*2ll;
	}
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}