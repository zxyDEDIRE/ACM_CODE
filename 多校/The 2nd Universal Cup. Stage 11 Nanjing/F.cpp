#include<bits/stdc++.h>
using namespace std;


const int N=1e5+10;
int n,m;
int a[N];
int le[N];
vector<int>tr[N],e[N];
int ans[N];
int in[N];
void solve()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		a[i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>le[i];
		e[i].clear();
		ans[i]=0;
		in[i]=0;
		tr[i].resize(le[i]);
		for(int j=0;j<le[i];j++){
			cin>>tr[i][j];
			a[tr[i][j]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<le[i];j++){
			if(a[tr[i][j]]!=i){
				e[i].push_back(a[tr[i][j]]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		sort(e[i].begin(),e[i].end());
		e[i].erase(unique(e[i].begin(),e[i].end()),e[i].end());
		sort(e[i].begin(),e[i].end(),greater<int>());
		for(int v:e[i]){
			in[v]++;
		}
	}
	queue<int>q;
	for(int i=m;i>=1;i--){
		if(!in[i]){
			q.push(i);
		}
	}
	int tp=0;
	while(!q.empty()){
		int u=q.front();
		ans[++tp]=u;
		q.pop();
		for(int v:e[u]){
			if(--in[v]==0){
				q.push(v);
			}
		}
	}
	int f=0;
	for(int i=1;i<=m;i++){
		if(i!=ans[i]){
			f=1;break;
		}
	}
	if(f){
		cout<<"Yes\n";
		for(int i=1;i<=m;i++){
			cout<<ans[i];
			if(i<m) cout<<" ";
			else cout<<'\n';
		}
	}
	else{
		cout<<"No\n";
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}