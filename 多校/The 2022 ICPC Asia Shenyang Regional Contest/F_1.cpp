#include<bits/stdc++.h>
using namespace std;
const int N=100;
int mp[N][N];
int n,m;

long long get(long long n)
{
	return n*(n+1)/2;
}

signed main()
{
	cin>>n>>m;
	long long tp=get(n)*(get(m))/2;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			long long tp1=get(i)*get(j)+get(i)*get(m-j)+get(n-i)*get(j)+get(n-i)*get(m-j);
			if(tp1==tp)
			{ 
				cout<<i<<" "<<j<<'\n';
			}
		}
	}
}
/*
4 4
1 1 1 1
1 1 1 1
0 0 0 0
1 1 1 1

4 3
1 1 1 1
0 0 0 0
1 1 1 1


3 3
1 0 1
1 0 1
1 0 1

3 5
1 1 1 1 1
0 0 0 0 0
1 1 1 1 1

3 7
1 1 1 1 1 1 1
0 0 0 0 0 0 0
1 1 1 1 1 1 1

8 8
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
0 0 0 0 1 1 0 0
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1

6 6
1 1 1 1 1 1 
0 0 0 0 0 0
1 1 1 1 1 1 
1 1 1 1 1 1 
1 1 1 1 1 1 
1 1 1 1 1 1 


5 8
1 1 1 1 1 1 1 1
1 1 1 0 1 1 1 1
1 1 1 0 1 1 1 1
1 1 1 0 1 1 1 1
1 1 1 0 1 1 1 1
*/