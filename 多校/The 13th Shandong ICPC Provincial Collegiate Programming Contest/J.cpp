#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,m,q;
long long val;
int f[N][125];
int find(int x,int t)
{
	return f[x][t]=(f[x][t]==x)?x:find(f[x][t],t);
}
void solve()
{
	cin>>n>>m>>q>>val;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=120;j++)
			f[i][j]=i;
	}
	vector<long long>b;
	int ff=0;
	long long val1=0;
	for(int i=60;i>=0;i--)
	{
		if((val>>i)&1)
		{
			val1|=(1ll<<i);ff=1;
			if(val==val1){
				b.push_back(val1);break;
			}
		}
		else if(ff){
			b.push_back(val1|(1ll<<i));
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		int v,u;
		long long w;
		cin>>v>>u>>w;
		for(int j=59;j>=0;j--)
		{
			if((w>>j)&1)
			{
				f[find(v,j)][j]=find(u,j);
			}
		}
		for(int j=0;j<(int)b.size();j++)
		{
			if((w&b[j])==b[j])
			{
				f[find(v,j+60)][j+60]=find(u,j+60);
			}
		}
	}
	while(q--)
	{
		int v,u;
		cin>>v>>u;
		int f=0;
		for(int j=0;j<(int)b.size();j++)
			if(find(v,60+j)==find(u,60+j))
			{
				cout<<"Yes\n";f=1;break;
			}
		if(f==0)
		for(int i=59;i>=0;i--)
		{
			if((1ll<<i)<val) break;
			if(find(v,i)==find(u,i))
			{
				cout<<"Yes\n";
				f=1;
				break;
			}
		}
		if(f==0)
		cout<<"No\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
