#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
const int maxn=1e3+10;
const int mod=1e9+7;
int mp[maxn][maxn];
int dis[N];
int n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n>>m;
	int num=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			if(dis[mp[i][j]]==1)num--;
			else if(dis[mp[i][j]]==0)num++;
			dis[mp[i][j]]++;
		}
	cout<<num<<endl;
}
/*
3 4
1 3 3 4 
2 3 1 4 
6 3 3 4
*/