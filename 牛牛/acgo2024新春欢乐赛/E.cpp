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
	set<int>s;
	for(int i=1;i<=n;i++)
		cin>>p[i],s.insert(p[i]);
	int mi=INF;
	while(s.size()>1)
	{
		mi=min(mi,*s.begin());
		vector<int>v;
		for(auto i:s){
			v.push_back(i);
			// cout<<i<<" ";
		}
		// cout<<endl;
		int len=v.size();
		s.clear();
		for(int i=0;i<len-1;i++)
			s.insert(v[i+1]-v[i]);
	}
	mi=min(mi,*s.begin());
	cout<<1ll*mi*n<<endl;
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
5
45 12 27 30 18

12 27 30 18 45
*/