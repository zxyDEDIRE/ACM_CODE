/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
vector<int>p[maxn];
bitset<maxn>vis;
int in[maxn];
int n,m;
bool check(vector<int>&x,vector<int>&y)
{
	int ma=x[0];
	for(int i=1;i<n;i++)
	{
		if(x[i]!=x[i-1])ma=0;
		if(y[i]<ma)return 0;
		ma=max(ma,y[i]);
	}
	return 1;
}
int f(vector<int>&x)
{
	for(int i=1;i<n;i++)
		if(x[i]<x[i-1])
			return 0;
	return 1;
}
void solve()
{
	for(int j=1;j<=m;j++)
		p[j].clear(),v[j].clear();

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x;cin>>x;
			p[j].push_back(x);
		}
	}
	priority_queue<int,vector<int>,greater<int>>q;
	for(int i=1;i<=m;i++)
		if(f(p[i])){
			q.push(i);
		}
	vis.reset();
	vector<int>ans;
	while(!q.empty())
	{
		int x=q.top();q.pop();
		if(vis[x])continue;
		ans.push_back(x);
		vis[x]=1;
		for(int i=1;i<=m;i++)
		{
			if(vis[i])continue;
			if(!check(p[x],p[i]))continue;
			q.push(i);
		}
	}
	for(int i=1;i<=m;i++)
		if(!vis[i]){
			cout<<"-1"<<endl;
			return ;
		}
	for(int i=0;i<m;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	while(cin>>n>>m)
	// cin>>n>>m;
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*

4 3
4 3 3
1 5 1
1 5 1
3 5 2
*/