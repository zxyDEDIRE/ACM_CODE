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
bool vis[maxn];
int prime[maxn];
int n;
void init()
{
	for(int i=2;i<=300;i++)
	{
		if(!vis[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&i*prime[j]<=300;j++)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
void solve()
{
	init();
	cin>>n;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}