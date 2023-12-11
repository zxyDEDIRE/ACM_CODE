/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn];
int dep[maxn],fa[maxn],siz[maxn];
int n,ma_d,ma_s,s,t;
void dfs(int x,int deep,int faa)
{
	fa[x]=faa;
	dep[x]=deep;
	ma_d=max(ma_d,deep);
	siz[deep]++;
	ma_s=max(ma_s,siz[deep]);
	for(auto y:v[x])
	{
		if(y==faa)continue;
		dfs(y,deep+1,x);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,1,1);
	cin>>s>>t;
	cout<<ma_d<<"\n"<<ma_s<<endl;

	int ans=0;
	while(s!=t)
	{
		if(dep[s]>dep[t])ans+=2,s=fa[s];
		else if(dep[t]>dep[s])ans+=1,t=fa[t];
		else ans+=3,s=fa[s],t=fa[t];
	}
	cout<<ans<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}