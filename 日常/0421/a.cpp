#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
const int N=1e3;
char q[100][100];
int p[100][100];
char mp[100][100];
int n,m;
void solve()
{
	
	memset(q,0,sizeof(q));
	memset(p,0,sizeof(p));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	
	for(int j=1;j<=m;j++)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(mp[i][j]=='*')ans++;
			else if(mp[i][j]=='o')p[i][j]=ans,ans=0;
		}
		if(ans!=0)p[n][j]=ans;
	}
	for(int j=1;j<=m;j++)
	{
		int t=p[n][j];
		for(int i=n;i>=1;i--)
		{
			if(mp[i][j]=='o')t=p[i][j],q[i][j]='o';
			else if(t)q[i][j]='*',t--;
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++){
			//cout<<p[i][j];
		//	cout<<q[i][j];
			if(q[i][j]!='o'&&q[i][j]!='*')cout<<'.';
			else cout<<q[i][j];
		}
		cout<<endl;	
	}
}
signed main(){
	int __;cin>>__;
	while(__--)solve();
}