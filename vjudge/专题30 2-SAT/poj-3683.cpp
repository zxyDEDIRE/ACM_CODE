#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<numeric>
#include<math.h>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1e6;


vector<int>v[maxn];
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
int num[maxn];
stack<int>s;
int n,m;
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
	int x,y;
	node(){}
	node(int _x,int _y):x(_x),y(_y){}
}p[maxn];

int IN(){
	int x,y;char ch;
	cin>>x>>ch>>y;
	return x*60+y;
}
void Fuck(int x){
	int a=x/60,b=x%60;
	if(a==0)cout<<"00:";
	else if(a<=9)cout<<"0"<<a<<":";
	else cout<<a<<":";
	if(b==0)cout<<"00";
	else if(b<=9)cout<<"0"<<b;
	else cout<<b;
}
void Fuck(node x){
	Fuck(x.x);
	cout<<" ";
	Fuck(x.y);
	cout<<"\n";
}



bool ok(node a,node b){
	if(a.x>=b.y)return 0;
	if(a.y<=b.x)return 0;
	return 1;
}
void solve()
{
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++){
		int a,b,w;
		a=IN();b=IN();cin>>w;
		p[m++]=node(a,a+w);
		p[m++]=node(b-w,b);
		if(a+w<b)flag=0;
	}
	if(!flag){cout<<"NO\n";return ;}
	for(int i=0;i<m;i++)
		for(int j=i+1;j<m;j++)
			if(ok(p[i],p[j])){
				v[i].push_back(j^1);
				v[j].push_back(i^1);
			}
	for(int i=0;i<m;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=0;i<m;i++)
		if(col[i]==col[i^1]){
			cout<<"NO\n";
			return ;
		}
	cout<<"YES\n";
	for(int i=0;i<m;i+=2)
		if(col[i]<col[i^1]){
			 Fuck(p[i]);
		}
		else {
			Fuck(p[i^1]);
		}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
        solve();
    return 0;
}