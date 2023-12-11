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
struct node{
	int x,y,id;
}p[maxn];
bitset<maxn>vis;
vector<int>v;
int n,x,y,z;
void solve()
{
	cin>>n>>x>>y>>z;
	for(int i=1;i<=n;i++)
		cin>>p[i].x,p[i].id=i;
	for(int i=1;i<=n;i++)
		cin>>p[i].y;
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.x==b.x)return a.id<b.id;
		return a.x>b.x;
	});
	for(int i=1;i<=n;i++)
	{
		if(x==0)break;
		if(vis[p[i].id])continue;
		x--;
		vis[p[i].id]=1;
	}
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.y==b.y)return a.id<b.id;
		return a.y>b.y;
	});
	for(int i=1;i<=n;i++)
	{
		if(y==0)break;
		if(vis[p[i].id])continue;
		y--;
		vis[p[i].id]=1;
	}
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.x+a.y==b.x+b.y)return a.id<b.id;
		return a.x+a.y>b.x+b.y;
	});
	for(int i=1;i<=n;i++)
	{
		if(z==0)break;
		if(vis[p[i].id])continue;
		vis[p[i].id]=1;
		z--;
	}
	for(int i=1;i<=n;i++)
		if(vis[i])
			cout<<i<<endl;
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