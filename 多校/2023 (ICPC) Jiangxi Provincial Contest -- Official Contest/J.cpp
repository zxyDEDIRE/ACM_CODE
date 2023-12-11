#include<bits/stdc++.h>
using namespace std;


void solve(){
	int n;
	cin>>n;
	vector<long long>mx(n+1,1e18);
	for(int i=1;i<=n;i++){
		long long b;
		cin>>b;
		for(int j=0;i+j<=n&&b+j*j<=n;j++){
			mx[i+j]=min(mx[i+j],b+j*j);
		}
		for(int j=-1;i+j>=1&&b+j*j<=n;j--){
			mx[i+j]=min(mx[i+j],b+j*j);
		}
	}
	int q;
	cin>>q;
	while(q--){
		int op;
		cin>>op;
		if(op==0){
			long long i,b;
			cin>>i>>b;
			for(int j=0;i+j<=n&&b+j*j<=n;j++){
				mx[i+j]=min(mx[i+j],b+j*j);
			}
			for(int j=-1;i+j>=1&&b+j*j<=n;j--){
				mx[i+j]=min(mx[i+j],b+j*j);
			}
		}
		else{
			int x;
			cin>>x;
			cout<<mx[x]<<'\n';
		}
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	solve();
	return 0;
}