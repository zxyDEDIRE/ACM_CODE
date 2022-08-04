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
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int p[maxn];
int a[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n*3;i++)
	{
		int x;string str;
		cin>>x>>str;
		a[x]++;
		p[x]+=(str=="YES")?1:0;
	}
	int ans=0,flag=1;
	for(int i=0;i<n;i++)
	{
		int x=p[i];
		int y=a[i]-x;
		if(x==y)flag=0;
	}
	if(flag)
	{
		for(int i=0;i<n;i++)
		{
			int x=p[i];
			int y=a[i]-x;
			if(x>y)cout<<1;
			else cout<<0;
		}
		cout<<endl;
	}
	else cout<<-1<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}