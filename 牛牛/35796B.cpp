#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int dfn[maxn],low[maxn],tot;
int stc[maxn],top,cnt;
vector<int>v[maxn];
bool vis[maxn];
int col[maxn];
int num[maxn];
int in[maxn];
int n,m;
void tarjan(int x)
{
	dfn[x]=low[x]=++tot;
	stc[++top]=x;//入栈
	vis[x]=1;//标记入栈

	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(!dfn[y])//还没有被访问
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
			//因为y深度比x大
			// 所以和low比较
		}
		else if(vis[y]){//已经入栈
			//y为回溯父亲节点 所以和dfn比较
			low[x]=min(low[x],dfn[y]);
		}
	}
	//同一个联通集合low相同
	// 找到一个联通集合
	int y;
	if(dfn[x]==low[x])
	{
		//集合数量++
		cnt++;
		do{
			y=stc[top--];
			col[y]=cnt;
			//涂色，标记相同集合
			num[cnt]++;
			vis[y]=0;
		}while(x!=y);//只要自己还没有弹出这个栈，都为同一个集合
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i])
			tarjan(i);
	}
	for(int x=1;x<=n;x++){
		for(int y:v[x]){
			if(col[x]!=col[y]){
				in[col[x]]++;
			}
		}
	}
	for(int i=1;i<=cnt;i++)
		if(!in[i])cout<<num[i]<<endl;

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;
//    cin>>__;
	__=1;
	while(__--)solve();
	return 0;
}