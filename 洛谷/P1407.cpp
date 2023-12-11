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
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
map<string,int>mp;
bitset<maxn>vis;
stack<int>s;
int mt[maxn];
int n,m,cnt;
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
		string x,y;
		cin>>x>>y;
		mp[x]=++cnt;
		mp[y]=++cnt;
		mt[cnt]=cnt-1;
		mt[cnt-1]=cnt;
		v[cnt-1].push_back(cnt);
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		string x,y;
		cin>>x>>y;
		v[mp[y]].push_back(mp[x]);
	}
	for(int i=1;i<=n*2;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
	{
		int x=i*2-1;
		int y=i*2;
		if(col[x]==col[y])cout<<"Unsafe"<<endl;
		else cout<<"Safe"<<endl;
	}
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
1->2
3->4

3->2
1->4

*/