#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
pii p[maxn];
pll sum[maxn];
ll m;
int n;
bool check(int mid)
{
	if(mid==0)return 1;
	for(int i=1;i<=n;i++)
	{
		priority_queue<int,vector<int>,less<int>>q;
		ll now=0;
		for(int j=i;j<=n;j++)
		{
			q.push(p[j].first);now+=p[j].first;
			while((int)q.size()>mid)
			{
				int x=q.top();q.pop();
				now-=x;
			}
			if((int)q.size()==mid && now+p[j].second-p[i].second<=m)return 1;
		}
	}
	return 0;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	sort(p+1,p+1+n,[&](pii a,pii b){
		if(a.second!=b.second)
			return a.second<b.second;
		return a.first<b.first;
	});


	int l=0,r=n,ans=0;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	while(ans<n && check(ans+1))
		ans++;
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



/*
a1 + a2 + a3 + .. + an 
abs(b1 - b2) + abs(b2 - b3)

*/