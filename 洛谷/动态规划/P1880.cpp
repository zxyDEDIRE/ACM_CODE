/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int dpa[210][210];
int dpb[211][211];
int sum[maxn];
int p[maxn];
int n;
int dfsa(int l,int r){
	if(dpa[l][r]!=-1)return dpa[l][r];
	if(l==r)return dpa[l][r]=0;
	for(int i=l;i<r;i++)
		dpa[l][r]=max(dpa[l][r],dfsa(l,i)+dfsa(i+1,r)+sum[r]-sum[l-1]);
	return dpa[l][r];
}
int dfsb(int l,int r){
	if(dpb[l][r]!=INF)return dpb[l][r];
	if(l==r)return dpb[l][r]=0;
	for(int i=l;i<r;i++)
		dpb[l][r]=min(dpb[l][r],dfsb(l,i)+dfsb(i+1,r)+sum[r]-sum[l-1]);
	return dpb[l][r];
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n*2;i++)
		for(int j=1;j<=n*2;j++)
			dpa[i][j]=-1,dpb[i][j]=INF;
	for(int i=1;i<=n*2;i++){
		if(i<=n)cin>>p[i];
		else p[i]=p[i-n];
		sum[i]=sum[i-1]+p[i];
	}
	dfsa(1,n*2-1);
	dfsb(1,n*2-1);
	int ma=-1,mi=INF;
	for(int i=1;i+n-1<n*2;i++)
	{
		ma=max(ma,dpa[i][i+n-1]);
		mi=min(mi,dpb[i][i+n-1]);
	}
	cout<<mi<<endl<<ma<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}