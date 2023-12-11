/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
int low[maxn],dfn[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
int out[maxn];
int in[maxn];
stack<int>s;
int n;
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	vis[x]=1;
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
		++tot;
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
		int x;
		while(cin>>x&&x)
			v[i].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	if(tot==1){
		cout<<1<<endl<<0<<endl;
		return ;
	}
	for(int x=1;x<=n;x++)
	{
		for(auto y:v[x])
			if(col[x]!=col[y]){
				out[col[x]]++;
				in[col[y]]++;
			}
	}
	int ans_a=0,ans_b=0;
	for(int i=1;i<=tot;i++)
	{
		if(!in[i])ans_a++;
		if(!out[i])ans_b++;
	}
	cout<<ans_a<<endl<<max(ans_a,ans_b)<<endl;

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
/*
2
2 0
1 0
*/