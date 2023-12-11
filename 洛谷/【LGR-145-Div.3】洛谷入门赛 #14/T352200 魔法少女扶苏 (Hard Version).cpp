/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
const int N=3e3+10;
int p[N][N];
int a[N];
int b[N];
int n,m,k;
bool check(int mid)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x=a[i]+b[j]-mid*(n+m);
			int y=p[i][j]-mid;
			if(y>=x)cnt++;
			if(cnt>=k)return 1;
		}
	}
	return 0;
}
void solve()
{
	cin>>n>>m>>k;
	int ma=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>p[i][j],ma=max(ma,p[i][j]);
			a[i]+=p[i][j];
			b[j]+=p[i][j];
		}
	int l=0,r=ma,ans=r;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	while(ans>=1 && check(ans-1))ans--;
	cout<<ans<<endl;
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
/*
3 3 3
1 1 1
1 1 1
1 1 1
*/