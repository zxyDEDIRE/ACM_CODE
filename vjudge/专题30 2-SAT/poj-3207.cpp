#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<stack>
using namespace std;
const int maxn=1e6+10;

vector<int>v[maxn];
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
int num[maxn];
int out[maxn];
int in[maxn];
stack<int>s;
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	vis[x]=1;
	s.push(x);
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x])
	{
		++tot;
		int y;
		do{
			y=s.top();s.pop();
			vis[y]=0;
			col[y]=tot;
		}while(x!=y);
	}
}


struct node{
	int x,y,ok;
}p[maxn];
int n,m;
inline bool cross(int x1,int x2,int y1,int y2)
{
    if( x1 == x2 || y1 == y2 || x1 == y2 || x2 == y1 )
        return 0;
    if( x1 < x2 && y1 < y2 && x2 < y1 )
        return 1;
    if( x2 < x1 && y2 < y1 && x1 < y2 )
        return 1;
    return 0;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>p[i].x>>p[i].y;
		p[i].x++;p[i].y++;p[i].ok=0;
		if(p[i].x>p[i].y)swap(p[i].x,p[i].y);
	}
	for(int i=1;i<=m;i++)
		if(p[i].x+1==p[i].y||p[i].x==1&&p[i].y==n)
			p[i].ok=1;
	for(int i=1;i<=m;i++)
	{
		if(p[i].ok)continue;
		for(int j=i+1;j<=m;j++)
		{
			if(p[j].ok)continue;
			if(cross(p[i].x,p[i].y,p[j].x,p[j].y))
			{
				v[i].push_back(j+m);
				v[j].push_back(i+m);
				v[j+m].push_back(i);
				v[i+m].push_back(j);
			}
		}
	}
	for(int i=1;i<=m*2;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=m;i++)
		if(col[i]==col[i+m]){
			cout<<"the evil panda is lying again";
			return ;
		}
	cout<<"panda is telling the truth...";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
