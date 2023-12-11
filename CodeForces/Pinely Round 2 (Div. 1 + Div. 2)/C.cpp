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
int n,k;
void solve()
{
	cin>>n>>k;
	set<int>s;
	for(int i=0;i<n;i++)
		cin>>p[i],s.insert(p[i]);
	for(int i=0;i<=n;i++)
		if(!s.count(i)){
			p[n]=i;
			break;
		}
	int t=n+1;
	for(int i=1;i<=n;i++)
		cout<<p[((i-k-1)%t+t)%t]<<" ";
	cout<<endl;

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