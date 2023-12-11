/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<iostream>
#include<algorithm>
using namespace std;
#define endl "\n"
const int maxn=1e6;
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
	while(cin>>n&&n)
	{
		int sum=0;
		cnt=0;
		for(int i=1;i<=n;i++)
			p[i]=i;
		for(int i=1;i<n;i++)
		{
			char x,y;
			int k,w;
			cin>>x>>k;
			for(int j=1;j<=k;j++)
			{
				cin>>y>>w;
				sum+=w;
				cnt++;
				a[cnt].x=x-'A'+1;
				a[cnt].y=y-'A'+1;
				a[cnt].w=w;
			}
		}
		sort(a+1,a+1+cnt,cmp);
		sum=0;
		int tot=n;
		for(int i=1;i<=cnt;i++)
		{
			int fa=find(a[i].x);
			int fb=find(a[i].y);
			if(fa!=fb)
			{
				p[fa]=fb;
				sum+=a[i].w;
				tot--;
			}
			if(tot==1)break;
		}
		cout<<sum<<endl;
	}
	
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
//abcdefghi