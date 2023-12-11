/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn];
vector<int>V[maxn];
struct node{
	int x,y;
}p[maxn];
int a[maxn],b[maxn],c[maxn];
bitset<maxn>vis;
int n,ans;
void init()
{
	for(int i=0;i<=2*n;i++)
	{
		v[i].clear();
		V[i].clear();
		c[i]=0;
		b[i]=0;
		p[i].x=p[i].y=0;
	}
	vis.reset();
}
void dfs(int x)
{
	if(vis[x])return ;	
	vis[x]=1;
	//cout<<x<<endl;
	int y=V[x][0];
	if(vis[y])return ;
	vis[y]=1;
	//cout<<y<<endl;
	ans++;
	dfs(v[y][0]);
}
bool solve()
{
	cin>>n;
	init();
	int flag=0;
	for(int i=0;i<n;i++)
	{
		cin>>p[i].x>>p[i].y;
		if(p[i].x==p[i].y){
			flag=1;
		}
		V[2*i+1].push_back(2*i+2);
		V[2*i+2].push_back(2*i+1);
		c[p[i].x]++;
		c[p[i].y]++;
		if(c[p[i].x]>2||c[p[i].y]>2){
			flag=1;
		}
		if(!vis[p[i].x])
		{
			vis[p[i].x]=1;
			b[p[i].x]=2*i+1;
		}
		else
		{
			v[2*i+1].push_back(b[p[i].x]);
			v[b[p[i].x]].push_back(2*i+1);
		}
		if(!vis[p[i].y])
		{
			vis[p[i].y]=1;
			b[p[i].y]=2*i+2;
		}
		else
		{
			v[2*i+2].push_back(b[p[i].y]);
			v[b[p[i].y]].push_back(2*i+2);
		}
	}
	if(flag)return 0;
	vis.reset();
	for(int i=1;i<=n*2;i++)
	{
		if(vis[i])continue;
		ans=0;
		dfs(i);
		if(ans%2==1)return 0;
	}
	return 1;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--){
       	if(solve())cout<<"Yes\n";
       	else cout<<"No\n";
    }
    return 0;
}
/*


1 2  1 2
4 5
1 3  1 3
4 6
2 3  2 3
5 6



*/