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
int a[maxn];
int n,x,y;
void solve()
{
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)
		cin>>a[i];

	auto check=[&](int mid)->bool{
		int _x=x,_y=y;
		if(abs(x-y)>mid)return 0;
		for(int i=1;i<=n;i++)
		{
			int fa=(abs(_x-a[i])>mid);
			int fb=(abs(_y-a[i])>mid);
			if(fa&&fb)return 0;
			else if(fa)_y=a[i];
			else _x=a[i];
		}
		return 1;
	};


	int l=1,r=INF,ans=r;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	while(ans>1&&check(ans-1))ans--;
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}