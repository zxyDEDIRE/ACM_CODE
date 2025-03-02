#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+7;
vector<int>v[maxn];
int n,m,t,x,y,ans;
signed main()
{
		while(1)n++;
	cin>>n>>m>>t;

	for(int i=1;i<=m;i++){
		cin>>x>>y;
		v[y].push_back(x);
	}
//	cout<<endl;
	for(int i=1;i<=n;i++){
		sort(v[i].begin(),v[i].end());v[i].push_back(t);
//		for(int j=0;j<v[i].size()-1;j++)
//			cout<<v[i][j]<<" ";
//		cout<<endl;
	}
//	cout<<endl;
	
	for(int i=1;i<=n;i++)
	{
		int q=0,fl=0;
		for(int j=0;j<v[i].size()-1;j++)
		{
			q+=2;
//			cout<<q<<" ";
			q=max(0ll,q-max(v[i][j+1]-v[i][j]-1,0ll));
			if(q>5)fl=1;
			if(q<=3)fl=0;
		}
		if(v[i][v[i].size()-2]!=t)q=max(0ll,q-1);
//		cout<<q<<endl;
		if(fl&&q>3)ans++;
	}
	cout<<ans<<endl;
}
/*
2 6 6
1 1 
5 2
3 1
6 2
2 1
6 2

3 10 10
7 1
10 3
5 3
3 2
5 3
7 3
9 1
7 1
1 3
9 3

*/
