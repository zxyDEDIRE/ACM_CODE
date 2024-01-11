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
int p[maxn];
int c[maxn];
int n;
void solve()
{
	cin>>n;
	vector<pii>v;
	for(int i=1,x;i<=n;i++)
		cin>>x,v.push_back({x,1});
	for(int i=1,x;i<=n;i++)
		cin>>x,v.push_back({x,0});
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(v.begin(),v.end());
	sort(c+1,c+1+n);
	stack<int>s;
	int cnt=0;
	for(auto [x,fl]:v)
	{
		if(fl==0)p[++cnt]=x-s.top(),s.pop();
		else s.push(x);
	}
	sort(p+1,p+1+n,[&](int a,int b){return a>b;});
	ll sum=0;
	for(int i=1;i<=n;i++)
		sum+=p[i]*c[i];
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