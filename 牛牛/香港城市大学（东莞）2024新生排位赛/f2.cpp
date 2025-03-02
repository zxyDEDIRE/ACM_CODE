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
const ll mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int mp[555][555];
ll p[555][555][111],s[555][555][111];
int hh[555][111];
int zz[555][111];
int n,m,q,k;

struct ST{
	int f[555][30];
	void init(int x,int op,int len)
	{
		if(op==1)
		{
			for(int i=1;i<=len;i++)
				f[i][0]=mp[x][i];
		}
		else
		{
			for(int i=1;i<=len;i++)
				f[i][0]=mp[i][x];
		}

		int t=log(len)/log(2)+1;//j定位 
		for(int j=1;j<t;j++)
		{
			for(int i=1;i<=len-(1<<j)+1;i++)
			{
				f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
				//f[i][j-1]为f[i][j]的长为2^j-1的前半段，另一段为f[i+(1<<(j-1))][j-1] 
			}
		} 
	}
	int query(int l,int r)
	{
		int k=log2(r-l+1);
		return min(f[l][k],f[r-(1<<k)+1][k]);
	}
}lx[555],ly[555];


void insert(int x1,int y1,int x2,int y2,ll c,int t)
{
	c%=mod;
	s[x1][y1][t]+=c;s[x1][y1][t]%=mod;
	s[x2+1][y2+1][t]+=c;s[x2+1][y2+1][t]%=mod;
	s[x1][y2+1][t]-=c;s[x1][y2+1][t]=(s[x1][y2+1][t]+mod)%mod;
	s[x2+1][y1][t]-=c;s[x2+1][y1][t]=(s[x2+1][y1][t]+mod)%mod;
}
void solve()
{
	cin>>n>>m>>q>>k;
	// n=500;m=500;
	// q=0;
	// k=100;
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++){
			mp[i][j]=k+10;
			for(int t=1;t<=k;t++)
				p[i][j][t]=s[i][j][t]=0,hh[j][t]=zz[i][t]=0;
		}
	for(int i=1;i<=q;i++)
	{
		int x,y,t;
		cin>>x>>y>>t;
		mp[x][y]=min(mp[x][y],t);
	}
	for(int i=1;i<=n;i++)
		lx[i].init(i,1,m);
	for(int i=1;i<=m;i++)
		ly[i].init(i,2,n);
	// cout<<"sdfd "<<lx[1].query()

	auto h=[&](int x,int y,int t)->int{
		// if(hh[x][t])return hh[x][t];
		int l=y,r=m,ans=l;
		while(l<r-1){
			int mid=(l+r)>>1;
			if(lx[x].query(y,mid)>t)ans=mid,l=mid;
			else r=mid;
		}
		while(ans<m && lx[x].query(y,ans+1)>t)ans++;
		hh[x][t]=ans;
		return ans;
	};
	auto z=[&](int x,int y,int t)->int{
		// if(zz[y][t])return zz[y][t];
		int l=x,r=n,ans=l;
		while(l<r-1){
			int mid=(l+r)>>1;
			if(ly[y].query(x,mid)>t)ans=mid,l=mid;
			else r=mid;
		}
		while(ans<n && ly[y].query(x,ans+1)>t)ans++;
		zz[y][t]=ans;
		return ans;
	};

	p[1][1][0]=1;
	int mi=k+10;
	ll ans=0;


	for(int t=0;t<k;t++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(mp[i][j]<=t)continue;
				if(p[i][j][t]==0)continue;
				int tmp;
				// heng
				tmp=h(i,j,t+1);
				if(tmp>j)
					insert(i,j+1,i,tmp,p[i][j][t],t+1);
				// zong
				tmp=z(i,j,t+1);
				if(tmp>i)
					insert(i+1,j,tmp,j,p[i][j][t],t+1);
			}
		}

		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				p[i][j][t+1]=(p[i-1][j][t+1]+p[i][j-1][t+1]-p[i-1][j-1][t+1]+s[i][j][t+1])%mod;

		// cout<<"time "<<t+1<<endl;
		// for(int i=1;i<=n;i++){
		// 	for(int j=1;j<=m;j++)
		// 		cout<<p[i][j][t+1]<<" ";
		// 	cout<<endl;
		// }
		// cout<<endl;
		if(p[n][m][t+1])
		{
			mi=min(mi,t+1);
			ans+=p[n][m][t+1];
			ans%=mod;
		}
	}



	if(!ans)cout<<-1<<endl;
	else cout<<ans<<" "<<mi<<endl;
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
/*
1
2 3 2 5
1 3 1
2 2 3


3 3 3 3 1 2
*/