/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
bitset<maxn>vis;
int p[maxn];
int n,x,ans;
void dfs(int num,int x)
{
	if(x==1)
	{
		ans=max(ans,num);
		return ;
	}
	for(int i=1;i<x;i++)
	{
		dfs(num%p[i],i);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n);
	cin>>x;
	for(int i=1;i<=n;i++)
	{
		dfs(x%p[i],i);
	}
	cout<<ans<<endl;
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
/*
10
90
81
25
35
46
56
29
580
272
2479
247
24
249
123

*/
