#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
long long vv,t;
void solve(){
	cin>>a>>b>>c>>d>>vv>>t;
	long long lc=a/__gcd(a,c)*c;
	vector<long long>v;
	v.push_back(0);
	for(long long x=a;x<=lc;x+=a){
		v.push_back(x);
	}
	for(long long x=c;x<=lc;x+=c){
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int n=(int)v.size();
	vector<long long>sum(n,0);
	for(int i=1;i<n;i++){
		long long cnt=v[i]-v[i-1];
		if(v[i]%a==0&&v[i]%c==0){
			if(cnt<=vv) sum[i]=b+d;
			else sum[i]=b+d-1;
		}
		else if(v[i]%a==0){
			if(cnt<=vv) sum[i]=b;
			else sum[i]=b-1;
		}
		else{
			if(cnt<=vv) sum[i]=d;
			else sum[i]=d-1;
		}
		sum[i]+=sum[i-1];
	}
	long long ans=d+b-1;
	ans+=t/lc*sum[n-1];
	t%=lc;
	int tt=upper_bound(v.begin(),v.end(),t)-v.begin();
	ans+=sum[tt-1];
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