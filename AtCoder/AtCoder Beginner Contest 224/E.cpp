/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
map<int,vector<int>>v;
int r[maxn],c[maxn],w[maxn];
int rma[maxn],cma[maxn];
int dp[maxn];
int H,W,n;
void solve()
{
	cin>>H>>W>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i]>>c[i]>>w[i];
		v[w[i]].push_back(i);
	}
	for(auto i=v.rbegin();i!=v.rend();i++)
	{
		for(auto x:i->second)
			dp[x]=max(rma[r[x]],cma[c[x]]);
		for(auto x:i->second)
		{
			rma[r[x]]=max(rma[r[x]],dp[x]+1);
			cma[c[x]]=max(cma[c[x]],dp[x]+1);
		}
	}
	for(int i=1;i<=n;i++)
		cout<<dp[i]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}