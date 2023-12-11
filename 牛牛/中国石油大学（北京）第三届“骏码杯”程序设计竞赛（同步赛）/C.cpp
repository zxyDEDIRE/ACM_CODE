/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
vector<int>v[maxn];
bitset<maxn>vis;
set<int>s;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	vis.reset();
	s.clear();
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		int x=p[i];
		for(int j=2;j*j<=x;j++)
			if(x%j==0){
				if(!vis[j])vis[j]=1,v[j].clear(),s.insert(j);
				v[j].push_back(i);
				while(x%j==0)x/=j;
			}
		if(x>1){
			if(!vis[x])vis[x]=1,v[x].clear(),s.insert(x);
			v[x].push_back(i);
		}
	}
	ll res=0;
	// for(int x=1;x<=1e6;x++)
	for(auto x:s)
	{
		if(v[x].size()==0)continue;
		ll ans= 1ll * (1+n)*n/2;
		ll s=0;
		v[x].push_back(n+1);
		// cout<<ans<<endl;
		for(auto i:v[x])
		{
			ll y=i-s-1;
			// cout<<"Y "<<y<<endl;
			ans -= 1ll*(y+1)*y/2;
			s=i;
		}
		res+=ans;
		// cout<<x<<" "<<ans<<endl;
	}
	cout<<res<<endl;

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 1 0

*/