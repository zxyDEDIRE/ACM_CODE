/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
vector<int>v[111],tot;
int c[maxn];
int n,m,ans;
vector<int> vector_set_union(vector<int>v1 ,vector<int>v2){
	vector<int>v;
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v));
	return v;
}
void dfs(int x,vector<int>now)
{
	if(x>m)
	{
		if(now==tot)ans++;
		return ;
	}
	dfs(x+1,vector_set_union(now,v[x]));
	dfs(x+1,now);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>c[i];
		for(int j=1;j<=c[i];j++)
		{
			int x;cin>>x;
			v[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++)
		tot.push_back(i);
	dfs(1,{});
	cout<<ans<<endl;
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