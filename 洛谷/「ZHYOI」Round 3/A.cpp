/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e7+100;
int prime[maxn];
bool vis[maxn];
int f[maxn];
int n;
void init()
{
	for(int i=2;i<=maxn;i++)
	{
		if(!vis[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=maxn;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		} 
	}
}
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		f[i]=i;
	ll ans=0;
	for(int i=n/2;i>=1;i--)
	{
		for(int j=1;prime[j]*i<=n;j++)
		{
			int x=i;
			int y=i*prime[j];
			x=find(x);
			y=find(y);
			if(x==y)continue;
			f[x]=y;
			ans+=i;
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	init();
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}