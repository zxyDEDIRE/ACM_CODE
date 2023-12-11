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
vector<int>v[maxn];
bitset<maxn>vis;
int step[maxn];
int out[maxn];
int in[maxn];
int p[200];
int cnt;
int n;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void dfs(int x,int st)
{
	step[st]=x;
	if(st==n+1)
	{
		for(int i=1;i<=n+1;i++)
			cout<<(char)step[i]<<" ";
		cout<<endl;
		return ;
	}
	for(auto y:v[x])
	{
		dfs(y,st+1);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=200;i++)p[i]=i;
	for(int i=1;i<=n;i++)
	{
		char a,b;
		cin>>a>>b;
		int x=a;
		int y=b;
		v[x].push_back(y);
		v[y].push_back(x);
		in[x]++;
		int fa=find(x);
		int fb=find(y);
		if(!vis[fa])cnt++,vis[fa]=1;
		if(!vis[fb])cnt++,vis[fb]=1;
		if(fa!=fb){
			p[fb]=fa;
			cnt--;
		}
	}
	if(cnt>1){
		cout<<"No Solution"<<endl;
		return ;
	}
	int s=-1,t=-1,cnt=0;
	for(int i=1;i<=200;i++)
		if(in[i]%2==1){
			if(s==-1)s=i;
			else if(t==-1)t=i;
			cnt++;
		}
	if(cnt!=0&&cnt!=2){
		cout<<"No Solution"<<endl;
		return ;
	}
	if(cnt==2)
	{
		cout<<"yes"<<endl;
		dfs(min(s,t),1);
	}
	else
	{
		for(int i=1;i<=200;i++)
			if(in[i])
				dfs(i,1);
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}