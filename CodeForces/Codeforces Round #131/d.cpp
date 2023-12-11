/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct node{
	int id,len;
	bool operator<(const node&a)const{
		return a.len<len;
	}
};
bitset<maxn>vis;
bitset<maxn>ok;
vector<int>v[maxn];
int ans[maxn];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	vis.reset();
	ok.reset();
	priority_queue<node>q;
	for(int i=1;i<=n;i++)
		v[i].clear();
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i])
		{
			int s=i/(p[i]+1)+1;
			while((i/s)==p[i])
			{
				v[i].push_back(s);
				s++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int len=v[i].size();
		if(len)q.push({i,len});
		// cout<<i<<endl;
		// for(int j=0;j<v[i].size();j++)
		// 	cout<<v[i][j]<<"  ";
		// cout<<endl;
	}
	while(!q.empty())
	{
		auto [x,len]=q.top();q.pop();
		vector<int>q;
		ok[x]=1;
		for(int i=0;i<v[x].size();i++)
		{
			int y=v[x][i];
			if(vis[y])continue;
			ans[x]=y;
			vis[y]=1;
			break;
		}
	}
	int s=1;
	for(int i=1;i<=n;i++)
	{
		if(ok[i])continue;
		while(vis[s])s++;
		ans[i]=s;
		vis[s]=1;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
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
5

11
3
*/