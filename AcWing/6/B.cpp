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
const int maxn=1e6+100;
vector<int>v;
int l,r,flag=1;
void dfs(int x,int ans,int y)
{
	if(x>y)
	{
		v.push_back(ans);
		if(ans>r)flag=0;
		return ;
	}
	dfs(x+1,ans*10+4,y);
	dfs(x+1,ans*10+7,y);
}
void solve()
{
	cin>>l>>r;
	while(flag)
		dfs(1,0,flag++);
	int fl=0;
	int ans=0;
	for(int i=l;i<=r;i++)
	{
		while(v[fl]<i)fl++;
		ans+=(min(r,v[fl])-i+1)*v[fl];
		i=min(r,v[fl]);
	}
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