#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int p[maxn];
int a[maxn];
int n,m,k;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		p[find(x)]=find(y);
	}
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
}
/*
7 5 4
1 2
2 3
3 1
4 5
5 6
1 4 5 7

*/