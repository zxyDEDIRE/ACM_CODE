/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct node{
	int x,y;
	double w;
}edge[maxn];
vector<double>ans;
pii a[maxn];
int p[maxn];
int n,m,tot;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
double dis(int x,int y)
{
	return 1.0*hypot(a[x].first-a[y].first,a[x].second-a[y].second);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
void solve()
{
	cin>>m>>n;tot=0;
	ans.clear();
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
		scanf("%d%d",&a[i].first,&a[i].second);
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			double w=dis(i,j);
			edge[++tot].x=i;
			edge[tot].y=j;
			edge[tot].w=w;
			// edge[++tot]={i,j,dis(i,j)};
		}
	sort(edge+1,edge+1+tot,cmp);
	for(int i=1;i<=tot;i++)
	{
		edge[i];
		int fa=find(edge[i].x);
		int fb=find(edge[i].y);
		if(fa!=fb)
		{
			p[fa]=fb;
			ans.push_back(edge[i].w);
		}
	}
	double ma=0;
	for(int i=0;i<ans.size()-m+1;i++)
		ma=max(ma,ans[i]);
	printf("%.2lf\n",ma);
}
signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}