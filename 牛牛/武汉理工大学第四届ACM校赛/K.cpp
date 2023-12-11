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
bool check(int sum,int n)
{
	// cout<<n<<endl;
	for(int i=1;i<=n;i++)
	{
		int len=n-i+1;
		int x=sum/len;
		x=min(x,i);
		sum-=len*x;
	}
	return sum==0;
}
void solve()
{
	int n;
	cin>>n;
	int l=1,r=1e6,ans=r;
	while(l<r-1)
	{
		int mid=(l+r)/2;
		if(check(n,mid))ans=mid,r=mid;
		else l=mid;
	}
	while(ans>1&&check(n,ans-1))ans--;
	cout<<ans<<endl;
	int sum=n;
	for(int i=1;i<=ans;i++)
	{
		int len=ans-i+1;
		int x=sum/len;
		x=min(x,i);
		sum-=len*x;
		cout<<x<<" ";
	}
	cout<<endl;
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