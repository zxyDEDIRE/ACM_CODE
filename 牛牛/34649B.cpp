#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e4;
vector<int>v[maxn];
bool a[maxn],b[maxn];
bitset<maxn>vis;
int mt[maxn];
int n;
void init(){
	for(int i=1;i<=n;i++){
		v[i].clear();
		mt[i]=0;
	}
}
bool dfs(int x){
	if(vis[x])return 0;
	vis[x]=1;
	for(auto y:v[x]){
		if(!mt[y]||dfs(mt[y])){
			mt[y]=x;
			return 1;
		}
	}
	return 0;
}
void solve()
{
	cin>>n;
	init();
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	int tot=0,sum=0;
	vector<int>p;
	for(int i=1;i<=n;i++){
		if(!a[i]||(a[i]&&!b[i])){
			tot++;
			p.push_back(i);
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			if(x&&a[j])v[i].push_back(j);
			else if(i==j&&a[j])v[i].push_back(i);
		}
	}
	// for(int i=1;i<=n;i++){
	// 	if(!a[i]||(a[i]&&!b[i])){
	// 		vis.reset();
	// 		if(dfs(i))sum++;
	// 	}
	// }
	// if(tot==sum)cout<<"^_^"<<endl;
	// else cout<<"T_T"<<endl;
	for(auto i:p){
		vis.reset();
		if(!dfs(i)){
			cout<<"T_T"<<endl;
			return ;
		}
	}
	cout<<"^_^"<<endl;
}
int main(){
	int __;cin>>__;
	while(__--)solve();
}