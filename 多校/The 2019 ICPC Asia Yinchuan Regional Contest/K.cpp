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
const int maxn=1e6+10;
const int N=1e3+10;
int mpa[N][N];
int mpb[N][N];
pii a[maxn];
pii b[maxn];
int f[maxn];
int n,m;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void merge(int x,int y)
{
	int fa=find(x);
	int fb=find(y);
	if(fa!=fb)f[fa]=fb;
}
bool same(int x,int y)
{
	if(y==0||x==0)return 0;
	int fa=find(x);
	int fb=find(y);
	if(fa==fb)return 1;
	return 0;
}
int len[N][N];
int l[N][N];
int r[N][N];
int p[maxn];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mpa[i][j],a[mpa[i][j]]={i,j};
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mpb[i][j],b[mpb[i][j]]={i,j};
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int now=mpa[i][j];
			for(int k=0;k<4;k++)
			{
				int x=i+dx[k];
				int y=j+dy[k];
				if(x<1||y<1||x>n||y>m)continue;
				auto [_x,_y]=b[now];
				if(mpa[x][y]==mpb[_x+dx[k]][_y+dy[k]])
					merge(now,mpa[x][y]);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			len[i][j]=1;
			if(same(mpa[i][j],mpa[i-1][j]))
				len[i][j]=len[i-1][j]+1;
		}
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		int T;
		for(int j=1;j<=m;j++)
		{
			if(!same(mpa[i][j],mpa[i][j-1]))
			{
				T=j-1;
				cnt=1;
				l[i][j]=j;
				p[1]=j;
			}
			else
			{
				while(cnt&&len[i][p[cnt]]>=len[i][j])cnt--;
				l[i][j]=j;
				if(cnt)
					l[i][j]=p[cnt]+1;
				else l[i][j]=T+1;
				p[++cnt]=j;
			}
			
		}
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		int T;
		for(int j=m;j>=1;j--)
		{
			if(!same(mpa[i][j],mpa[i][j+1]))
			{
				T=j+1;
				cnt=1;
				r[i][j]=j;
				p[1]=j;
			}
			else{
				while(cnt&&len[i][p[cnt]]>=len[i][j])cnt--;
				r[i][j]=j;
				if(cnt)
					r[i][j]=p[cnt]-1; 
				else r[i][j]=T-1;
				p[++cnt]=j;
			}
			
		}
	}

	int ans=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			ans=max(ans,len[i][j]*(r[i][j]-l[i][j]+1));
			// cout<<i<<" "<<j<<" "<<len[i][j]*(r[i][j]-l[i][j]+1)<<endl;
		}
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
/*
3 3
1 2 3
8 9 4
7 6 5


1 2 3
9 8 4
7 6 5


3 3
1 2 3
4 5 6
8 7 9

5 6 1
7 9 3
2 4 8


3 3
1 2 3
4 5 6
7 8 9

9 2 6
4 5 3
8 7 1
*/