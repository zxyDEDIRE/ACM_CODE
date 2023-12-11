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
using pii=pair<ll,ll>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
bitset<maxn>vis;
int dt[maxn];
int f[maxn];
pii E[maxn];
int a[maxn];
int n;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
struct Trie{
	int t[maxn][5];
	int nxt[maxn];
	int indx;
	void init()
	{
		for(int i=0;i<=indx;i++)
			t[i][0]=t[i][1]=0;
		indx=0;
	}
	void insert(int x)
	{
		int rt=0;
		int w=a[x];
		for(int i=30;i>=0;i--)
		{
			int now=w&(1<<i);
			if(!t[rt][now&1])
				t[rt][now&1]=++indx;
			rt=t[rt][now&1];
			if(!nxt[rt])nxt[rt]=x;
		}
		nxt[rt]=min(nxt[rt],x);
	}
	int query(int x)
	{
		int rt=0;
		int w=a[x];
		for(int i=30;i>=0;i--)
		{
			int now=w&(1<<i);
			if(t[rt][now^1])
				rt=t[rt][now^1];
			else rt=t[rt][now];
		}
		return nxt[rt];
	}
}trie;
int Boruvka()
{
	for(int i=1;i<=n;i++)
		f[i]=i,v[i].push_back(i);
	int num=0;
	int sum=0;
	while(num!=n-1)
	{
		int tmp=0;
		for(int i=1;i<=n;i++)
			if(!vis[find(i)]){
				dt[++tmp]=find(i);
				vis[find(i)]=1;
			}
		for(int i=1;i<=tmp;i++)
			E[i]={INF,INF};
		trie.init();
		for(int i=1;i<=tmp;i++)
		{
			for(auto y:v[dt[tmp]])
			{
				int x=trie.query(y);
				ll nxt=x*(n+1)+y;
				E[i]=min(E[i],{a[x]^a[y],nxt});
			}
			for(auto y:v[dt[tmp]])
				trie.insert(y);
		}
		trie.init();
		for(int i=tmp;i>=1;i--)
		{
			for(auto y:v[dt[tmp]])
			{
				int x=trie.query(y);
				ll nxt=x*(n+1)+y;
				E[i]=min(E[i],{a[x]^a[y],nxt});
			}
			for(auto y:v[dt[tmp]])
				trie.insert(y);
		}
		for(int i=1;i<=tmp;i++)
		{
			auto [w,c]=E[i];
			ll x=c/(n+1);
			ll y=c%(n+1);
			x=find(x);
			y=find(y);
			if(x==y)continue;
			sum+=w;
			if(v[x].size()<v[y].size())
				swap(x,y);
			f[y]=x;
			for(auto j:v[y])
				v[x].push_back(j);
			v[y].clear();
			num++;
		}
	}
	return sum;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<Boruvka()<<endl;
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