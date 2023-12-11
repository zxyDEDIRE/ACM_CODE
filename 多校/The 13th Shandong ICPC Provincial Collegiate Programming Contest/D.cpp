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
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	ll x,y;
}p[maxn];
int n;
bool check(ll mid)
{
	vector<ll>a,b;
	for(int i=1;i<=n;i++)
		if(p[i].x>=mid)
			a.push_back(p[i].y+p[i].x-mid);
		else b.push_back(p[i].y);
	if(a.size()<b.size())return 0;
	sort(a.begin(),a.end(),[&](auto a,auto b){return a>b;});
	sort(b.begin(),b.end(),[&](auto a,auto b){return a>b;});
	for(int i=0;i<b.size();i++)
		if(a[i]<b[i])return 0;
	return 1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y;
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.x!=b.x)return a.x>b.x;
		return a.y>b.y;
	});
	ll l=p[n].x,r=p[1].x,ans=l;
	while(l<r-1)
	{
		ll mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	if(check(ans+1))ans++;
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}