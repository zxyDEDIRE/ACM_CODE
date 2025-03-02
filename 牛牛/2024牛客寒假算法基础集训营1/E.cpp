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
	int x,y;
}p[maxn];
vector<pii>v;
int a[maxn];
int n,m,len;
int ans;
void dfs(int x)
{
	if(x==len)
	{
		for(int i=1;i<=n;i++)
			p[i].x=a[i],p[i].y=i;
		sort(p+1,p+1+n,[&](node a,node b){
			if(a.x!=b.x)return a.x>b.x;
			return a.y<b.y;
		});
		for(int i=1;i<=n;i++)
			if(p[i].y==1)
				ans=min(ans,i);
		return ;
	}
	auto &[_x,_y]=v[x];
	a[_x]+=3;
	dfs(x+1);
	a[_x]-=3;

	a[_y]+=3;
	dfs(x+1);
	a[_y]-=3;

	a[_x]++;
	a[_y]++;
	dfs(x+1);
	a[_x]--;
	a[_y]--;

}
void solve()
{
	cin>>n>>m;
	v.clear();
	ans=INF;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(x==1||y==1)a[1]+=3;
		else v.push_back({x,y});
	}
	len=v.size();
	dfs(0);
	cout<<ans<<endl;
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