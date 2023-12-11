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
bitset<maxn>vis;
int p[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	int l=1;
	int tot=0;
	p[++tot]=1;
	vis[1]=1;
	while(tot<n)
	{
		while(1)
		{
			if(p[tot]+k>n)break;
			p[tot+1]=p[tot]+k;
			tot++;
			vis[p[tot]]=1;
		}
		if(tot==n)break;
		while(vis[l])l++;
		p[++tot]=l;
		vis[l]=1;
	}
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" \n"[i==n];
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}