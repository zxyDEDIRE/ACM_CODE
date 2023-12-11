#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
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
const int N=555;
bitset<N>q[N];
int p[maxn];
int a[maxn];
int len;
int k,r,flag;
void dfs(int x,int yu)
{
	if(flag)return ;
	if(x>k)
	{
		if(yu!=0)return ;
		a[1]=p[1];
		for(int i=2;i<=k;i++)
			a[i]=a[i-1]+p[i];
		if(a[k]!=256)return ;
		for(int i=1;i<=k;i++)
		{
			int r=a[i];
			int l=a[i]-len+1;
			for(int j=1;j<=256;j++)
				if(j>=l&&j<=r)q[i][j]=1;
				else q[i][j]=0;
			if(l<1)return ;
		}
		int ans=1;
		for(int i=1;i+r-1<=k;i++)
		{
			bitset<N>now;
			for(int j=0;j<r;j++)
				now|=q[i+j];
			if(now.count()<128)return ;
		}
		flag=1;
		return ;
	}
	for(int i=0;i<=yu;i++)
	{
		p[x]+=i;
		dfs(x+1,yu-i);
		p[x]-=i;
	}
}
void solve()
{
	// _sleep(10);
	cin>>k>>r;
	cout<<k<<" "<<r<<" ";
	len=ceil(1.0*512/r);
	int x=256-len;
	int ans_1 = x/(k-1);
	int ans_2 = x%(k-1);
	flag=0;
	p[1]=len;
	for(int i=2;i<=k;i++)
		p[i]=ans_1;
	dfs(1,ans_2);
	cout<<flag<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// for(r=3;r<=26;r++)
	// 	for(k=r;k<=26;k++)
		solve();
	return 0;
}