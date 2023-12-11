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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
map<array<int,3>,bool>mp;
int ma=0;
void dfs(int x,int y,int z)
{
	if(mp[{x,y,z}])return ;
	mp[{x,y,z}]=1;
	int now=x*x+y*y+z*z;
	if(now>ma)
	{
		cout<<now<<endl;
		cout<<x<<" "<<y<<" "<<z<<endl;
		ma=max(ma,now);
	}

	if(y&&z)dfs(x+2,y-1,z-1);
	if(x&&z)dfs(x-1,y+2,z-1);
	if(x&&y)dfs(x-1,y-1,z+2);
}
void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	dfs(a,b,c);
	cout<<ma<<endl;
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
2 4 9

*/