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
vector<pii>G[maxn];
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int fa[maxn];
set<int>st;
int flag;
int n,m;
int s,t;
void init(){
	memset(head+1,0,sizeof(int)*cnt);
	cnt=0;
	st.clear();
}
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dfs(int x,int f,int w)
{
	fa[x]=f;
	if(x!=t&&x!=s)
		st.insert(w);
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==f)continue;
		dfs(y,x,w^edge[i].w);
	}
}
void dfs1(int x,int w)
{
	// cout<<w<<" "<<(w^2)<<endl;
	if(st.count(w^0))flag=1;
	if(flag)return ;
	for(int i=head[x];i;i=edge[i].next)
		if(edge[i].to==fa[x]){
			dfs1(edge[i].to,w^edge[i].w);
		}		
}
void solve()
{
	cin>>n>>s>>t;
	init();
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	flag=0;
	dfs(t,0,0);
	// for(auto y:st)
	// 	cout<<y<<" ";
	// cout<<endl;
	dfs1(s,0);
	if(flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}