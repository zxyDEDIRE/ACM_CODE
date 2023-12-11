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
struct node{
	ll x,y,id;
}p[maxn];

int n;
void solve()
{
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++)
		cin>>p[i].x;
	for(int i=1;i<=n;i++)
		cin>>p[i].y,p[i].id=i,sum+=abs(p[i].x-p[i].y);
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.x!=b.x)
			return a.x<b.x;
		return a.y<b.y;
	});
	ll ans=sum;
	ll ma=0,mb=0;
	for(int i=n;i>=1;i--)
	{
		if(p[i].y>=p[i].x)
		{
			if(ma>=p[i].y)
				ans=max(ans,sum+2*(ma-p[i].y));
			if(mb>=p[i].y)
				ans=max(ans,sum+2*(mb-p[i].y));
			ma=max(ma,p[i].x);
		}
		else
		{
			if(ma>=p[i].x)
				ans=max(ans,sum+2*(ma-p[i].x));
			if(mb>=p[i].x)
				ans=max(ans,sum+2*(mb-p[i].x));
			mb=max(mb,p[i].y);
		}
	}
	cout<<ans<<endl;


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