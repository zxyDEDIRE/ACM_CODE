/*！*/
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
	int x,id;
}p[maxn];
ll ans[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x,p[i].id=i;
	sort(p+1,p+1+n,[&](node a,node b){
		return a.x<b.x;
	});
	ll now=0;
	for(int i=2;i<=n;i++)
		now+=p[i].x-p[1].x+1;
	ans[p[1].id]=now+1;
	// cout<<now<<endl;
	int l=0,r=n-1;
	for(int i=2;i<=n;i++)
	{
		l++;
		ll now=ans[p[i-1].id];
		now+=l*(p[i].x-p[i-1].x);
		now-=r*(p[i].x-p[i-1].x);
		// cout<<l<<" "<<r<<endl;
		ans[p[i].id]=now;
		r--;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";cout<<endl;
}
signed main(){
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}