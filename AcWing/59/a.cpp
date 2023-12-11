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
void solve()
{
	int sum=0,mi=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		sum+=x;
		mi=min(mi,sum);
	}
	cout<<sum-mi<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);

		solve();
	return 0;
}