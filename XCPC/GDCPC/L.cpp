#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+7;


int n,a[maxn];
vector<int> G[maxn];
int st,f=0;
long long ans=0;


void dfs(int now,int fa)
{
	/*
	if(G[now].size()==1)
	{
		if(f==1)
		{
			st=now;
			return;
		}
		else
			f=1;
	}
	*/
	st=now;
	int p,maxx=-1; 
	for(auto i:G[now])
	{
		if(i==fa)continue;
		if(a[i]>maxx)
		{
			p=i;
			maxx=a[i];
		}
	}
	if(maxx>=0)
	{
		
		dfs(p,now);
		
	}
}
void dfs2(int now,int fa)
{
	cout<<"from: "<<fa<<" to "<<now<<endl;
	ans+=a[now];
	int p,maxx=-1; 
	for(auto i:G[now])
	{
		if(i==fa)continue;
		if(a[i]>maxx)
		{
			p=i;
			maxx=a[i];
		}
	}
	cout<<"--------p="<<p<<"---maxx="<<maxx<<endl;
	if(maxx>=0)
		dfs2(p,now);
}


int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int x;cin>>x;
		G[i].push_back(x);
		G[x].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(G[i].size()==1)
			st=i;
		else
			sort(G[i].begin(),G[i].end());
	}
	dfs(st,0);
	
	cout<<"==="<<st<<endl;
	
	
	dfs2(st,0);

	cout<<st<<"\n"<<ans<<endl;
}
