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
struct node{
	int x,id;ll w;
}p[maxn];
bitset<1500>vis;
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char ch;cin>>ch;
		p[i].x=(ch=='1');
		p[i].id=i;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ll w;
		cin>>w;
		if(p[i].x==1)p[i].w=-w,ans+=w;
		if(p[i].x==0)p[i].w=w;
	}
	
	vector<vector<int>>mp;
	while(1)
	{
		sort(p+1,p+1+n,[&](node a,node b){
			return a.w>b.w;
		});
		ll _ans=ans;
		int cnt=m;
		for(int i=1;i<=m;i++)
			_ans+=p[i].w;
		if(_ans>ans)
		{
			vector<int>now;
			for(int i=1;i<=m;i++)
				p[i].w*=-1,now.push_back(p[i].id);
			mp.push_back(now);
			ans=_ans;
		}
		else break;
	}
	cout<<ans<<" "<<mp.size()<<endl;
	for(auto x:mp)
	{
		vis.reset();
		for(auto y:x)
			vis[y]=1;
		for(int i=1;i<=n;i++)
			cout<<vis[i];
		cout<<endl;
	}
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
3 2
1010
-2 -3 -9
*/