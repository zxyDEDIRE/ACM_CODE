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
struct node{
	int l,r,ma,mi;
}t[maxn];
int p[maxn];
int a[maxn];
int b[maxn];
int n;
void solve()
{
	cin>>n;
	int ma=0;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		a[i]=a[i-1]+p[i];
		ma=max(ma,a[i]);
	}
	int l=0,r=ma,ans=0;

	auto check=[&](int mid)->bool{
		int ans=0;
		int flag=0;
		for(int i=1;i<=n;i++){
			if(flag==0)
			{
				ans+=p[i];
				if(ans>=mid)flag=1;
			}vasdfsazZxZx
			else ans=max(mid,ans+p[i]);
		}
		cout<<ans<<endl;
		if(ans<=ma)return 0;
		ma=max(ma,ans);
		return 1;
	};


	cout<<check(3)<<endl;

	// while(l<r-1)
	// {
	// 	int mid=(l+r)/2;
	// 	if(check(mid))ans=mid,l=mid;
	// 	else r=mid;
	// }
	// while(check(ans+1))ans++;
	// cout<<ans<<endl;



}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}