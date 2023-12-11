#include<bits/stdc++.h>
using namespace std;
// #define endl "\n"
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
const int N=2e5+100;
vector<int>v[maxn],G[maxn];
bitset<N>vis,ok;
int in[maxn];
int n,m;
void AddEdge(){
	for(int x=1;x<=n;x++){
		if(!vis[x])continue;
		for(auto y:v[x]){
			if(!vis[y])continue;
			in[y]++;
		}
	}
}
bool Ftopsort(vector<int>&ano)
{
	AddEdge();
	for(auto x:ano)
	{
		if(in[x])return 0;
		for(auto y:v[x]){
			if(!vis[y])continue;
			in[y]--;
		}
	}
	return 1;
}
vector<int> topsort()
{
	AddEdge();
	vector<int>ans;
	queue<int>q;
	int num=0;
	for(int i=1;i<=n;i++)
		if(vis[i]){
			num++;
			if(!in[i])q.push(i);
		}
	while(!q.empty())
	{
		int x=q.front();q.pop();
		num--;
		ans.push_back(x);
		for(auto y:v[x])
		{
			if(!vis[y])continue;
			in[y]--;
			if(!in[y])q.push(y);
		}
	}
	if(num)return vector<int>{-1};
	return ans;
}
void dfs1(int x){
	if(vis[x]||ok[x])return ;
	vis[x]=1;
	for(auto y:v[x])
		dfs1(y);
}
void dfs2(int x){
	if(vis[x]||ok[x])return ;
	vis[x]=1;
	for(auto y:v[x])
		dfs2(y);
}
void NO(){cout<<-1<<endl;}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		G[y].push_back(x);
	}
	int k;
	cin>>k;
	vector<int>ano(k);
	for(int i=0;i<k;i++)
		cin>>ano[i],vis[ano[i]]=1,ok[ano[i]]=1;
	bool ans1=Ftopsort(ano);
	if(!ans1)return NO();
	vis.reset();
	for(auto x:ano)
		for(auto y:G[x])
			dfs1(y);
	vector<int>ans2=topsort();
	if(ans2.size() && ans2[0]==-1)return NO();
	vis.reset();
	for(auto x:ano)
		for(auto y:v[x])
			dfs2(y);
	vector<int>ans3=topsort();
	if(ans3.size() && ans3[0]==-1)return NO();

	int len= (int)ans2.size() + k + (int)ans3.size();
	// if(len!=n)return NO();

	cout<<"ans2: ";
	for(auto i:ans2)
		cout<<i<<" ";
	cout<<endl;
	cout<<" ano: ";
	for(auto i:ano)
		cout<<i<<" ";
	cout<<endl;
	cout<<"ans3: ";
	for(auto i:ans3)
		cout<<i<<" ";
	cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
1 4

4 3
1 2
2 3
3 4
2
1 4
*/