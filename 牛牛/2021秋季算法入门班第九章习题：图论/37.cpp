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
const int maxn=1e6;
struct PII{
	int x,y;
}a[maxn];
struct node{
	int x,y;
	double dis;
}p[maxn];
int f[maxn];
int b[maxn];
int n,m,cnt;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
double dis(int x,int y)
{
	return (double)(1.0*sqrt((a[x].x-a[y].x)*(a[x].x-a[y].x)+(a[x].y-a[y].y)*(a[x].y-a[y].y)));
}
void solve()
{
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>b[i];
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		a[i]={x,y};
		for(int j=1;j<i;j++)
			p[++cnt]={j,i,dis(i,j)};
	}
	sort(p+1,p+1+cnt,[&](node a,node b){
		return a.dis<b.dis;
	});
	for(int i=1;i<=n;i++)
		f[i]=i;
	double ma=0;
	for(int i=1;i<=cnt;i++)
	{
		auto [x,y,w]=p[i];
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
		{
			f[fa]=fb;
			ma=max(ma,w);
		}
	}
	int num=0;
	for(int i=1;i<=m;i++)
		if(b[i]>=ma)num++;
	cout<<num<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}