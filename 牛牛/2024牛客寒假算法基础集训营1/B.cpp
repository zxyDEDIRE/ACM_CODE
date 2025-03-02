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
pii p[maxn];
int n;
void solve()
{
	cin>>n;
	set<pii>s;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].first>>p[i].second;
		s.insert(p[i]);
	}
	sort(p+1,p+1+n,[&](pii a,pii b){
		if(a.second!=b.second)
			return a.second<b.second;
		return a.first<b.first;
	});
	auto f=[&](int x)->int{
		if(x==1)return 2;
		return 1;
	};
	int fa=0,fb=0;
	for(int i=1;i<=n;i++)
	{
		auto &[x,y]=p[i];
		if(y>=0)break;
		fa=max(fa,1);
		if(s.count({f(x),y}) || s.count({f(x),y+1}) || s.count({f(x),y-1}))
			fa=2;
	}
	for(int i=n;i>=1;i--)
	{
		auto &[x,y]=p[i];
		if(y<=0)break;
		fb=max(fb,1);
		if(s.count({f(x),y}) || s.count({f(x),y+1}) || s.count({f(x),y-1}))
			fb=2;
	}
	int num=0;
	if(s.count({2,0}))num++,fa=max(fa,1),fb=max(fb,1);
	if(s.count({1,-1}))num++;
	if(s.count({1,1}))num++;
	cout<<min(4-fa-fb,3-num)<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
