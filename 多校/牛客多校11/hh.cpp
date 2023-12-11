/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<long,long>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
pii operator +(pii &a,pii &b){
	return {a.first+b.first,a.second+b.second};
}
pii operator *(pii &a,int b){
	return {a.first*b,a.second*b};
}
vector<int>v[maxn];
int dep[maxn],siz[maxn];
pii dp[maxn];
pii p[maxn];
int n,q;
void dfs1(int x,int fa)
{
	siz[x]=1;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs1(y,x);
		siz[x]+=siz[y];
	}
	pii t=dp[fa]*(siz[fa]-siz[x]);
	dp[x]=dp[x]+t;
	cout<<x<<" "<<fa<<endl;
	cout<<dp[x].first<<" "<<dp[x].second<<endl;
	cout<<dp[fa].first<<" "<<dp[fa].second<<" "<<siz[fa]<<" "<<siz[x]<<endl;
	cout<<dp[x].first<<" "<<dp[x].second<<endl;
	cout<<endl;
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		int t=i;
		while(t%2==0)p[i].first++,t/=2;
		while(t%5==0)p[i].second++,t/=5;
		dp[i]=p[i];
	}
	cout<<endl;
	dfs1(1,1);
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}