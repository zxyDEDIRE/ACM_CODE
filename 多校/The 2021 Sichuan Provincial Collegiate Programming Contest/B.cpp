#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,k;
vector<int>tr[N];
void solve(){
	cin>>n>>k>>m;
	vector<int>ans(n+1,0);
	for(int i=1;i<=k;i++){
		tr[i].clear();
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		tr[x].push_back(i);
	}
	for(int i=1;i<=k;i++){
		int si=(int)tr[i].size();
		if(si==0) continue;
		int f=0; //最后一个还有没有
		if(si&1){
			int tp=m/(2*n);
			int nu=m%(2*n);
			int f=0;
			for(int v:tr[i]){
				if(v>nu) break;
				ans[v]+=f;
				f^=1;
			}
			for(int v:tr[i]){
				if(v+n>nu) break;
				ans[v]+=f;
				f^=1;
			}
			for(int  v:tr[i]){
				ans[v]+=tp;
			}
		}
		else{
			int tp=m/n;
			int nu=m%n;
			int f=0;
			for(int v:tr[i]){
				if(v>nu) break;
				ans[v]+=f;
				f^=1;
			}
			f=0;
			for(int v:tr[i]) {
				ans[v]+=tp*f;
				f^=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i];
		if(i<n)cout<<" ";
	}
	cout<<'\n';
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
/*

*/