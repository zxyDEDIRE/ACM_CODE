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
int l,r,cnt;
int dfs(int x,int l,int r,int cnt)
{
	cout<<x<<" "<<l<<" "<<r<<" "<<((l+r)>>1)<<endl;
	if(x==cnt)return 1;
	if(l==r)return 0;
	int ans=0;
	int mid=((l+r)>>1);
	ans+=dfs(x+1,l,mid-1,cnt);
	ans+=dfs(x+1,mid+1,r,cnt);
	return ans;
}
void solve()
{
	cin>>l>>r>>cnt;
	cout<<dfs(1,l,r,cnt)<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}