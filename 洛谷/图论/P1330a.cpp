#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn];
bitset<maxn>vis,a,b;
int n,m,fla,flb,na,nb,num;
void dfs(int x,int fa)
{
	if(a[x]==1)na++;
	if(b[x]==1)nb++;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		if(vis[y])
		{
			if(a[x]==a[y])fla=1;
			if(b[x]==b[y])flb=1;
		}
		else if(!vis[y])
		{
			a[y]=(a[x]^1);
			b[y]=(b[x]^1);
			vis[y]=1;
			dfs(y,x);
		}
		if(a[x]==a[y])fla=1;
		if(b[x]==b[y])flb=1;
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	vis.reset();
	a.reset();
	b.reset();
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			fla=flb=na=nb=0;
			b[i]=1;
			a[i]=0;
			vis[i]=1;
			dfs(i,-1);
			if(fla)na=1e7;
			if(flb)nb=1e7;
			num+=min(na,nb);
		}
	}
	if(num>=1e7)cout<<"Impossible"<<endl;
	else cout<<num<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;
//    cin>>__;
	__=1;
	while(__--)solve();
	return 0;
}