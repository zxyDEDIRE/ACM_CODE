/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
set<int>s;
int p[maxn];
int n,cnt;
void dfs(int step)
{
	if(step>1&&p[1]==0)return ;
	if(step==9)
	{
		cnt++;
		if(cnt==n)
		{
			int ans=0;
			p[9]=p[7];
			for(int i=1;i<=9;i++)
				ans=ans*10+p[i];
			cout<<ans<<endl;
		}
		
		// s.insert(ans);
		return ;
	}
	else if(step==6)
	{
		p[6]=p[5];
		dfs(step+1);
	}
	else if(step==2)
	{
		p[2]=p[1];
		dfs(step+1);
	}
	else
	{
		for(int i=0;i<=9;i++)
		{
			p[step]=i,dfs(step+1);
		}
	}
}
void solve()
{
	cin>>n;
	dfs(1);

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