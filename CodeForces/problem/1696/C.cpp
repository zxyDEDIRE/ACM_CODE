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
ll p[maxn];
ll t[maxn];
int n,k,m;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>t[i];

	vector<pii>v;
	for(int i=1;i<=n;i++)
	{
		if(p[i]%k==0)
		{
			if(!v.size())v.push_back({p[i]/k,1});
			else
			{
				auto [x,fl]=v.back();
				if(!fl)v.push_back({p[i]/k,1});
				else if((p[i]/k)%m==0)
				{
					v.back().first+=p[i]/k;
				}
				else v.push_back({p[i]/k,1});
			}
		}
		else v.push_back({p[i],0});
	}
	vector<pii>vv;
	for(int i=1;i<=m;i++)
	{
		if(t[i]%k==0)
		{
			if(!vv.size())vv.push_back({t[i]/k,1});
			else
			{
				auto [x,fl]=vv.back();
				if(!fl)vv.push_back({t[i]/k,1});
				else if((t[i]/k)%m==0)
				{
					v.back().first+=t[i]/k;
				}
				else v.push_back({t[i]/k,1});
			}
		}
		else vv.push_back({t[i],0});
	}
	if(v!=vv)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}