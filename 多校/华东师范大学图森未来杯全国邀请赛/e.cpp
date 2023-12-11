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
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int INF=1e9+7;
const int maxn=1e5+10;
map<vector<int>,int>mp;
int p[maxn];
int n;
void solve()
{
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
		scanf("%lld",&p[i]);
	int ans=0;
	for(int j=1;j<(1ll<<n);j++)
	{
		vector<int>v;
		for(int i=0;i<n;i++)
		{
			int tmp=((j>>i)&1);
			if(tmp==1)v.push_back(p[i]);
		}
		mp[v]++;
		if(mp[v]==2)ans++;
	}
	printf("%lld\n",ans);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}