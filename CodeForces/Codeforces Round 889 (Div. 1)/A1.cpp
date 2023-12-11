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
int p[maxn];
int n;
void solve()
{
	cin>>n;
	int ma=0,fl=1;
	vector<pii>ans;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(abs(p[i])>ma)
		{
			ma=abs(p[i]);
			fl=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i==fl)continue;
		p[i]+=p[fl];
		ans.push_back({i,fl});
	}
	if(p[fl]>=0)
	{
		for(int i=2;i<=n;i++)
		{
			p[i]+=p[i-1];
			ans.push_back({i,i-1});
		}
	}
	else
	{
		for(int i=n-1;i>=1;i--)
		{
			p[i]+=p[i+1];
			ans.push_back({i,i+1});
		}
	}


	// for(int i=1;i<=n;i++)
	// 	cout<<p[i]<<" \n"[i==n];
	cout<<ans.size()<<endl;
	for(auto [x,y]:ans)
		cout<<x<<" "<<y<<endl;
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