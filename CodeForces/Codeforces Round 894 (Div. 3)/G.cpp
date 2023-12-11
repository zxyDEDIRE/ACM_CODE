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
struct Seg{
	int l,r,v1,v2,v3,sum;
}t[maxn<<2];
vector<int>v;
int p[maxn];
pii q[maxn];
int n,m,len;
void pushup(int rt)
{
	if(t[rt<<1].v1&&t[rt<<1|1].v2)
	{
		t[rt].v1=t[rt<<1].v1;
		t[rt].v2=t[rt<<1|1].v2;
		t[rt].v3=max({t[rt<<1].v3,t[rt<<1|1].v3,t[rt<<1|1].v1-t[rt<<1].v2});
	}
	else if(t[rt<<1].v1&&!t[rt<<1|1].v1)
	{
		t[rt].v1=t[rt<<1].v1;
		t[rt].v2=t[rt<<1].v2;
		t[rt].v3=t[rt<<1].v3;
	}
	else if(!t[rt<<1].v1&&t[rt<<1|1].v1)
	{
		t[rt].v1=t[rt<<1|1].v1;
		t[rt].v2=t[rt<<1|1].v2;
		t[rt].v3=t[rt<<1|1].v3;
	}
	else
	{
		t[rt].v1=0;
		t[rt].v2=0;
		t[rt].v3=0;
	}
}
void build(int rt,int l,int r){
	t[rt]={l,r,0,0,0,0};
	if(l==r){
		// t[rt].v1=v[l-1];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	// pushup(rt);
}
void update(int rt,int l,int op)
{
	if(t[rt].l==t[rt].r){
		if(op==0)t[rt].sum--;
		else t[rt].sum++;
		if(t[rt].sum==0)
		{
			t[rt].v1=0;
			t[rt].v2=0;
			t[rt].v3=0;
		}
		if(t[rt].sum)
		{
			t[rt].v1=t[rt].v2=max(t[rt].v1,op);
			t[rt].v3=0;
		}
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,op);
	else update(rt<<1|1,l,op);
	pushup(rt);
}
void erase(int num)
{
	int fl=lower_bound(v.begin(),v.end(),num)-v.begin();
	update(1,fl+1,0);
}
void insert(int num)
{
	int fl=lower_bound(v.begin(),v.end(),num)-v.begin();
	update(1,fl+1,num);
}
void dfs(int rt)
{
	cout<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].v1<<" "<<t[rt].v2<<" "<<t[rt].v3<<" "<<t[rt].sum<<endl;
	if(t[rt].l==t[rt].r){return ;	}
	dfs(rt<<1);
	dfs(rt<<1|1);
}
void solve()
{
	cin>>n;
	v.resize(n);
	for(int i=1;i<=n;i++)
		cin>>p[i],v[i-1]=p[i];
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>q[i].first>>q[i].second,v.push_back(q[i].second);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int len=v.size();
	// cout<<"Len "<<len<<endl;
	build(1,1,len);
	for(int i=1;i<=n;i++)
		insert(p[i]);
	for(int i=1;i<=m;i++)
	{
		auto [op,w]=q[i];
		erase(p[op]);
		insert(w);
		p[op]=w;
		cout<<t[1].v2+ t[1].v3<<" ";
		// cout<<t[1].v2<<" "<<t[1].v3<<endl;
	}
	// dfs(1);
	cout<<endl;
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