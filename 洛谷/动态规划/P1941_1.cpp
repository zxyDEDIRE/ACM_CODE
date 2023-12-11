/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
// const int dx[]={0,0,1,-1,1,-1,1,-1};
// const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int dp[10011][1011];
int dx[maxn];
int dy[maxn];
int h[maxn];
int b[maxn];
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		cin>>dx[i]>>dy[i],h[i]=m+1,b[i]=-1;
	h[n]=m+1;b[n]=-1;
	for(int i=1;i<=k;i++)
	{
		int x,l,r;
		cin>>x>>l>>r;
		h[x]=r;
		b[x]=l;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			dp[i][j]=INF;
	int L=0;
	for(int i=0;i<n;i++)
	{
		int flag=0;
		for(int j=b[i]+1;j<h[i];j++)
			if(min(m,j+dx[i])>b[i+1]&&min(m,j+dx[i])<h[i+1]){
				dp[i+1][min(m,j+dx[i])]=min(dp[i+1][min(m,j+dx[i])],dp[i][j]+1);
				if(dp[i+1][min(m,j+dx[i])]!=INF)flag=1;
			}
		for(int j=max(dx[i],b[i+1]+1);j<h[i+1];j++)
			if(j>b[i+1]&&j<h[i+1]){
				dp[i+1][j]=min(dp[i+1][j],dp[i+1][j-dx[i]]+1);
				if(dp[i+1][j]!=INF)flag=1;
			}
		for(int j=b[i]+1;j<h[i];j++)
			if(max(0,j-dy[i])>b[i+1]&&max(0,j-dy[i])<h[i+1]){
				dp[i+1][max(0,j-dy[i])]=min(dp[i+1][max(0,j-dy[i])],dp[i][j]);
				if(dp[i+1][max(0,j-dy[i])]!=INF)flag=1;
			}
		L=i;
		if(flag==0)break;
	}
	int mi=INF;
	for(int i=0;i<=m;i++)
		mi=min(mi,dp[n][i]);
	if(mi!=INF)cout<<"1\n"<<mi<<endl;
	else
	{
		int cnt=0;
		for(int i=1;i<=L;i++)
			if(b[i]!=-1||h[i]!=m+1)
				cnt++;
		cout<<"0\n"<<cnt<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}