/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<algorithm>
#include<iostream>
using namespace std;
#define endl "\n"
#define int long long
const int maxn=1e5;
struct node{
	int x,y,w;
}a[maxn];
int p[maxn];
int n,cnt;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
void solve()
{
	while(cin>>n)
	{
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int x;cin>>x;
				if(x)
				{
					cnt++;
					a[cnt].x=i;
					a[cnt].y=j;
					a[cnt].w=x;
					//a[++cnt]={i,j,x};
				}
			}
		}
		sort(a+1,a+1+cnt,cmp);
		int ans=0;
		for(int i=1;i<=n;i++)
			p[i]=i;
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
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
		solve();
	return 0;
}