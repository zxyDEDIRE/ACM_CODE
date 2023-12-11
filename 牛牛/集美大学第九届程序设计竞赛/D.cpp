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
const int maxn=1e6+100;
int prime[maxn],phi[maxn];
bool vis[maxn];
int n;
void doit()
{
	phi[1]=1;
	for(int i=2;i<=maxn;i++){
		if(!vis[i])prime[++prime[0]]=i,phi[i]=i-1;
		for(int j=1;j<=prime[0]&&prime[j]*i<=maxn;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}}
void solve()
{
	// doit();
	// n=12;
	// int ans=0;
	// for(int i=1;i<=n;i++){
	// 	ans+=phi[i]*(n/i);
	// 	cout<<i<<" "<<phi[i]<<" "<<(n/i)<<" "<<phi[i]*(n/i)<<" "<<ans<<endl;
	// }
	ll n;
	cin>>n;
	cout<<(1+n)*n/2<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*

*/