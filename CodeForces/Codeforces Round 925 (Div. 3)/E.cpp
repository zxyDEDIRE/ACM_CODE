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
	int x,y;
}p[maxn];
int n,m;
node f(int x)
{
	vector<int>v;
	while(x){
		v.push_back(x%10);
		x/=10;
	}
	int len=0;
	for(auto i:v){
		if(i==0)len++;
		else break;
	}
	return {(int)v.size(),len};
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		p[i]=f(x);
	}
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.y!=b.y)return a.y>b.y;
		return a.x>b.x;
	});
	// for(int i=1;i<=n;i++)
	// 	cout<<i<<" "<<p[i].x<<" "<<p[i].y<<endl;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i&1)
		{
			ans+=p[i].x-p[i].y;
		}
		else
		{
			ans+=p[i].x;
		}
	}
	cout<<((ans>=m+1)?"Sasha":"Anna")<<endl;
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
/*
3 2 800
4 1 1580
4 0 2007
1 0 1

1580820071
10000000001
*/