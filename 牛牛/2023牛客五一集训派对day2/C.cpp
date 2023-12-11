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
vector<int>v[maxn];
bitset<maxn>vis;
vector<int>p;
int n;
void dfs(int x)
{
	vis[x]=1;
	int fl=1;
	for(auto y:v[x])
	{
		if(vis[y])continue;
		fl=0;
		dfs(y);
	}
	if(fl)
		p.push_back(x);
}
void solve()
{
	cin>>n;
	if(n==1){
		cout<<0<<endl;
		return ;
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	int ans=((int)(p.size())+1)/2;

    
	if(p.size()&1)
	{
		cout<<ans<<endl;
		for(int i=0;i<ans-1;i++)
			cout<<p[i]<<" "<<p[i+ans]<<" "<<endl;
		cout<<1<<" "<<p[ans-1]<<endl;
	}
	else
	{
    	if(v[1].size()==1)cout<<ans+1<<endl;
    	else cout<<ans<<endl;
        if(v[1].size()==1)cout<<1<<" "<<p[0]<<endl;
		for(int i=0;i<ans;i++)
			cout<<p[i]<<" "<<p[i+ans]<<" "<<endl;
	}
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
8
1 2
1 3
3 4
3 5
3 6
3 7
3 8

7
1 2
1 7
2 3
2 4
2 5
2 6

3
1 2
2 3


5
1 2
2 3
2 4
2 5

我们的想法：
首先枚举一个A节点 ，那么A与原点的连线的中垂线 
是所有可能的圆心（经过A以及圆心）必定在这条中垂线上

那么接下俩枚举B点，求出圆心
那么如果B与另外一点B'以及A、圆心在同一个圆上，那么B与B'求出的圆心是同一个
就可以用map计数，直接求最大值

*/