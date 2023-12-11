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
int low[maxn],dfn[maxn],col[maxn],tot,indx;
bitset<maxn>vis;
stack<int>s;
int n,m;
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
			col[y]=tot;
			vis[y]=0;
		}while(x!=y);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,c;
		string ch;
		cin>>x>>y>>ch>>c;
		x++;
		y++;
		if(ch=="=")
		{
			if(c==0)
			{
				v[x+n].push_back(x);
				v[y+n].push_back(y);
				v[x].push_back(y);
				v[y].push_back(x);
			}
			else if(c==1)
			{
				v[x].push_back(y+n);
				v[y].push_back(x+n);
			}
			else if(c==2)
			{
				v[x].push_back(x+n);
				v[y].push_back(y+n);
				v[x+n].push_back(y+n);
				v[y+n].push_back(x+n);
			}
		}
		else if(ch=="!=")
		{
			if(c==0)
			{
				v[x].push_back(y+n);
				v[y].push_back(x+n);
			}
			else if(c==1)
			{
				v[x].push_back(y);
				v[y].push_back(x);
				v[x+n].push_back(y+n);
				v[y+n].push_back(x+n);
			}
			else if(c==2)
			{
				v[x+n].push_back(y);
				v[y+n].push_back(x);
			}
		}
		else if(ch=="<")
		{
			if(c==0)
			{
				cout<<"No"<<endl;
				return ;
			}
			else if(c==1)
			{
				v[x+n].push_back(x);
				v[y+n].push_back(y);
				v[x].push_back(y);
				v[y].push_back(x);
			}
			else if(c==2)
			{
				v[x+n].push_back(y);
				v[y+n].push_back(x);
			}
		}
		else if(ch==">")
		{
			if(c==0)
			{
				v[x].push_back(y+n);
				v[y].push_back(x+n);
			}
			else if(c==1)
			{
				v[x+n].push_back(y+n);
				v[y+n].push_back(x+n);
				v[x].push_back(x+n);
				v[y].push_back(y+n);
			}
			else if(c==2)
			{
				cout<<"No"<<endl;
				return ;
			}
		}
		else if(ch=="<=")
		{
			if(c==0)
			{
				v[x].push_back(y);
				v[y].push_back(x);
			}
			else if(c==1)
			{
				v[x+n].push_back(y);
				v[y+n].push_back(x);
			}
			else if(c==2)
			{
			}
		}
		else if(ch==">=")
		{
			if(c==0)
			{
			}
			else if(c==1)
			{
				v[x].push_back(y+n);
				v[y].push_back(x+n);
			}
			else if(c==2)
			{
				v[x+n].push_back(y+n);
				v[y+n].push_back(x+n);
			}
		}
	}
	for(int i=1;i<=n*2;i++)
		if(!dfn[i])
			tarjan(i);
	//判断无解情况
	for(int i=1;i<=n;i++)
		if(col[i]==col[i+n]){
			cout<<"No"<<endl;
			return ;
		}
	cout<<"Yes"<<endl;
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
4 3 
0 1 < 1
1 3 = 1
2 3 = 1
*/