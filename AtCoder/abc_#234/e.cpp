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
vector<ll>v;
map<ll,bool>mp;
ll n;
void  dfs(ll x,ll fl,ll sum)
{
	
	if(!mp[sum])v.push_back(sum),mp[sum]=1;
	if(sum>n)return ;
	ll y=x+fl;
	if(y>=0&&y<=9)
	{
		dfs(y,fl,sum*10+y);
	}
}
void solve()
{
	cin>>n;
	for(int i=-9;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			dfs(j,i,j);
		}
	}
	sort(v.begin(),v.end());
	int fl=lower_bound(v.begin(),v.end(),n)-v.begin();
	cout<<v[fl]<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}