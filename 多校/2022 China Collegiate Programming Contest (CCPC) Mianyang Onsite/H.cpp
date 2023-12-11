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
vector<pii>p;
vector<int>a,b;
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		p.push_back({x,1});
	}
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		p.push_back({x,-1});
	}
	sort(p.begin(),p.end());
	for(int i=0;i<n*2;i++)
	{
		if(i%2==0){
			if(p[i].second==1)a.push_back(p[i].first);
		}
		else{
			if(p[i].second==-1)b.push_back(p[i].first);
		}
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}