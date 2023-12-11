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
int p[maxn];
int a[maxn];
int b[maxn];
int n,k;
struct ST{
	int f[maxn][30];
	int h[maxn][30];
	int n;
	void init()
	{
		n=k;
		for(int i=1;i<=n;i++)//距离为0初始化 
		{
			f[i][0]=b[i];
			h[i][0]=a[i];
		}
		int t=log(n)/log(2)+1;//j定位 
		for(int j=1;j<t;j++)
		{
			for(int i=1;i<=n-(1<<j)+1;i++)
			{
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
				h[i][j]=min(h[i][j-1],h[i+(1<<(j-1))][j-1]);
				//f[i][j-1]为f[i][j]的长为2^j-1的前半段，另一段为f[i+(1<<(j-1))][j-1] 
			}
		} 
	}
	int ma(int l,int r)
	{
		int k=log2(r-l+1);
		return max(f[l][k],f[r-(1<<k)+1][k]);
	}
	int mi(int l,int r)
	{
		int k=log2(r-l+1);
		return min(h[l][k],h[r-(1<<k)+1][k]);
	}
}st;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		a[i]=INF;
		b[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		a[p[i]]=min(a[p[i]],i);
		b[p[i]]=max(b[p[i]],i);
	}
	st.init();
	for(int i=1;i<=k;i++)
	{
		int l=st.mi(i,k);
		int r=st.ma(i,k);
		if(a[i]==INF)cout<<"0 ";
		else cout<<1ll*(r-l+1)+(r-l+1)<<" ";
	}
	cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}