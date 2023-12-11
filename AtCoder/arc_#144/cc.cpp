/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
void solve()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		p[i]=i;
	while(next_permutation(p+1,p+1+n))
	{
		int flag=1;
		for(int i=1;i<=n;i++)
			if(abs(p[i]-i)<k)flag=0;
		if(flag)
		{
			for(int i=1;i<=n;i++)
				cout<<p[i]<<" ";
			cout<<endl;
			return ;
		}
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
1 2 3     4 5 6 7  8  9 10 11
4 5 6     1 2 9 10 11 3 7  8
*/