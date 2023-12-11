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
const int N=2750160;
int ans[maxn];
int p[maxn];
int n,q;

bool vis[N];
int prime[N];
void init()
{
	for(int i=2;i<=N;i++)
	{
		if(!vis[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=N;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		} 
	}
}
bitset<N>ok;
void solve()
{
	init();
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int s=1;
	for(int i=1;i<=n;i++)
	{
		if(!vis[p[i]])ok[p[i]]=1;
		while(ok[prime[s]])s++;
		ans[i]=prime[s];
	}
	while(q--)
	{
		int x;cin>>x;
		cout<<ans[x]<<endl;
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
/*
4 2
zZZz
*/