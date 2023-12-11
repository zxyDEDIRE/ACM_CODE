/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
int n,m,c;
int l=0,r,ans;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
bool check(int mid)
{
	for(int i=1;i<=n;i++)
		f[i]=i;
	int cnt=n;
	int sum=0;
	vector<int>v;
	for(int i=1;i<=m;i++)
	{
		auto [x,y,w]=p[i];
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
		{
			f[fa]=fb;
			if(w>mid)v.push_back(w);
			cnt--;
		}
		if(cnt==1)break;
	}
	cnt=0;
	for(int i=v.size()-1;i>=0;i--)
	{
		cnt++;
		sum+=cnt*v[i];
	}
	return sum<=c;
}
void solve()
{
	cin>>n>>m>>c;
	for(int i=1;i<=m;i++)
		cin>>p[i].x>>p[i].y>>p[i].w,r=max(r,p[i].w);
	sort(p+1,p+1+m,[&](node a,node b){
		return a.w<b.w;
	});


	ans=r;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	while(ans>0&&check(ans-1))ans--;
	cout<<ans<<endl;

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