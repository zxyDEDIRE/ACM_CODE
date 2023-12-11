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
const int mod=998244353;
vector<int>v[maxn];
int siz[maxn];
ll n,ans;
int fp(int b,int p)
{
	int res=1;
	while(p)
	{
		if(p&1)res=(res*b)%mod;
		p>>=1;
		b=(b*b)%mod;
	}
	return res;
}
void dfs(int x,int fa)
{
	siz[x]=1;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs(y,x);
		siz[x]+=siz[y];
	}
	if(siz[x]%2==0)ans++;
}
void solve()
{
	cin>>n;
	for(int  i=1;i<=n;i++)
		v[i].clear();
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	ans=0;
	dfs(1,1);
	ans--;
	cout<<(fp(2,ans)-1+mod)%mod<<endl;

}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
6
1 2
2 3
3 4
4 5
5 6

1
10
1 2
2 3
2 4
4 5
1 6
6 7
6 9
7 8
9 10

1
12
1 2
2 3
2 4
4 5
1 6
6 7
6 9
7 8
9 10
3 11
12 11
*/