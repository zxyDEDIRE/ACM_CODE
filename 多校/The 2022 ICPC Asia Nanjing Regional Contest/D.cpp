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
int cnt[maxn];
ll p[maxn];
ll n,k,m,a,d;
int f(ll _a,ll _b)
{
	auto check=[&](int x)->bool{
		if(x)return _a+a+(x-1)*d>=_b;
		return _a>=_b;
	};
	int l=0,r=m+1,ans=r;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	while(ans>0&&check(ans-1))ans--;
	return ans;
}
bool check(ll mid)
{
	for(int i=0;i<=n;i++)
		cnt[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(i<=m&&p[i]+a+(i-1)*d>=mid){
			// cout<<"I:"<<i<<" add:"<<1<<endl;
			cnt[1]++;
		}
		if(i>m){
			if(p[i]>=mid)cnt[0]++;
			else if(p[i]+a+(m-1)*d>=mid)cnt[i-m+1]++;
			// cout<<"I:"<<i<<" add"<<i-m+1<<endl;
		}
		int len=f(p[i],mid);
		// cout<<"I:"<<i<<" len:"<<len<<endl;
		if(len && len<=i && len<=m &&i-len+2>=1){
			// cout<<"I:"<<i<<" sub:"<<i-len+2<<endl;
			cnt[i-len+2]--;
		}
	}
	int sum=0;
	for(int i=0;i<=n;i++)
	{
		sum+=cnt[i];
		if(sum>=k)return 1;
	}
	return 0;
}
void solve()
{
	cin>>n>>k>>m>>a>>d;
	ll ma=0;
	for(int i=1;i<=n;i++)
		cin>>p[i],ma=max(ma,p[i]);
	ll l=0,r=ma+a+(m-1)*d,ans=0;
	while(l<r-1){
		ll mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	while(check(ans+1))ans++;
	cout<<ans<<endl;
	// cout<<check(5)<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
6 4 3 1 2
1 1 4 5 1 4
I:1 len:3
I:2 len:3
I:3 add:1
I:3 len:1
I:3 sub:4
I:4 add2
I:4 len:0
I:5 add3
I:5 len:3
I:5 sub:4
I:6 add4
I:6 len:1
I:6 sub:7
*/
/*
6 4 3 1 2
1 1 4 5 1 4
4

7 3 2 4 0
1 9 1 9 8 1 0
9

8 3 5 0 0
2 0 2 2 1 2 1 8
2
*/