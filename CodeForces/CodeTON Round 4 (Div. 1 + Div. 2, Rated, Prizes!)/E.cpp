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
int a[maxn];
struct node{
	int x;
	bool operator<(const node&t)const{
		return a[t.x]<a[x];
	}
};
vector<int>v[maxn];
bitset<maxn>vis,ok;
set<int>S;
int n,m;
void init(){
	for(int i=1;i<=n;i++)
		v[i].clear();
	S.clear();
	ok.reset();
	
}
int bfs(int s)
{
	priority_queue<node>q;
	q.push({s});
	vis[s]=1;
	int cnt=0;
	while(!q.empty())
	{
		auto [x]=q.top();q.pop();
		ok[x]=1;
		if(a[x]>cnt)break;
		cnt++;
		vis[x]=1;
		for(auto y:v[x])
			if(!vis[y]){
				vis[y]=1;
				q.push({y});
			}
	}
	return cnt;
}
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!a[i])S.insert(i);
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(auto s:S){
		if(ok[s])continue;
		vis.reset();
		if(bfs(s)==n){
			cout<<"Yes"<<endl;
			return ;
		}
	}
	cout<<"No"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}