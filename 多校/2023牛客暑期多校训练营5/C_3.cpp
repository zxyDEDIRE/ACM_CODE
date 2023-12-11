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
stack<int>s;
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
int n;
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	vis[x]=1;
	int num=0;
	for(auto y:v[x])
	{
		if(!dfn[y])
		{
			num++;
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		tot++;
		int y;
		do{
			y=s.top();
			s.pop();
			vis[y]=0;
			col[y]=tot;
		}while(x!=y);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int x;cin>>x;
			if(x==0)continue;
			v[i].push_back(j);
		}
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	if(tot==1)cout<<n<<endl;
	else cout<<n-1<<endl;
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

*/