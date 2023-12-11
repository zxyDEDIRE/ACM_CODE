#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5555;
int a[N][N];
int b[N][N];
int c[N][N];
int q[N],s,t;
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=i*j/__gcd(i,j);
	for(int j=1;j<=n;j++)
	{
		s=0;t=1;
		for(int i=1;i<=m;i++)
		{
			int x=a[j][i];
			q[++s]=i;
			while(q[t]+k-1<i||a[j][q[t]]<x)
				t++;
			b[j][i]=a[j][q[t]];
		}
	}

	for(int j=k;j<=m;j++)
	{
		s=0,t=1;
		for(int i=1;i<=n;i++)
		{
			int x=b[i][j];
			q[++s]=i;
			while(q[t]+k-1<i||b[q[t]][j]<x)
				t++;
			c[i][j]=b[q[t]][j];
		}
	}
	long long ans=0;
	for(int i=k;i<=n;i++)
		for(int j=k;j<=m;j++)
			ans+=c[i][j];
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}