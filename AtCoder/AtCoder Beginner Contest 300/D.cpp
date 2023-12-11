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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
bool vis[maxn];
__int128 prime[maxn];
ll n;
void init()
{
	int N=5e5;
	for(int i=2;i<=N;i++)
	{
		if(!vis[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=N;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		} 
	}
}
bool ok(__int128 a,__int128 b,__int128 c)
{
	__int128 now=a*a*b;
	if(now>n)return 0;
	__int128 x=n/now;
	if(x<c*c)return 0;
	return 1;
}
void solve()
{
	init();
	cin>>n;
	ll res=0;
	for(int i=1;i<=prime[0];i++)
	{
		for(int j=i+1;j<=prime[0]&&prime[i]*prime[i]*prime[j]<=n;j++)
		{
			ll l=j,r=prime[0],ans=j;
			while(l<r-1)
			{
				ll mid=(l+r)/2;
				if(ok(prime[i],prime[j],prime[mid]))ans=mid,l=mid;
				else r=mid;
			}
			while(ans<prime[0]&&ok(prime[i],prime[j],prime[ans+1]))ans++;
			if(ans==j)break;
			int a=prime[i],b=prime[j];
			// cout<<a<<" "<<b<<" "<<(int)(ans)<<endl;
			res+=ans-(j+1)+1;
		}
	}
	cout<<res<<endl;
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
/*
###
##.
#..
...

...
..#
.##
###
*/