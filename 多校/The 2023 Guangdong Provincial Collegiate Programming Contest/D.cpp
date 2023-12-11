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
	ll x,y;
}p[maxn];
bool vis[maxn];
ll sum;
int n,m;
void solve()
{
	cin>>n>>m;
	ll sum=0;
	ll len=n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y,sum+=p[i].x,vis[i]=0;
	sort(p+1,p+1+n,[&](node a,node b){
		return a.y-a.x>b.y-b.x;
	});
	for(int i=1;i<=n;i++)
	{
		if(p[i].y<=p[i].x)break;
		ll _len=len+1;
		if(_len<=m)
		{
			sum=sum+p[i].y-p[i].x;
			len=_len;
			vis[i]=1;
		}
		else {
			break;
		}
	}
	if(n==1)
	{
		sum=p[1].y;
	}
	else if(!vis[n]&&vis[n-1])
	{
		sum=sum-p[n].x+p[n].y;
		sum=max(sum,sum-p[n].y-p[n-1].y+p[n].x+p[n-1].x);
	}

	cout<<sum<<endl;
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
2 3
100 50
1 1000

1 2
100 50
*/