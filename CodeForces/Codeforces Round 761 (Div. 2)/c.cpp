/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
bitset<maxn>vis;
vector<int>v;
vector<int>q;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	v.clear();
	q.clear();
	vis.reset();
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]<=n)
		{
			if(!vis[p[i]])vis[p[i]]=1;
			else v.push_back(p[i]);
		}
		else v.push_back(p[i]);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])q.push_back(i);

	sort(v.begin(),v.end());

	// for(auto i:q)cout<<i<<" ";cout<<endl;
	// for(auto i:v)cout<<i<<" ";cout<<endl;


	int ans=0;
	for(int i=0;i<q.size();i++)
	{
		if(v[i]>q[i]*2)
		{
			ans++;
		}
		else 
		{
			cout<<-1<<endl;
			return ;
		}
	}
	cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}
/*
1 2 3 4 5 6 7 
1 2 3 4 5 6 7 18 19
*/