#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
vector<int> G[maxn];
stack<int> s;
bool vis[maxn];
int a[maxn];
bool FLAG;
int fa[maxn];
int n,q;
void dfs(int now,int f)
{
	if(FLAG)
		return;
	if(vis[now])
	{

		s.pop();
		int cnt=0;
		
		while(1)
		{
			int tmp=s.top();
			cnt++;
			s.pop();
			a[tmp]=1;
			if(tmp==now)
				break;
		}
		FLAG=1;
		return;
	}
	vis[now]=1;
	for(auto i:G[now])
	{
		if(i==f)
			continue;
		s.push(i);
		dfs(i,now);
		if(s.size())
			s.pop();
	}
}
//top是链顶端的元素，只能是环上的
void getfa(int now,int top,int f)
{
	fa[now]=top;
	for(auto i:G[now])
	{
		if(i==f)continue;
		// if(i==fa[now])
		// 	continue;
		// if(vis[i])
		// 	continue;
		if(!a[i])
		getfa(i,top,now);
	}
}
// int find(int r){
// 	return fa[r]=fa[r]==r?fa[r]:find(fa[r]);
// }
// void dfs_1(int x,int f)
// {
// 	for(auto y:G[x])
// 	{
// 		if(y==f)continue;
// 		int A=find(x);
// 		int B=find(y);
// 		fa[A]=B;
// 		dfs_1(y,x);
// 	}
// }
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	// cout<<"finish input"<<endl;

	s.push(1);
	dfs(1,0);

	// cout<<"finish dfs"<<endl;

	// for(int i=1;i<=n;i++)
	// 	cout<<a[i]<<" \n"[i==n];
	for(int i=1;i<=n;i++)
	{
		if(a[i]){
			//cout<<"getfa i="<<i<<endl;
			getfa(i,i,i);
		}
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<fa[i]<<" \n"[i==n];
	// cout<<"finish getfa"<<endl;
	// for(int i=1;i<=n;i++)
	// 	fa[i]=i;
	// for(int i=1;i<=n;i++)
	// {
	// 	if(!a[i])continue;
	// 	for(auto y:G[i])
	// 	{
	// 		if(a[y])continue;
	// 		int A=find(i);
	// 		int B=find(y);
	// 		fa[A]=B;
	// 		dfs_1(y,i);
	// 	}
	// }

	cin>>q;
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		// int A=find(u);
		// int B=find(v);
		// if(A==B)cout<<"Yes"<<endl;
		// else cout<<"No"<<endl;
		// cout<<u<<" - "<<v<<" & "<<fa[u]<<" - "<<fa[v]<<endl;
		if(fa[u]==fa[v])
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}
/*

*/