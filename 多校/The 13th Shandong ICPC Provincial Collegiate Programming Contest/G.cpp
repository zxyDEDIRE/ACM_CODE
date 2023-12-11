/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
struct node{
	int x,y;
}a[maxn];
vector<int>v[maxn];
map<int,int>mp;
int p[maxn];
int n,m,tot;
void solve()
{
	cin>>n;
	mp.clear();
	tot=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(!mp.count(p[i]-i))
			mp[p[i]-i]=++tot,v[tot].clear();
		v[mp[p[i]-i]].push_back(i);
	}
	int cnt=0;
	for(auto [x,y]:mp)
		a[++cnt]={x,y};
	sort(a+1,a+1+cnt,[&](node a,node b){
		return a.x>b.x;
	});
	ll ans=0;
	for(int i=1;i<=cnt;i++)
	{
		int x=a[i].y;
		if(v[x].size()<=1)continue;
		sort(v[x].begin(),v[x].end(),[&](int a,int b){return a>b;});
		for(int j=1;j<v[x].size();j+=2)
		{
			if(p[v[x][j]]+p[v[x][j-1]]<0)break;
			ans+=p[v[x][j]]+p[v[x][j-1]];
		}
	}
	cout<<ans<<endl;
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