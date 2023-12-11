/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
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
int f[maxn];
int n,m,k;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void solve()
{
	cin>>k>>m>>n;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		p[i]={x,y,w};
	}
	sort(p+1,p+1+m,[&](node a,node b){
		return a.w<b.w;
	});
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		auto [x,y,w]=p[i];
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb){
			f[fa]=fb;
			ans+=w;
		}
	}
	if(ans>k)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}