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
const int maxn=40000+10;
bool vis[maxn];
int prime[maxn];
int n;
void doit()
{
	for(int i=2;i<=maxn;i++)
	{
		if(!vis[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&i*prime[j]<=maxn;j++)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)continue;
		}
	}
}
void solve()
{
	cin>>n;
	int ans=0;
	bitset<maxn>vis;
	for(int i=1;i<=prime[0];i++)
	{
		if(prime[i]>=n)break;
		for(int j=1;j*prime[i]<n;j++)
		{
			if(!vis[prime[i]*j])
			{
				ans++;
				vis[prime[i]*j]=1;
			}
		}
	}
	cout<<n-ans<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	doit();
	while(__--)
		solve();
	return 0;
}