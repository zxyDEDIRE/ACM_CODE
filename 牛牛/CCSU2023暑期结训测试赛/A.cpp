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
vector<int>v[maxn];
int prime[maxn];
bool vis[maxn];
int p[maxn];
int s[maxn];
int n;
void init()
{
	for(int i=2;i<=maxn;i++)
	{
		if(!vis[i])prime[++prime[0]]=i,s[i]=prime[0];
		for(int j=1;j<=prime[0]&&prime[j]*i<=maxn;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		} 
	}
}
void solve()
{
	init();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		for(int j=1;prime[j]*prime[j]<=x;j++)
			if(x%prime[j]==0)
			{
				v[j].push_back(i);
				while(x%prime[j]==0)
					x/=prime[j];
			}
		if(x!=1)
			v[s[x]].push_back(i);
	}
	int q;cin>>q;
	while(q--)
	{
		int l,r,x;
		cin>>l>>r>>x;
		x=s[x];
		int fa=lower_bound(v[x].begin(),v[x].end(),l)-v[x].begin();
		int fb=upper_bound(v[x].begin(),v[x].end(),r)-v[x].begin()-1;
		if(fa<=fb)cout<<fb-fa+1<<endl;
		else cout<<"666666!"<<endl;
		
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}