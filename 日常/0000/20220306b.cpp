#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
vector<pair<int,int> >v[maxn];
int p[maxn],cnt;
bool vis[maxn];
int x,n,m;
int xx[500],yy[100100];
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>x;
			if(!vis[x])
			{
				vis[x]=1;
				p[++cnt]=x;
				v[x].push_back(pair<int,int>(i,j));
			}
			else v[x].push_back(pair<int,int>(i,j));
		}
	int ans=0;
	cout<<endl;
	for(int k=1;k<=cnt;k++)
	{
		x=p[k];
		for(int i=1;i<=n;i++)xx[i]=0;
		for(int i=1;i<=m;i++)yy[i]=0;
		for(int j=0;j<v[x].size();j++)
		{
			pair<int,int>i;
			i=v[x][j];
			xx[i.first]++;
			yy[i.second]++;
		//	cout<<i.first<<" "<<i.second<<endl;
		}
		
		for(int i=1;i<=n;i++)cout<<xx[i]<<" ";
		cout<<endl;
		for(int i=1;i<=m;i++)cout<<yy[i]<<" ";
		cout<<endl;
		for(int i=1;i<n;i++)
		{
			ans+=xx[i]*xx[i+1];
			xx[i+1]+=xx[i]*2;
			cout<<ans<<" ";
		}
		cout<<endl;
		yy[0]=0;
		for(int i=1;i<m;i++)
		{
			ans+=yy[i]*yy[i+1];
			cout<<ans<<" ";
			yy[i+1]+=yy[i]*2;
		}
		cout<<endl;
		cout<<endl;
	}
	cout<<ans<<endl;
}
