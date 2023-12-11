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
bitset<maxn>vis;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	vector<int>v;
	vector<pii>u;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]==2)
			v.push_back(i);
		if(p[i]==1)
		{
			if(u.size()&&u.back().second==i-1)u.back().second=i;
			else u.push_back({i,i});
		}
	}
	vis.reset();
	int ans=0;
	for(auto x:v)
	{
		if(vis[x])continue;
		vis[x]=1;
		vis[x+1]=vis[x-1]=1;
		ans++;
		int l=x-1;
		while(p[l])
		{
			vis[l-1]=1;
			l--;
		}
		int r=x+1;
		while(p[r])
		{
			vis[r+1]=1;
			r++;
		}
	}
	for(auto [x,y]:u)
	{
		if(vis[x])continue;
		if(x-1>=1&&!vis[x-1])
		{
			ans++;
			for(int i=x-1;i<=y;i++)
				vis[i]=1;
		}
		else if(y+1<=n&&!vis[y+1])
		{
			ans++;
			for(int i=x;i<=y+1;i++)
				vis[i]=1;
		}
		else
		{
			ans++;
			for(int i=x;i<=y;i++)
				vis[i]=1;
		}
	}

	// for(int i=1;i<=n;i++)
	// 	cout<<vis[i];
	// cout<<endl;
	for(int i=1;i<=n;i++)
		if(!vis[i])ans++;
	cout<<ans<<endl;
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
7
0 2 1 0 1 2 0
1 0 1 1 1 0 1

4
0 1 2 0
1 1 1 1


7
0 2 1 0 1 2 0
1 1 1 1 1 1 1
*/