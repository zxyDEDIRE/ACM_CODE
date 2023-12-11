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
struct Edge{
	int to,next,fl,x,y;
}edge[maxn];
int head[maxn],cnt;
struct NODE{
	int x,y,z;
};
struct node{
	char mp[33][33];
	int a=0,b=0;
	bool operator<(const node&x)const{
		if(x.mp!=mp)return x.mp<mp;
		if(x.a!=a)return x.a>a;
		if(x.b!=b)return x.b>b;
		return 0;
	}
}p[111];
map<node,int>MAP;
vector<int>ans_fu[111];
vector<NODE>ans;
bool vis[111];
bool fu[111];
int in[111];
int n,m,k;
void add(int from,int to,int fl,int x,int y)
{
	edge[++cnt].x=x;
	edge[cnt].y=y;
	edge[cnt].fl=fl;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dfs(int x)
{
	ans.push_back({2,x});
	for(auto i:ans_fu[x])
		ans.push_back({2,i,0});
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		int fl=edge[i].fl;
		if(vis[y])continue;
		ans.push_back({1,edge[i].x,edge[i].y});
		dfs(y);
	}
}
void doit(int x,int y)
{
	int cnt=0,a,b;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(p[x].mp[i][j]!=p[y].mp[i][j])
				cnt++,a=i,b=j;
	if(cnt==1)add(x,y,1,a,b),add(y,x,1,a,b),in[x]++,in[y]++;
}
void solve()
{
	cin>>n>>m>>k;k++;
	for(int o=1;o<=k;o++)
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>p[o].mp[i][j];
				if(p[o].mp[i][j]=='0')p[o].a++;
				else p[o].b++;
			}
			cout<<MAP.count(p[o])<<endl;
			if(MAP.count(p[o]))
				ans_fu[MAP[p[o]]].push_back(o);
			else MAP[p[o]]=o;
		}
			
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(fu[i]||fu[j])continue;
			if(abs(p[i].a-p[j].a)+abs(p[i].b-p[j].b)>=3)continue;
			doit(i,j);
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" "<<in[i]<<" "<<MAP[p[i]]<<endl;
	}
	for(int i=1;i<=n;i++)
		if(in[i]==1){
			cout<<i<<endl;
			vis[i]=1;
			dfs(i);
			break;
		}
	// cout<<ans.size()-1<<endl;
	// for(int i=1;i<ans.size();i++)
	// {
	// 	auto [fl,x,y]=ans[i];
	// 	if(fl==1)cout<<1<<" "<<x<<" "<<y<<endl;
	// 	else cout<<2<<" "<<x<<endl;
	// }
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
3 2 4 1

1->2
2->1

2->3
3->2
*/