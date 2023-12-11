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
int p[maxn];
int n,k,q;
multiset<int>a,b;
ll sum=0;
void rm(int x)
{
	if(x==0)return ;
	if(x<=*b.rbegin())b.erase(b.find(x));
	else a.erase(a.find(x)),sum-=x;
}
void in(int x)
{
	b.insert(x);
	while((int)a.size()<k&&b.size())
	{
		auto now=*b.rbegin();
		sum+=now;
		a.insert(now);
		b.erase(now);
	}
	while(a.size() && b.size() && (*a.begin())<(*b.rbegin()))
	{
		auto x=*a.begin();
		auto y=*b.rbegin();
		a.erase(a.find(x));
		b.erase(b.find(y));
		b.insert(x);
		a.insert(y);
		sum=sum-x+y;
	}
}
void solve()
{
	cin>>n>>k>>q;
	for(int i=1;i<=q;i++)
	{
		ll x,y;
		cin>>x>>y;
		rm(p[x]);
		in(y);
		p[x]=y;
		cout<<sum<<endl;
	}
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