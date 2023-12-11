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
int n;
void solve()
{
	cin>>n;
	int m=sqrt(n);
	if(m*m!=n)m++;
	bitset<maxn>vis;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		int l=i;
		for(int j=min(n,i+m-1);j>=i;j--)
		{
			p[l++]=j;
			vis[j]=1;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<endl;
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