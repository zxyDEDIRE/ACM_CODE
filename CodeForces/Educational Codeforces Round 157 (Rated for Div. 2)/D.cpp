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
int t[maxn][2],indx;
int val[maxn];
int a[maxn];
int p[maxn];
int n;
void clear(){
	for(int i=0;i<=indx;i++)
		t[i][0]=t[i][1]=0;
}
void insert(int x)
{
	int rt=0;
	for(int i=18;i>=0;i--)
	{
		int tmp=(x&(1ll<<i))?1:0;
		if(!t[rt][tmp])
			t[rt][tmp]=++indx;
		rt=t[rt][tmp];
	}
}
ll query(int x)
{
	int rt=0;
	ll ans=0;
	for(int i=18;i>=0;i--)
	{
		int tmp=(x&(1ll<<i))?1:0;
		if(t[rt][tmp^1])
		{
			ans+=(1ll<<i);
			rt=t[rt][tmp^1];
		}
		else
			rt=t[rt][tmp];
	}
	return ans;
}
void solve()
{
	cin>>n;
	clear();
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		a[i]=(a[i]^a[i-1]);
		insert(a[i]);
	}
	int x=0;
	for(x=0;x<n;x++)
	{
		ll now=query(x);
		if(now<=n-1)break;
	}
	for(int i=1;i<=n;i++)
		cout<<(x^a[i])<<" ";cout<<endl;

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}