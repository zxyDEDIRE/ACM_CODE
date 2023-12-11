/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<double,double>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct node{
	int x,y;
	double w;
}a[maxn];
pii b[maxn];
int p[maxn];
int n,cnt;
double f(int x,int y)
{
	return sqrt((b[x].first-b[y].first)*(b[x].first-b[y].first)+(b[x].second-b[y].second)*(b[x].second-b[y].second));
}
void add(int x,int y,double w)
{
	cnt++;
	a[cnt].x=x;	
	a[cnt].y=y;
	a[cnt].w=w;
}
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			p[i]=i;
		cnt=0;
		for(int i=1;i<=n;i++)
			cin>>b[i].first>>b[i].second;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				add(i,j,f(i,j));
				add(j,i,f(i,j));
			}
			sort(a+1,a+1+cnt,[&](node a,node b){
				return a.w<b.w;
			});
			double ans=0;
			for(int i=1;i<=cnt;i++)
			{
				int fa=find(a[i].x);
				int fb=find(a[i].y);
				if(fa!=fb)
				{
					p[fa]=fb;
					ans+=a[i].w;
				}
			}
			printf("%.2lf\n",ans);
		}

	}
	signed main()
	{	
		ios::sync_with_stdio(false);
		cin.tie(nullptr);cout.tie(nullptr);
		solve();
		return 0;
	}