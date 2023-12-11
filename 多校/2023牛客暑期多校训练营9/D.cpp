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
	int l,r,val,id,dfn;bool ok;
	node():l(0),r(0),val(0),id(0),dfn(0),ok(false){}
}t[maxn];
int p[maxn];
int indx;
int num=0;
int n;
void init(int val)
{
	t[1]=node();
	t[1].val=val;
	t[1].dfn=1;
	t[1].id=1;
	indx=1;
	num=0;
}
void build(int rt,int val)
{
	t[rt]=node();
	t[rt].val=val;
	t[rt].id=indx;
	t[rt].ok=false;
}
void insert(int rt,int val)
{
	if(val>t[rt].val)
	{
		if(t[rt].r)insert(t[rt].r,val);
		else
		{
			t[rt].r=++indx;
			build(indx,val);
		}
	}
	else
	{
		if(t[rt].l)insert(t[rt].l,val);
		else
		{
			t[rt].l=++indx;
			build(indx,val);
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int l=1;l<=n;l++)
	{
		init(p[l]);
		for(int i=l+1;i<=n;i++)
		{
			insert(1,p[i]);
		}
	}
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