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
	int cnt=0,ma=0,ned=0;
	for(int i=0;;i++)
	{
		if(!s.count(i)){
			if(cnt==0)ned=i;
			cnt++;

		}
		if(cnt==2){
			ma=i;
			break;
		}
	}
	cout<<ned<<endl;
	s.insert(ned);
	while(1)
	{
		int y;cin>>y;
		if(y<0)break;
		cout<<y<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}