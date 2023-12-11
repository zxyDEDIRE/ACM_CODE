#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+100;
bitset<maxn>p[maxn],now;
string str;
int n,m;
void solve()
{
	for(int i=0;i<n;i++)
		p[i].reset();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x;cin>>x;
			if(x&1)p[i][j]=1;
			else p[i][j]=0;
		}
	}
	int flag=1;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			now=(p[i]^p[j]);
			if(now.count()%2==0)flag=0;
		}
	}
	if(flag)cout<<"Yes\n";
	else cout<<"No\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	while(cin>>n>>m)
		solve();
	return 0;
}
/*
2 2
0 1
0 0
*/
