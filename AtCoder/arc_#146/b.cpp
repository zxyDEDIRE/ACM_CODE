/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
bitset<maxn>vis;
vector<int>v[60];
ll f[maxn];
ll p[maxn];
ll n,m,k;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=29;i>=0;i--)
	{
		ll ans=0;
		for(int j=1;j<=n;j++)
		{
			ll x=j%(1<<(i+1));
			if(x<(1<<i))ans+=(1<<i)-x;
		}
	}
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}