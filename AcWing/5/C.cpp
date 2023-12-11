/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=5e6+100;
struct node{
	int x,y,w;
}p[maxn];
bool vis[maxn];
int fa[maxn];
pii a[maxn];
int c[maxn];
int k[maxn];
int n,m;
int find(int r){
	return fa[r]=fa[r]==r?fa[r]:find(fa[r]);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].first>>a[i].second;
	for(int i=1;i<=n;i++)
		cin>>c[i],p[++m]={i,i,c[i]};
	for(int i=1;i<=n;i++)
		cin>>k[i];
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			p[++m]={i,j,(abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second))*(k[i]+k[j])};
	sort(p+1,p+1+m,[&](node a,node b){
		return a.w<b.w;
	});
	int ans=0;
	vector<int>v;
	vector<pii>e;
	for(int i=1;i<=m;i++)
	{
		auto [x,y,w]=p[i];
		if(x!=y)
		{
			int FA=find(x);
			int FB=find(y);
			if(FA!=FB&&(!vis[FA]||!vis[FB]))
			{
				fa[FA]=FB;
				vis[FB]|=vis[FA];
				vis[FA]|=vis[FB];
				e.push_back({x,y});
				ans+=w;
				// cout<<"s:: "<<x<<" "<<y<<" "<<w<<endl;
			}
		}
		else
		{
			int FA=find(x);
			if(vis[FA])continue;
			vis[FA]=1;
			ans+=w;
			v.push_back(x);
			// cout<<"t:: "<<x<<" "<<FA<<" "<<w<<endl;
		}
	}
	// cout<<endl;
	cout<<ans<<endl;
	cout<<v.size()<<endl;
	for(auto i:v)
		cout<<i<<" ";cout<<endl;
	cout<<e.size()<<endl;
	for(auto [x,y]:e)
		cout<<x<<" "<<y<<endl;

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}