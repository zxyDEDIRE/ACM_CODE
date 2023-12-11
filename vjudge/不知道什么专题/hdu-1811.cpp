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
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
vector<int>v[maxn],G[maxn];
bitset<maxn>vis;
int in[maxn];
int p[maxn];
int n,m,fa,fb;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void topsort()
{
	vis.reset();
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		if(q.size()>1)fb=1;
		int x=q.front();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto y:G[x])
			if(!vis[y])
				q.push(y);
		for(auto y:v[x])
		{
			in[y]--;
			if(!in[y])
				q.push(y);
		}
	}
	for(int i=1;i<=n;i++)
		if(in[i])fb=1;
}
void solve()
{
	cin>>n>>m;
	{
		fa=fb=0;
		for(int i=1;i<=n;i++)
			p[i]=i,in[i]=0,v[i].clear(),G[i].clear();
		for(int i=1;i<=m;i++)
		{
			int x,y;char ch;
			cin>>x>>ch>>y;
			x++,y++;
			int fa=find(x);
			int fb=find(y);
			if(fa!=fb)p[fa]=fb;
			if(ch=='>')
			{
				v[y].push_back(x);
				in[x]++;
			}
			else if(ch=='<')
			{
				v[x].push_back(y);
				in[y]++;
			}
			else G[x].push_back(y),G[y].push_back(x);
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(p[i]==i)
				cnt++;
		cout<<cnt<<endl;
		if(cnt!=1)fa=1;
		topsort();

		if(!fa&&!fb)cout<<"OK"<<endl;
		else if(fa&&!fb)cout<<"UNCERTAIN"<<endl;
		else if(!fa&&fb)cout<<"CONFLICT"<<endl;
		else cout<<"CONFLICT"<<endl;




	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}