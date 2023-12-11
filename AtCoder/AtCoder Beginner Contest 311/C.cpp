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
int low[maxn],dfn[maxn],indx;
bool vis[maxn];
stack<int>s;
int n;
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	vis[x]=1;
	s.push(x);
	for(auto y:v[x])
	{
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		vector<int>q;
		int y;
		do{
			y=s.top();s.pop();
			q.push_back(y);
		}while(x!=y);
		if(q.size()>1)
		{
			reverse(q.begin(),q.end());
			cout<<q.size()<<endl;
			for(auto i:q)
				cout<<i<<" ";
			cout<<endl;
			exit(0);
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		v[i].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);

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