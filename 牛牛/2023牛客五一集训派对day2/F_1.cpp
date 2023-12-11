#include<bits/stdc++.h>
using namespace std;
#define int long long 
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int n,m,k;
const int N=5110;
int mp[N][N];
int q[N];
int tp[N][N];
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			mp[i][j]=i/gcd(i,j)*j;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int t=0,w=-1;
		for(int j=1;j<=m;j++)
		{
			if(t<=w&&q[t]-j>=k) t++;
			while(t<=w&&mp[i][q[w]]<=mp[i][j]) w--;
			q[++w]=j;
				tp[i][j]=mp[i][q[t]];
		}
	}
	long long ans=0;
	for(int i=k;i<=m;i++)
	{
		int t=0,w=-1;
		for(int j=1;j<=n;j++)
		{
			if(t<=w&&q[t]-j>=k) t++;
			while(t<=w&&tp[q[w]][i]<=tp[j][i]) w--;
			q[++w]=j;
			if(j>=k)
			{
				ans+=tp[q[t]][i];
			}
		}
	}
	cout<<ans;
	return 0;
}