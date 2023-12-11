/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<pii>v[maxn];
int ans[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		v[i].clear();
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		int L=i/(p[i]+1)+1;
		int R=p[i]==0?n:i/p[i];
		v[L].push_back({R,i});
	}
	set<pii>s;
	for(int i=1;i<=n;i++)
	{
		for(auto j:v[i])
			s.insert(j);
		auto x=*s.begin();
		ans[x.second]=i;
		s.erase(x);
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
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