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
struct node{ll t,a,b,id;};
multiset<int>s[maxn];
ll val[maxn],sum;
vector<node>v;
vector<int>u;
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)val[i]=INF;
	for(int i=1;i<=m;i++)
	{
		int S,t,p,c;
		cin>>S>>t>>p>>c;
		for(int j=1;j<=c;j++)
		{
			int a,b;
			cin>>a>>b;
			s[a].insert(b);
			ll K=1ll*b*p/100;
			v.push_back({S,b,(int)K,a});
			v.push_back({t+1,(int)K,b,a});
		}
	}
	sort(v.begin(),v.end(),[&](node a,node b){
		return a.t<b.t;
	});
	for(auto i:v)
	{
		if(u.size()==0||i.t!=u.back())
			u.push_back(i.t);
	}
	for(int i=1;i<=n;i++){
		val[i]=*s[i].begin();
		sum+=val[i];
	}
	ll ans=sum;
	int indx=0;
	for(auto now:u)
	{
		while(indx<v.size()&&v[indx].t==now)
		{
			auto [_,x,y,id]=v[indx];
			sum-=val[id];
			s[id].erase(s[id].find(x));
			s[id].insert(y);
			val[id]=*s[id].begin();
			sum+=val[id];
			indx++;
		}
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
*/