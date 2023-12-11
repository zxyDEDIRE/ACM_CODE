/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
map<int,int>mp;
bitset<maxn>vis;
set<int>s;
int n,m;
bool ok(int x){
	if(x<*s.begin())return 1;
	return 0;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		v[i].clear();
	vis.reset();
	vis[0]=1;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(x>y)swap(x,y);
		v[x].push_back(y);
		vis[x]=1;
	}
	int l=1,r=1;
	int mi=n;
	s.clear();
	mp.clear();
	s.insert(n+1);
	mp[n+1]++;
	vector<pii>u;
	u.push_back({0,0});
	for(int i=1;i<=n;i++)
	{
		r=max(r,l);
		while(ok(r))
		{
			for(auto y:v[r])
				s.insert(y),mp[y]++;
			r++;
		}
		if(vis[i-1]==1&&r-1>u.back().second){
			u.push_back({i,r-1});
		}
		for(auto y:v[i]){
			mp[y]--;
			if(!mp[y])s.erase(y);
		}
	}
	int ans=0;
	// cout<<endl;
	// for(auto [x,y]:u)
	// 	cout<<x<<" "<<y<<endl;
	for(auto [x,y]:u)
	{
		int len=y-x+1;
		if(x==0)continue;
		ans+=len*(len+1)/2;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
9 4
1 4
1 6
2 8
3 6
*/