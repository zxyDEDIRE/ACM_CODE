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
const int maxn=1e6+100;
struct node{
	int x,y;
}a[maxn];
int t[maxn];
int p[maxn];
int n,m;
int findp(int r){
	return p[r]=p[r]==r?p[r]:findp(p[r]);
}
int findt(int r){
	return t[r]=t[r]==r?t[r]:findt(t[r]);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y;
		if(a[i].x>a[i].y)
			swap(a[i].x,a[i].y);
	}
	sort(a+1,a+1+m,[&](node a,node b){
		if(a.x!=b.x)return a.x<b.x;
		return a.y<b.y;
	});
	for(int i=1;i<=n;i++)
		p[i]=i,t[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x=a[i].x;
		int y=a[i].y;
		int fa=findt(x);
		int fb=findt(y);
		if(fa!=fb)
		{
			int a=findp(x);
			int b=findp(y);

		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}