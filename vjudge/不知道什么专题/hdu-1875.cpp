/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct node{
	int x,y;double w;
}a[maxn];
pii b[maxn];
int p[maxn];
int n;
double f(int x,int y)
{
	return sqrt(1.0*(a[x].x-a[y].x)*(a[x].x-a[y].x)+(a[x].y-a[y].y)*(a[x].y-a[y].y));
}
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<=n;i++)
		cin>>b[i].first>>b[i].second;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			double t=sqrt((b[i].first-b[j].first)*
				(b[i].first-b[j].first)+
				(b[i].second-b[j].second)*
				(b[i].second-b[j].second));
			if(t>=10&&t<=1000)
			{
				a[++cnt]={i,j,t};
			}
		}
	}
	sort(a+1,a+1+cnt,[&](node a,node b){
		return a.w<b.w;
	});
	double ans=0;
	int num=n;
	for(int i=1;i<=cnt;i++)
	{
		int fa=find(a[i].x);
		int fb=find(a[i].y);
		if(fa!=fb)
		{
			p[fa]=fb;
			ans+=a[i].w;
			num--;
		}
	}
	if(num!=1)cout<<"oh!"<<endl;
	else printf("%.1f\n",ans*100);
}
signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}