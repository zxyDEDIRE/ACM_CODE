//这回只花了114514min就打完了。
//真好。记得多手造几组。ACM拍什么拍。 
#include "bits/stdc++.h"
using namespace std;
template<typename T1,typename T2> istream &operator>>(istream &cin,pair<T1,T2> &a) { return cin>>a.first>>a.second; }
template<typename T1> istream &operator>>(istream &cin,vector<T1> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename T1> istream &operator>>(istream &cin,valarray<T1> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename T1,typename T2> ostream &operator<<(ostream &cout,const pair<T1,T2> &a) { return cout<<a.first<<' '<<a.second; }
template<typename T1,typename T2> ostream &operator<<(ostream &cout,const vector<pair<T1,T2>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename T1> ostream &operator<<(ostream &cout,const vector<T1> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<typename T1,typename T2> bool cmin(T1 &x,const T2 &y) { if (y<x) { x=y; return 1; } return 0; }
template<typename T1,typename T2> bool cmax(T1 &x,const T2 &y) { if (x<y) { x=y; return 1; } return 0; }
template<typename T1> vector<T1> range(T1 l,T1 r,T1 step=1) { assert(step>0); int n=(r-l+step-1)/step,i; vector<T1> res(n); for (i=0; i<n; i++) res[i]=l+step*i; return res; }
template<typename T1> basic_string<T1> operator*(const basic_string<T1> &s,int m) { auto r=s; m*=s.size(); r.resize(m); for (int i=s.size(); i<m; i++) r[i]=r[i-s.size()]; return r; }
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef double db;
#define all(x) (x).begin(),(x).end()
// template<typename T1,typename T2> void inc(T1 &x,const T2 &y) { if ((x+=y)>=p) x-=p; }
// template<typename T1,typename T2> void dec(T1 &x,const T2 &y) { if ((x+=p-y)>=p) x-=p; }
const int N=1e6+5;
typedef unsigned long long ui;
typedef unsigned long long ull;
typedef unsigned long long ll;
typedef pair<ui,ui> pa;
namespace sh
{
	const int N=1e6+5;
	const ull b1=137,b2=149,i1=1'603'801'661,i2=1'024'053'074;
	const ui p1=2'034'452'107,p2=2'013'074'419;
	ull m1[N+1],m2[N+1],r1,r2;
	int i;
	void init()
	{
		m1[0]=m2[0]=1;
		for (i=1; i<=N; i++)
		{
			m1[i]=m1[i-1]*b1%p1;
			m2[i]=m2[i-1]*b2%p2;
		}
	}
	struct str
	{
		vector<pa> a;
		str(char *s,int n)
		{
			a.resize(n+1);
			r1=r2=0;
			a[0]={0,0};
			for (i=0; i<n; i++)
			{
				r1=(r1+s[i]*m1[i])%p1;
				r2=(r2+s[i]*m2[i])%p2;
				a[i+1]={r1,r2};
			}
		}
		str(const string &s)
		{
			int n=s.size();
			a.resize(n+1);
			r1=r2=0;
			a[0]={0,0};
			for (i=0; i<n; i++)
			{
				r1=(r1+s[i]*m1[i])%p1;
				r2=(r2+s[i]*m2[i])%p2;
				a[i+1]={r1,r2};
			}
		}
		pa getv(int l,int r)//[l,r)
		{
			return {(p1+a[r].first-a[l].first)*m1[N-l]%p1,(p2+a[r].second-a[l].second)*m2[N-l]%p2};
		}
	};
	ull ptou(const pa &a)
	{
		return (ull)a.first<<32|a.second;
	}
}
using sh::init,sh::ptou,sh::p1,sh::p2,sh::str,sh::m1,sh::m2;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(15);
	int n,m,q,i,j;
	string s;
	init();
	cin>>n>>m>>q>>s;
	vector<int> f(n);
	str t(s);
	map<ll,int> id;
	int cc=0;
	vector<int> lst(n+1,-1),tt(n+1);
	for (i=m; i<=n; i++)
	{
		ll x=ptou(t.getv(i-m,i));
		int &y=id[x];
		if (!y) y=++cc;
		if (lst[y]==-1)
		{
			lst[y]=i;
			tt[y]=1;
		}
		else if (lst[y]+m<=i)
		{
			lst[y]=i;
			++tt[y];
		}
	}
	cout<<count(all(tt),q)<<endl;
}
