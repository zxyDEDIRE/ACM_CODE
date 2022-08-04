#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
bitset<maxn>vis;
string str,s;
int p[maxn];
int n;
ll lcm(ll x,ll y){
	return x*y/__gcd(x,y);
}
void dfs(int x)
{
	if(vis[x])return ;
	vis[x]=1;
	s+=str[x-1];
	dfs(p[x]);
}
int f(string x)
{
	int len=x.size(),le,fl;
	string y="";
	for(int i=0;i<len;i++)
	{
		y+=x[i];le=i+1;fl=1;
		if(len%le==0){
			for(int j=0;j<len;j++)
				if(x[j]!=y[j%le])fl=0;
			if(fl)return le;
		}
		
	}
	return len;
}
void solve()
{
	cin>>n>>str;
	for(int i=1;i<=n;i++)cin>>p[i];


	vis.reset();
	vector<ll>v;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		s=str[i-1];
		vis[i]=1;
		dfs(p[i]);
		v.push_back(f(s));
	//	cout<<s<<" "<<f(s)<<endl;
	}
	ll ans=v[0];
	for(int i=1;i<v.size();i++)
		ans=lcm(ans,v[i]);
	cout<<ans<<endl;
}
int main()
{
	int __;cin>>__;
	while(__--)solve();
}