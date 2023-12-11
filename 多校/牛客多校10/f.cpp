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
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
vector<int>v[maxn];
bitset<maxn>vis;
int num[maxn];
int p[maxn];
int n,m,s,t;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void YES(){
	cout<<"Join Player"<<endl;
}
void NO(){
	cout<<"Cut Player"<<endl;
}
void solve()
{
	cin>>n>>m>>s>>t;
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
		v[i].clear();
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	queue<int>q;
	q.push(t);
	vis.reset();
	memset(num+1,0,sizeof(int)*n);
	while(!q.empty())
	{
		
		int x=q.front();q.pop();
		if(vis[x])continue; 
		vis[x]=1;
		if(x==s)return YES();
		for(auto y:v[x])
		{
			num[y]++;
			if(num[y]>1)
			q.push(y);
		}
	}
	return NO();
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
4 6 1 4
1 4
1 2
2 4
3 4
2 3
2 3
*/