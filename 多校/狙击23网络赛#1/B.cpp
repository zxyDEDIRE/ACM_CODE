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
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		v[i].clear(),vis[i]=0;
	for(int i=2;i<=n;i++)
	{
		int x;cin>>x;
		v[x].push_back(i);
	}
	queue<pii>q;
	q.push({1,0});
	vis[1]=1;
	int ans=0;
	while(!q.empty())
	{
		auto [x,t]=q.front();q.pop();
		ans++;
		for(auto y:v[x])
		{
			if(vis[y])continue;
			vis[y]=1;
			q.push({y,t+1});
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
	for(int i=1;i<=__;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*

*/