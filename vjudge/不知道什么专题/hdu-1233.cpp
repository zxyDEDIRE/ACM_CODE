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
const int maxn=1e6;
struct node{
	int x,y,w;
}a[maxn];
int p[maxn];
int n;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void solve()
{
	while(cin>>n)
	{
		if(n==0)return ;
		for(int i=1;i<=n*(n-1)/2;i++)
			cin>>a[i].x>>a[i].y>>a[i].w;
		sort(a+1,a+1+n*(n-1)/2,[&](node a,node b){
			return a.w<b.w;
		});
		int ans=0;
		for(int i=1;i<=n;i++)
			p[i]=i;
		for(int i=1;i<=n*(n-1)/2;i++)
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
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}