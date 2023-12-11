#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
string str,s;
bitset<maxn>vis;
int n,cnt,fl;
ll lcm(ll a,ll b){
	return a*b/__gcd(a,b);
}
void dfs(int x,int fa)
{
	cnt++;
	if(str[x-1]!=str[fa-1])fl=1;
	vis[x]=1;
	if(x==fa)return ;
	s+=str[x-1];
	dfs(p[x],fa);
}
int f(string x)
{
	string y;
	int len=x.size();
	for(int i=0,l=0;i<x.size();i++)
	{
		y+=x[i];
		l++;
		if(len%l==0)
		{
			int flag=1;
			for(int j=0;j<x.size();j++)
				if(x[j]!=y[j%l])flag=0;
			if(flag)return len;
		}
	}
	return len;
}
void solve()
{
	cin>>n>>str;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	vis.reset();
	ll ans=1;
	vector<ll>v;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		cnt=0;
		s=str[i-1];
		dfs(p[i],i);
		cout<<s<<endl;
		v.push_back(f(s));
	}
	ans=v[0];
	for(int i=1;i<v.size();i++)
		ans=lcm(ans,v[i]);
	cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}
/*
2
4
abab
2 3 4 1
6
abcabc
2 3 1 5 6 4

1
8
abacabac
2 3 4 1 6 7 8 5
*/