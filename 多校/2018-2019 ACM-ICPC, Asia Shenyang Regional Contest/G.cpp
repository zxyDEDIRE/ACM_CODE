#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
const int mod=6000;
vector<pair<int,int>>tr[N];
map<pair<int,int>,int>mp;
void solve(){
	int n,q;
	cin>>n>>q;
	mp.clear();
	for(int i=1;i<=n;i++){
		int x,y,w;
		cin>>x>>y>>w;
		if(mp.count({x,y})) mp[{x,y}]+=w;
		else
			mp[{x,y}]=w;
	}
	long long ans=0;
	while(q--){
		int op,x,y;
		cin>>op>>x>>y;
		x=(x+ans%mod)%mod+1;
		y=(y+ans%mod)%mod+1;
		if(op==1){
			int w;
			cin>>w;
			mp[{x,y}]=w;
		}
		else if(op==2){
			mp.erase({x,y});
		}
		else if(op==3){
			int k,w;
			cin>>k>>w;
			for(auto [x1,y1]:tr[k]){
				if(x1+x>=1&&x1+x<=6000&&y+y1>=1&&y+y1<=6000
					&&mp.count({x+x1,y+y1})){
					mp[{x+x1,y+y1}]+=w;
				}
			}
		}
		else{
			int k;
			cin>>k;
			long long ans1=0;
			for(auto [x1,y1]:tr[k]){
				if(x1+x>=1&&x1+x<=6000&&y+y1>=1&&y+y1<=6000
					&&mp.count({x+x1,y+y1}))
					ans1=(ans1+mp[{x1+x,y+y1}]);
				}
			ans=ans1;
			cout<<ans<<'\n';
		}
	}
}


int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	for(int i=0;i<=6000;i++){
		for(int j=0;j<=6000;j++){
			long long w=1ll*i*i+1ll*j*j;
			if(w>1e7)
				break;
			if(i==0&&j==0){
				tr[w].push_back({i,j});
			}
			else if(i==0){
				tr[w].push_back({i,j});
				tr[w].push_back({i,-j});
			}
			else if(j==0){
				tr[w].push_back({-i,j});
				tr[w].push_back({i,j});
			}
			else{
				tr[w].push_back({i,j});
				tr[w].push_back({i,-j});
				tr[w].push_back({-i,j});
				tr[w].push_back({-i,-j});
			}
		}
	}
	cin>>t;
	for(int i=1;i<=t;i++){
		cout<<"Case #"<<i<<":\n";
		solve();
	}
	return 0;
}