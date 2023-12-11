#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long k;
string s[N];
long long pw[N];
map<int,int>mp[21][N];//存中断点
void dfs1(int id,int l,int r){
	if(id==m){
		return;
	}
	for(int i=l+1;i<=r;i++){
		if(s[i][id]=='B'){
			mp[id][l][r]=i;
			break;
		}
	}
	if(mp[id][l].count(r)==false){
		dfs1(id+1,l,r);
	}
	else{
		int x=mp[id][l][r];
		dfs1(id+1,l,x-1);dfs1(id+1,x,r);
	}
}
void clear(int id,int l,int r){
	if(id==m){
		return;
	}
	if(mp[id][l].count(r)==false){
		dfs1(id+1,l,r);
	}
	else{
		int x=mp[id][l][r];
		dfs1(id+1,l,x-1);dfs1(id+1,x,r);
		mp[id][l].clear();
	}
}
const int M=(1<<21);
long long vis[M];

void dfs(int id,int l,int r,long long res,int tp){
	if(id==m){
		
	}
	if(mp[id][l].count(r)==false){
		dfs(id+1,l,r,res,tp);
		return;
	}
	else{
		int x=mp[id][l][r];
		long long add=1ll*(x-l)*(r-x+1);
		dfs(id+1,l,x-1,res,tp);
		dfs(id+1,x,r,res,tp);
		dfs(id+1,l,x-1,res+add,tp);
		dfs(id+1,x,r,res+add,tp);
	}

	}

void solve()
{
	pw[0]=1;
	for(int i=1;i<=22;i++){
		pw[i]=pw[i-1]*2;
	}
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=0;i<m;i++){
		sort(s+1,s+n+1);
		dfs1(i,1,n);
		dfs(i,1,n,0,(1<<i));
		clear(i,1,n);
		for(int j=1;j<=n;j++){
			s[j][i]='A';
		}
	}
	int ans=0;
	for(int i=0;i<(1<<m);i++){
		if(vis[i]>=k){
			ans++;
		}
	}
	cout<<ans<<'\n';

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}
