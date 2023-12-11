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
int dfn[maxn],low[maxn];
bitset<maxn>vis;
bitset<maxn>cut;
stack<int>s;
string str;
int n,k,indx;
void init(){
	for(int i=1;i<=n;i++){
		v[i].clear();
		dfn[i]=low[i]=0;
	}
	indx=0;
	vis.reset();
	cut.reset();
}
void tarjan(int x,int fa=0)
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
			if(low[y]>=dfn[x])
			{
				cut[x]=1;
				int v;
				do{
					v=s.top();s.pop();
				}while(v!=y);
			}
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(x==fa&&num==1)cut[x]=0;
}
void solve()
{
	init();
	getchar();
	while(getline(cin,str)&&str!="0")
	{
		vector<int>p;
		int now=0;
		for(auto i:str)
		{
			if(i>='0'&&i<='9')now=now*10+i-'0';
			else
			{
				if(now)p.push_back(now);
				now=0;
			}
		}
		if(now)p.push_back(now);
		for(int i=1;i<p.size();i++)
		{
			v[p[0]].push_back(p[i]);
			v[p[i]].push_back(p[0]);
		}
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i,i);
	cout<<cut.count()<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>n&&n)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*

*/