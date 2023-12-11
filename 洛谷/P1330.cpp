#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn];
bitset<maxn>vis,a,b;
int numa,numb,num;
int fla,flb,flag;
int n,m;
void dfs(int x,int fa)
{
	if(a[x]==1)numa++;
	if(b[x]==1)numb++;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		if(vis[y])
		{
			if(a[x]==a[y])fla=1;
			if(b[x]==b[y])flb=1;
		}
		else if(!vis[y]){
			vis[y]=1;
			a[y]=(a[x]^1);
			b[y]=(b[x]^1);
			dfs(y,x);
		}
		if(a[y]==a[x])fla=1;
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
	vis.reset();a.reset();
	vis[1]=1;
	fla=flb=0;
	a[1]=0;
	b[1]=1;
	dfs(1,-1);

	cout<<fla<<" "<<flb<<endl;
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