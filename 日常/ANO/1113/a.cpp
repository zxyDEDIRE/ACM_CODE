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
	int x,y,w;
}p[maxn];
bitset<maxn>vis;
int f[maxn];
int n;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void solve()
{
	cin>>n;
	int sum=0,ans=0;
	for(int i=1;i<=n;i++)
		cin>>p[i].x,p[i].y=i;
	for(int i=1;i<=n;i++)
		cin>>p[i].w,sum+=p[i].w;
	for(int i=1;i<=n;i++)
		f[i]=i;
	sort(p+1,p+1+n,[&](node a,node b){
		return a.w>b.w;
	});
	for(int i=1;i<=n;i++)
	{
		auto [x,y,w]=p[i];
		if(vis[y])continue;
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
		{
			f[fa]=fb;
			ans+=w;
			vis[y]=1;
		}
	}
	cout<<sum-ans<<endl;
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