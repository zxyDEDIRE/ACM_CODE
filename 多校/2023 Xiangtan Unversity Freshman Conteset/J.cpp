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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int mp[100];
int cnt;
int vis[100];
int n,m,ans=0;
void dfs(int x,int cnt)
{
	if(cnt==((1ll<<m)-1)){
		ans++;
		return ;
	}
	if(x==n)return ;
	for(int i=x+1;i<=n;i++)
	{
		if(cnt&mp[i])continue;
		dfs(i,cnt^mp[i]);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		mp[i]=0;
		int k,x;cin>>k;
		while(k--){
			cin>>x;x--;
			mp[i]|=(1ll<<x);
		}
	}
	dfs(0,0);
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