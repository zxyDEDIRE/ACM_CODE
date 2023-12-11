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
	int x,y;
}p[maxn];
int t[maxn];
int n,k;
double f(int x,int y)
{
	return sqrt(1.0*(p[x].x-p[y].x)*(p[x].x-p[y].x)+1.0*(p[x].y-p[y].y)*(p[x].y-p[y].y));
}
void solve()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&t[i]);

	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);


	double ma=0;
	for(int i=1;i<=n;i++)
	{
		double mi=1e9;
		for(int j=1;j<=k;j++)
			mi=min(1.0*mi,1.0*f(i,t[j]));
		ma=max(ma,mi);
	}

	printf("%.6lf\n",ma);
}
signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}