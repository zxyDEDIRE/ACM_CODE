#include<bits/stdc++.h>

#include <typeinfo>
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
int pre[maxn];
int suf[maxn];
ll p[maxn];
int n;
int getA(int l,int r)
{
	return pre[r];
}
int getB(int l,int r)
{
	if(l>r)return 0;
	return suf[l];
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	suf[n]=0;
	pre[1]=0;
	for(int i=2;i<=n;i++)
	{
		pre[i]=pre[i-1];
		if(p[i-1]<=p[i])pre[i]++;
	}
	for(int i=n-1;i>=1;i--)
	{
		suf[i]=suf[i+1];
		if(p[i+1]<=p[i])suf[i]++;
	}
	int ans=INF;
	for(int i=0;i<=n;i++)
	{
		if(i==0)ans=min(ans,getB(1,n));
		else ans=min(ans,1+getA(1,i)+getB(i+1,n));
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	// 	solve();
	deque<int>a,b;
	a.push_back(1);
	b.push_back(1);
	cout<<typeid(a<=>b).name()<<endl;
	auto ans=(a<=>b);
	cout<<ans.less;
// .	cout<<(a<=>b)<<endl;
	// a<=>b;
	// return 0;
}
/*
5 4 3 2 5 1
-5 -4 -3 -2 5 1
-5 -4 -3 -2 5 10

2 4 3 2 
-2 -4 -3 -2
*/