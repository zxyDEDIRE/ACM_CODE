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
int p[maxn];
int s[maxn];
int res=0;
int n;
void dfs(int step,int x,int ans,vector<pii>v={})
{
	if(step==4)
	{
		// cout<<ans<<endl;
		if(res<=ans)
		{
			res=ans;
			cout<<res<<endl;
			for(auto [x,y]:v)
				cout<<x<<" "<<y<<endl;
			cout<<endl; 
		}
		return ;
	}
	if(x>n)return ;
	for(int i=x;i<=n;i++)
	{
		vector<pii>now=v;
		now.push_back({x,i});
		dfs(step+1,i+1,ans*(s[i]^(s[x-1])),now);
	}
}
void solve()
{
	cin>>n;
	srand(time(0));
	for(int i=1;i<=n;i++)
	{
		int x;x=rand();
		s[i]=(s[i-1]^x);
	}
	dfs(1,1,1);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
10
6 7 8 9 0 7 6 5 6 5

*/