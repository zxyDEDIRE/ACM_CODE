#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn=2e5;
int vis[maxn][2];
int a[maxn];
int b[maxn];
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	int t=1;
	b[0]=b[n+1]=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i-1]<a[i])
		{
			t=i;
		}
		else
		{
			break;
		}
	}
	int s=n;
	for(int i=n;i>=1;i--)
	{
		if(b[i+1]<a[i])
		{
			s=i;
		}
		else 
		{
			s=i;
			break;
		}
	}
	if(t>=s)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
/*
4

*/