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
	ll x,y;int op;
}p[maxn];
int n,c;
void solve()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		p[i].y=x,p[i].x=i,p[i].op=0;
	}
	p[1].op=1;
	// i * c - a[i]
	sort(p+2,p+1+n,[&](node a,node b){
		return a.x*c-a.y<b.x*c-b.y;
	});
	int cnt=n;
	// while(1)
	{
		// if(cnt==1)break;
		// int flag=0;
		for(int i=2;i<=n;i++)
		{
			if(p[i].op)continue;
			ll sum=p[1].y+p[i].y;
			if(sum>=p[i].x*c){
				cnt--;
				flag=1;
				p[i].op=1;
				p[1].y=sum;
			}
		}
		// if(!flag)break;
	// }
	cout<<(cnt==1?"Yes\n":"No\n");
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