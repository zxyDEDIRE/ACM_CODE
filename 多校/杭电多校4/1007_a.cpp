/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int su[maxn];
int p[maxn];
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=0;i<=n;i++)
	{
		if(p[i]<=m)
		{
			m+=p[i];
			continue;
		}
		int j=i;
		int need=p[j];
		int sum=need;
		while(1)
		{
			j++;
			sum+=p[j];
			if(j>n)break;
			need=max(p[j],need-p[j]);
			if(need<=m)break;
		}
		m+=sum;
		i=j;

		if(j>n||j-i>k){
			//cout<<len<<endl;
			cout<<"NO"<<endl;
			return ;
		}	
	}
	cout<<"YES"<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1 2 3 4
4 3 2 1
4 3 2 1 4 3 2 1 

6 2 1 0
6 4 2 1

6 2 4 0
6 4 4 4

6 2 1
6 4 3


9 3
9 6

1
5 3 3
5 4 1 10 1
*/