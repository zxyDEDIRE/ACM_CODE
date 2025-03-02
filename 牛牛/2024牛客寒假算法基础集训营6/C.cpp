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
vector<ll>p;
int t=3;
void init()
{
	p.push_back(0);
	p.push_back(1);
	p.push_back(1);
	while(p[t-1]<1e9)
	{
		p.push_back(p[t-1]+p[t-2]);
		t++;
	}
}
void solve()
{
	ll n;
	cin>>n;
	for(int i=0;i<t;i++)
		for(int j=i;j<t;j++)
			if(p[i]+p[j]<=n)
			{
				ll ned = n-p[i]-p[j];
				int fl=lower_bound(p.begin(),p.end(),ned)-p.begin();
				if(p[fl]==ned)
				{
					cout<<p[i]<<" "<<p[j]<<" "<<ned<<endl;
					return ;
				}
			}
	cout<<-1<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	init();
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}