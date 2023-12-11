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
int dfn[maxn],low[maxn],indx;
bitset<maxn>vis;
stack<int>s;
vector<int>ans;
int n,k;
void init()
{
	for(int i=1;i<=n;i++)
	{
		dfn[i]=low[i]=vis[i]=0;
		v[i].clear();
	}
	indx=0;
	ans.clear();
}
void tarjan(int x)
{
	low[x]=dfn[x]=++indx;
	vis[x]=1;
	s.push(x);
	for(auto y:v[x])
	{
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		int cnt=0;
		int y=0;
		do{
			y=s.top();s.pop();
			cnt++;
			vis[y]=0;
		}while(x!=y);
		if(cnt>1)
			ans.push_back(cnt);
	}
}
void solve()
{
	cin>>n>>k;
	init();
	int flag=1,fa=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		v[x].push_back(i);
		if(x!=i)flag=0;
		if(x==i)fa=1;
	}
	if(k==1){
		cout<<(flag?"YES\n":"NO\n");
		return ;
	}
	if(fa==1){
		cout<<"NO"<<endl;
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(auto i:ans)
		if(i!=k){
			cout<<"NO\n";
			return ;
		}
	cout<<"YES\n";

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