#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int maxn=1e6+100;
// using PLL=array<ULL,2>;
using ull=unsigned long long;
using ULL=unsigned long long;
using PLL=pair<ull,ull>;
const int sigma = maxn;
const int HASH_CNT = 2;
ULL Prime_Pool[] = {1998585857ul,23333333333ul};
ULL Seed_Pool[]={911,146527,19260817,91815541};
ULL Mod_Pool[]={29123,998244353,1000000009,4294967291ull};
int n,m,k;
char s[maxn];
struct Hash{
    ULL Seed,Mod;
    ULL bas[maxn];ULL sum[maxn];
    int perm[sigma];
    Hash(ULL Seed, ULL Mod):Seed(Seed),  Mod(Mod){
        bas[0] = 1;
        for (int i = 1; i <= n; i++){
            bas[i] = bas[i - 1] * Seed % Mod;
        }
    }
    void init(){
        for (int i=1;i<=n;i++){
            sum[i] = (sum[i-1]*Seed%Mod+s[i])%Mod;
        }
        bas[0] = 1;
        for (int i = 1; i <= n; i++){
            bas[i] = bas[i - 1] * Seed % Mod;
        }
    }
    /*random_shuffle 离散化id，防止kill_hash*/
    void indexInit(){
        iota(perm + 1, perm + 1 + sigma, 1);
        random_shuffle(perm+1,perm+1+sigma);
        for (int i=1;i<=n;i++){
            sum[i] = (sum[i-1]*Seed%Mod+perm[s[i]])%Mod;
        }
    }
    ULL getHash(int l,int r){
        return (sum[r]-sum[l-1]*bas[r-l+1]%Mod+Mod)%Mod;
    }
}h[3] = {Hash(Seed_Pool[3], Mod_Pool[3]),Hash(Seed_Pool[2], Mod_Pool[2]),Hash(Seed_Pool[1], Mod_Pool[1])};

void solve()
{
	cin>>n>>m>>k>>s+1;
	h[0].init();
	h[1].init();
	map<PLL,int>cnt;
	map<PLL,int>vis;
	for(int i=m;i<=n;i++)
	{
		ULL now[3];
		now[0]=h[0].getHash(i-m+1,i);
		now[1]=h[1].getHash(i-m+1,i);
		PLL fl={now[0],now[1]};
		if(vis.count(fl)&&vis[fl]<i-m+1)
		{
			cnt[fl]++;
			vis[fl]=i;
		}
		else if(!vis.count(fl))
		{
			cnt[fl]=1;
			vis[fl]=i;
		}
	}
	int ans=0;
	for(auto [x,y]:cnt)
		if(y==k)ans++;
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}