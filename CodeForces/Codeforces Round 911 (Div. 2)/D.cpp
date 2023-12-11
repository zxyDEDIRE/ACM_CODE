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
const int M=1e5+10,T=1e3+10;//值 域
bool vis[M];
int q[M],cnt;
int fac[M][3];
int gc[T][T];
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
void init(int n=M-10)
{
	vis[1]=true;
	vis[0]=true;
	fac[1][0]=fac[1][1]=fac[1][2]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			q[cnt++]=i;
			fac[i][0]=fac[i][1]=1;
			fac[i][2]=i;
		}
		for(int j=0;1ll*q[j]*i<=n;j++)
		{
			int nu=q[j]*i;
			vis[nu]=true;
			fac[nu][0]=fac[i][0]*q[j];
			fac[nu][1]=fac[i][1];
			fac[nu][2]=fac[i][2];
			if(fac[nu][0]>fac[nu][1]) swap(fac[nu][0],fac[nu][1]);
			if(fac[nu][1]>fac[nu][2]) swap(fac[nu][1],fac[nu][2]);
			if(i%q[j]==0) break;
		}
	}
	for(int i=0;i<=T-10;i++)
	{
		for(int j=0;j<=T-10;j++)
		{
			if(!i&&!j) continue;
			gc[i][j]=gcd(i,j);
		}
	}
}
int qgcd(int x,int y)
{
	int res=1;
	for(int i=0,t=1;i<3;i++)
	{
		if(fac[x][i]>T-10)
		{
			if(y%fac[x][i]) t=1;
			else t=fac[x][i];
		}
		else t=gc[fac[x][i]][y%fac[x][i]];
		res=res*
		t;y/=t;
	}
	return res;
}

int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n);
	n--;
	ll ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			// cout<<p[i]<<" "<<p[j]<<" "<<__gcd(p[i],p[j])*(n-j+1)<<endl;
			ans+=qgcd(p[i],p[j])*(n-j+1);
		}
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	init();
	// cout<<prime[0]<<endl;
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
6 6

3*3

6 8 9

6 12
2 2
3 3
*/