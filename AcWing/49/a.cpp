/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
int n,k,cnt;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		if(x+k<=5)cnt++;
	}
	cout<<cnt/3<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}