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
#include<queue>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct node{
	int x,y,w;
}a[maxn];
bool cmp(node a,node b){
	return a.w<b.w;
}
int p[maxn];
int n;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		p[i]=i;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			cnt++;
			a[cnt].x=i;
			a[cnt].y=j;
			a[cnt].w=w;
		}
	}
	sort(a+1,a+1+cnt,cmp);
	int ans=0;
	for(int i=1;i<=cnt;i++)
	{
		int fa=find(a[i].x);
		int fb=find(a[i].y);
		if(fa!=fb){
			p[fa]=fb;
			ans=max(ans,a[i].w);
		}
	}
	cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}