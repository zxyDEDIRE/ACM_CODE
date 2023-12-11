#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
int w[maxn];
int f[maxn];
int n,m,k,W;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n>>m>>k>>W;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
		cin>>f[i],p[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		int fa=find(x);
		int fb=find(y);
		if(f[fa]==f[fb]&&fa!=fb)
			p[fa]=fb,w[fb]+=w[fa];
	}
	vector<int>v;
	for(int i=1;i<=n;i++)
		if(find(i)==i&&f[i]==1)
			v.push_back(w[i]);
	sort(v.begin(),v.end(),[&](int a,int b){
		return a>b;
	});
	int ans=0;
	for(int i=0;i<min(k,(int)v.size());i++)
		ans+=v[i];
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}