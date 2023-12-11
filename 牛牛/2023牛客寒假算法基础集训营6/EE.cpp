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
int vis[maxn];
bool V[maxn];
int prime[maxn];
int n,ma,k,ans;
void init()
{
	for(int i=2;i<=n;i++)
	{
		if(!V[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=maxn;j++){
			V[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		} 
	}
}
void solve()
{
	cin>>n>>k;
	init();
	ma=prime[prime[0]];
	if(ma-1>k)ans++,vis[ma]=1;
	for(int i=2;i<=n;i++)
		if(i-1>k&&!vis[i])
			ans++,vis[i]=1;
	for(int i=2;i<=n;i++)
	{
		if(vis[i])continue;
		if(ma-i>k)
		{
			ans++;
			vis[i]=1;
		}
		else if(ma-i<=k)
		{
			int now = INF;
			for(int j=k+i+1;j<=n;j++)
				now=min(now,__gcd(j,i));
			if(now!=INF)
			{
				ans+=now;
				vis[i]=1;
			}
			else ans+=i;
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}