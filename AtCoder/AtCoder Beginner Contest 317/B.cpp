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
int n,mi,ma;
void solve()
{
	cin>>n;
	set<int>s;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		s.insert(x);
	}
	mi=*s.begin();
	ma=*s.rbegin();
	for(int i=mi;i<=ma;i++)
		if(!s.count(i)){cout<<i<<endl;
return ;
}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);vbnm         
		solve();
	return 0;
}
/*
*/
/*
uvbnm
*/