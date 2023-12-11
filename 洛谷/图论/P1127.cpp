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
struct Edge{
	int to,next,i;
	string w;
}edge[maxn];
int in[maxn],out[maxn];
int p[maxn],p_num=0;
int head[maxn],cnt;
bitset<maxn>vis;
string mp[1111];
string stp[maxn];
int n;
int find(int r){
	return p[r]=(p[r]==r)?p[r]:find(p[r]);
}
void add(int from,int to,string w,int i)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	edge[cnt].i=i;
	head[from]=cnt;
}
void dfs(int x,int step)
{
	//cout<<str<<endl;
	if(step==n)
	{
		for(int i=0;i<n;i++)
		{
			cout<<stp[i];
			if(i<n-1)cout<<".";
		}
		exit(0);
		return ;
	}
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		int j=edge[i].i;
		if(vis[j])continue;
		vis[j]=1;
		stp[step]=edge[i].w;
		dfs(y,step+1);
		vis[j]=0;
	}
}
int solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>mp[i];
	sort(mp+1,mp+1+n);
	for(int i=1;i<=n;i++)
	{
		int S=mp[i].front()-'a'+1;
		int T=mp[i].back()-'a'+1;
		in[T]++;
		out[S]++;
		if(!vis[S])
		{
			p_num++;
			p[S]=S;
			vis[S]=1;
		}
		if(!vis[T])
		{
			p_num++;
			p[T]=T;
			vis[T]=1;
		}
		int fa=find(S);
		int fb=find(T);
		if(fa!=fb)
		{
			p_num--;
			p[fa]=fb;
		}
		add(S,T,mp[i],i);
	}
	if(p_num!=1)return 0;


	int start=0;
	int end=0;
	for(int i=1;i<=26;i++)
	{
		if(!vis[i])continue;
		if(out[i]-in[i]==1)
		{
			if(!start)start=i;
			else return 0;
		}
		else if(in[i]-out[i]==1)
		{
			if(!end)end=i;
			else return 0;
		}
		else if(out[i]==in[i]);
		else return 0;
	}
	// for(int i=1;i<=26;i++)
	// 	cout<<in[i]<<" ";cout<<endl;
	// for(int i=1;i<=26;i++)
	// 	cout<<out[i]<<" ";cout<<endl;

	if(start&&!end)return 0;
	else if(!start&&end)return 0;

	if(!start)start=mp[1][0]-'a'+1;

	vis.reset();
	dfs(start,0);

	return 1;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		if(!solve())cout<<"***"<<endl;
	return 0;
}