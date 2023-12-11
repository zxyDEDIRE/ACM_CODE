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
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct node{
	int x,y,w;
}a[maxn];
int p[100];
int n,cnt;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void add(char x,char y,int w)
{
	cnt++;
	a[cnt].x=x-'A'+1;
	a[cnt].y=y-'A'+1;
	a[cnt].w=w;
}
void solve()
{
	cnt=0;
	for(int i=1;i<=30;i++)
		p[i]=i;
	for(int i=1;i<n;i++)
	{
		char x;
		int m;
		cin>>x>>m;
		for(int j=1;j<=m;j++)
		{
			char y;
			int w;
			cin>>y>>w;
			add(x,y,w);
			add(y,x,w);
		}
	}
	sort(a+1,a+1+cnt,[&](node a,node b){
		return a.w<b.w;
	});
	int ans=0;
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
	cout<<ans<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>n&&n)
		solve();
	return 0;
}