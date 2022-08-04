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
const int mod=1e9+7;
const int maxn=1e6;
bitset<maxn>vis;
vector<int>v;
int p[maxn];
ll n,ans;
ll A(int x,int y)
{
	ll res=1;
	for(int i=1;i<=y;i++)
	{
		res*=x;
		x--;
		res%=mod;
	}
	return res;
}
void solve()
{
	cin>>n;
	ans=1;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	vis.reset();



	int lena=0,s=0;
	for(int i=1;i<=n;i++)
	{
		lena++;
		vis[p[i]]=1;
		if(p[i]==0)break;
	}
	while(vis[s]=1)s++;s--;

	if(lena>2)
	{
		
	}



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
/*
1 3 7 2 5 0 6 4
a 4 2   
a 3 3

4*3*3*2*1
12*6=72

*/