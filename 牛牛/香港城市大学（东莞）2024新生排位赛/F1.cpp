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
int n,m,q,k;

struct St{
	int f[555][555][10][10];
	void init(int m,int n){

		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				f[i][j][0][0]=mp[i][j];

		int t=log(n)/log(2)+1;//j定位 
		for(int i=0;i<=t;i++){
			for(int j=0;j<=t;j++){
				if(i==0&&j==0)
					continue;
				for(int row=1;row+(1<<i)-1<=m;row++){
					for(int col=1;col+(1<<j)-1<=n;col++){
						if(i)f[row][col][i][j]=min(f[row][col][i-1][j],
							f[row+(1<<(i-1))][col][i-1][j]);
						else f[row][col][i][j]=min(f[row][col][i][j-1],
							f[row][col+(1<<(j-1))][i][j-1]);
					}
				}
			}
		}
	}
	int query(int x1,int y1,int x2,int y2)
	{
		int k1 = log(double(x2 - x1 + 1)) / log(2.0);
		int k2 = log(double(y2 - y1 + 1)) / log(2.0);
		int m1 = f[x1][y1][k1][k2];
		int m2 = f[x2 - (1<<k1) + 1][y1][k1][k2];
		int m3 = f[x1][y2 - (1<<k2) + 1][k1][k2];
		int m4 = f[x2 - (1<<k1) + 1][y2 - (1<<k2) + 1 ][k1][k2];
		int _max = min(min(m1,m2),min(m3,m4));
		return _max;
	}
}st;


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
	// cin>>n>>m>>q>>k;
	n=500;m=500;
	q=0;
	k=100;
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++){
			mp[i][j]=k+10;
			for(int t=1;t<=k;t++)
				p[i][j][t]=s[i][j][t]=0;
		}
	for(int i=1;i<=q;i++)
	{
		int x,y,t;
		cin>>x>>y>>t;
		mp[x][y]=min(mp[x][y],t);
	}
	st.init(n,m);


	////////////////////////////////////////////////
	// cout<<endl;
	// cout<<"MP"<<endl;
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++)
	// 		cout<<mp[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	////////////////////////////////////////////////

	auto h=[&](int x,int y,int t)->int{
		int l=y,r=m,ans=l;
		while(l<r-1){
			int mid=(l+r)>>1;
			if(st.query(x,y,x,mid)>t)ans=mid,l=mid;
			else r=mid;
		}
		while(ans<m && st.query(x,y,x,ans+1)>t)ans++;
		return ans;
	};
	auto z=[&](int x,int y,int t)->int{
		int l=x,r=n,ans=l;
		while(l<r-1){
			int mid=(l+r)>>1;
			if(st.query(x,y,mid,y)>t)ans=mid,l=mid;
			else r=mid;
		}
		while(ans<n && st.query(x,y,ans+1,y)>t)ans++;
		return ans;
	};

	p[1][1][0]=1;
	for(int t=0;t<k;t++)
	{
		// if(t==0)insert(1,1,1,1,1,0);
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

	}



	int mi=k+10;
	ll ans=0;
	for(int i=1;i<=k;i++)
	{
		if(p[n][m][i])
		{
			mi=min(mi,i);
			ans+=p[n][m][i];
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