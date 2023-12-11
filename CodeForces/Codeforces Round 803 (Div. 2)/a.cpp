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
int n;
void solve()
{
	cin>>n;
	int t;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(i==1)t=p[1];
		else t^=p[i];
	}
	cout<<p[1]<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}