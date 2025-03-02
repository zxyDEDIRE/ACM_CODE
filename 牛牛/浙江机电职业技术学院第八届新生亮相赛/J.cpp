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
void solve()
{
	ll k,n,x;
	cin>>k>>n;
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>x,cout<<x-1<<endl;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].x,p[i].id=i;
	}
	sort(p+1,p+1+n,[&](node a,node b){
		return a.x<b.x;
	});
	__int128 id=1,len=1;
	int i=1;
	int t=0;
	while(1)
	{
		if(i>n)break;
		while(i<=n && p[i].x<=id)
		{
			p[i].y=t;
			i++;
		}
		t++;
	}
	sort(p+1,p+1+n,[&](node a,node b){
		return a.id<b.id;
	});
	for(int i=1;i<=n;i++)
		cout<<p[i].y<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
19273486754741928