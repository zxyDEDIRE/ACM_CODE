/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
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
int a[maxn];
int b[maxn];
int p[maxn];
int n;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
bool check(int mid)
{
	// for(int i=1;i<=n;i++)
		// p[i]=i;
	int ma=a[1];
	for(int i=1;i<n;i++)
	{
		int nxt=a[i]+b[i]+mid;
		ma=max(ma,nxt);
		if(a[i+1]>ma)return 0;
	}
	return 1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	int l=0,r=a[n]-a[1],ans=r;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	while(ans>=1&&check(ans-1))ans--;
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
2
1 10
2 0
*/