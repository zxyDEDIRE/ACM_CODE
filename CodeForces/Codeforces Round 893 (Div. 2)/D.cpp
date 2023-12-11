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
const int N=3010;
bool vis[N];
int dpa[N][N];
int pre[N][2];
int ma[N][N];
int mb[N][N];
int ans[N];
int to[N];
int p[N];
int n,k;
int sum0(int l,int r){
	return pre[r][0]-pre[l-1][0];
}
int sum1(int l,int r){
	return pre[r][1]-pre[l-1][1];
}
void solve()
{
	cin>>n>>k;
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=n+1;j++){
			dpa[i][j]=ma[i][j]=mb[i][j]=0;
		}
		to[i]=ans[i]=vis[i]=pre[i][0]=pre[i][1]=0;
	}
	for(int i=1;i<=n;i++){
		char ch;cin>>ch;
		p[i]=ch-'0';
		pre[i][0]=pre[i-1][0]+(p[i]==0);
		pre[i][1]=pre[i-1][1]+(p[i]==1);
	}


	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int cnt1=sum1(i,j);
			dpa[i][cnt1]=max(dpa[i][cnt1],j-i+1);

			int cnt0=sum0(i,j);
			mb[i][cnt0]=max(mb[i][cnt0],j-i+1);
			ma[j][cnt0]=max(ma[j][cnt0],j-i+1);
		}
		for(int j=1;j<=k;j++)
		{
			dpa[i][j]=max(dpa[i][j],dpa[i][j-1]);
			mb[i][j]=max(mb[i][j],mb[i][j-1]);
			ma[i][j]=max(ma[i][j],ma[i][j-1]);
		}
	}



	for(int j=0;j<=k;j++)
	{
		for(int i=1;i<=n;i++)
			ma[i][j]=max(ma[i-1][j],ma[i][j]);
		for(int i=n;i>=1;i--)
			mb[i][j]=max(mb[i+1][j],mb[i][j]);
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			int x=dpa[i][j];
			if(i-1>=1)to[x]=max(to[x],ma[i-1][k-j]);
			if(i+x<=n)to[x]=max(to[x],mb[i+x][k-j]);
			vis[x]=1;
		}
	}	

	for(int i=0;i<=n;i++)
	{
		if(!vis[i])continue;
		for(int j=1;j<=n;j++)
			ans[j]=max(ans[j],i*j+to[i]);
	}

	// for(int i=0;i<=n;i++)
	// 	cout<<"to["<<i<<"]="<<to[i]<<endl;
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" \n"[i==n];



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
7 7
1000100
2 2
11
*/