#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6;
int p[maxn];
int b[maxn];
int c[maxn];
int n,len;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	len=max(b[n],c[n]);
	for(int i=1,j;i<=n;i++)
	{
		if(b[i]<c[i])
		p[i]=2*(c[i]-b[i]);
		else p[i]=0;
		p[i]+=p[i-1];
	}
	int mi=1e18;
	for(int i=1;i<=n;i++)
	{
		int t=p[i-1]+len+(len-b[i]);
		mi=min(mi,t);
	}
	cout<<mi<<endl;
}
/*
5
1 2 6 11 12
3 4 8 10 20
*/
