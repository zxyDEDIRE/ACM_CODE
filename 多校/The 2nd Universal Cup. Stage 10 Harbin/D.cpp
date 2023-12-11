#include<bits/stdc++.h>
using namespace std;

const int N=1e6+100;
vector<int>tr[N];
bool vis[N];
int q[N],cnt;
void init(int n=N-10){
	vis[1]=true;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			q[cnt++]=i;
		}
		for(int j=0;1ll*q[j]*i<=n;j++){
			int nu=q[j]*i;
			vis[nu]=true;
			if(i%q[j]==0){
				break;
			}
		}
	}
	for(int i=0;i<cnt;i++){
		for(int j=q[i];j<=n;j+=q[i]){
			tr[j].push_back(q[i]);
		}
	}
}


map<vector<int>,int>mp;
vector<int>vr;
int res;
void dfs(int id,int nu,int le,int x){
	if(id==le){
		if(nu==0) return;
		if(mp.count(vr)==true){
			res=min(res,le+mp[vr]);
			mp[vr]=min(mp[vr],le-nu);
		}
		else{
			mp[vr]=le-nu;
		}
		return;
	}
	vr.push_back(tr[x][id]);
	dfs(id+1,nu+1,le,x);;
	vr.pop_back();
	dfs(id+1,nu,le,x);
}

void solve(){
	long long ans=0;
	int l,r;
	cin>>l>>r;
	mp.clear();
	int tn=0,mi=1e9;
	vector<int>tp(r-l+1,1e9);
	for(int i=l;i<=r;i++){
		int le=(int)tr[i].size();
		vr.clear();
		res=1e9;
		dfs(0,0,le,i);
		if(res!=1e9){
			tp[i-l]=min(res,tp[i-l]);
		}

	}
	mp.clear();
	for(int i=r;i>=l;i--){
		int le=(int)tr[i].size();
		vr.clear();
		res=1e9;
		dfs(0,0,le,i);
		if(res!=1e9){
			tp[i-l]=min(res,tp[i-l]);
		}
	}
	long long sum=0;
	int mx1=0,mx2=0;
	for(int i=l;i<=r;i++){
		if(tp[i-l]==1e9){
			int le=(int)tr[i].size();
			sum+=le;
			if(mx1<=le){
				mx2=mx1;mx1=le;
			}
			else{
				mx2=max(mx2,le);
			}
		}
		else{
			ans+=tp[i-l];
		}
	}
	ans+=sum+sum-mx1-mx2;
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	init();
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}

	return 0;
}