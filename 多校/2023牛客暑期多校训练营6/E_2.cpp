/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long; 
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void solve()
{
	int T=5;
	cout<<T<<endl;
	while(T--)
	{
		int n=10;
		int m=5;
		cout<<n<<" "<<m<<endl;
		srand(time(0));
		for(int i=1;i<=n;i++)
		{
			cout<<rand()%2<<" ";
		}
		cout<<endl;
		for(int i=1;i<=m;i++)
		{
			int l=rand()%n+1;
			int r=rand()%n+1;
			while(l>r)
			{
				l=rand()%n+1;
				r=rand()%n+1;
			}
			int w=rand()%(n-1)+1;
			cout<<l<<" "<<r<<" "<<w<<endl;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
10 5
0 1 0 1 0 1 1 0 0 0
9 9 9
3 3 8
5 6 9
1 5 7
5 7 3

#!/bin/bash
g++ c.cpp -o c.out
g++ a.cpp -o a.out
g++ b.cpp -o b.out

#!/bin/bash
./c.out
./a.out
echo
./b.out
*/