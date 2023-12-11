#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);
#define int long long
typedef long long ll;
typedef pair<int,int> P;
const int N=2e5+7;
const int mod=998244353;
int n,x,minn=LLONG_MAX;
struct poi
{
    int a,num;
}a[N];
int vis[N];
int dp[N];
int ans=0;
void dfs(int x,int num,int mi)
{
    if(x<=ans)return;
    if(num==n){
        ans=max(ans,x);
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vis[i]=1;
        dfs(x%a[i].a,num+1);
        vis[i]=0;
    }
}
void solve()
{
	cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].a,minn=min(minn,a[i].a);
    cin>>x;
    // for(int i=1;i<=n;i++)a[i].num=x%a[i].a;
    sort(a+1,a+1+n,[&](poi a,poi b){
        return a.num>b.num;
    });
    dfs(x,0,1e18);
    cout<<ans<<endl;
}
signed main()
{
	//IOS
	int __=1;
	//cin >> __;
	while (__--)
		solve();
}