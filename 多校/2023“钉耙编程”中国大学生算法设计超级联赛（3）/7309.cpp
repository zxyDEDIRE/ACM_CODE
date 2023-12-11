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
using pii=pair<ll,ll>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=5e4+100;
struct node{
	int l,r;
	vector<pii>val;
}t[maxn<<2];
vector<pii>ans;
int n,m;
inline vector<pii> add(vector<pii>a,const ll &x,const ll &y)
{
	for(auto &[_x,_y]:a)
		_x+=x,_y+=y;
	return a;
}
inline void next_un(vector<pii>&nxt,pii&now,const pii&o){
	if(o.first>now.second+1){
		if(now.second>=0)nxt.push_back(now);
		now=o;
	}else{
		now.second=max(now.second,o.second);
	}
}
inline vector<pii> un(const vector<pii>&a,const vector<pii>&b)
{
	vector<pii> nxt;
	int j=0,k=0;
	pii now(0ll,-2ll);
	while(j<a.size()&&k<b.size())next_un(nxt,now,a[j].first<b[k].first?a[j++]:b[k++]);
	while(j<a.size())next_un(nxt,now,a[j++]);
	while(k<b.size())next_un(nxt,now,b[k++]);
	nxt.push_back(now);
	return nxt;
}
inline vector<pii> merge(const vector<pii>&a, const vector<pii>&b)
{
	if(!a.size())return b;
	vector<pii>now = a;
	for(auto &[x,y]:b)
		now=un(now,add(a,x,y));
	return now;
}
inline void build(int rt,int l,int r)
{
	t[rt].l=l;t[rt].r=r;
	if(l==r){
		t[rt].val.resize(2);
		t[rt].val[0]={0ll,0ll};
		cin>>t[rt].val[1].first>>t[rt].val[1].second;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	t[rt].val=merge(t[rt<<1].val,t[rt<<1|1].val);
}
inline void update(int rt,int l)
{
	if(t[rt].l==t[rt].r){
		t[rt].val.resize(2);
		t[rt].val[0]={0ll,0ll};
		cin>>t[rt].val[1].first>>t[rt].val[1].second;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l);
	else update(rt<<1|1,l);
	t[rt].val=merge(t[rt<<1].val,t[rt<<1|1].val);
}
inline void query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		ans=merge(ans,t[rt].val);
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)query(rt<<1,l,r);
	if(r>mid)query(rt<<1|1,l,r);
}
inline void solve()
{
	cin>>n>>m;
	build(1,1,n);
	while(m--)
	{
		int op,l,r;
		cin>>op;
		if(op==1)
		{
			cin>>l;
			update(1,l);
		}
		else
		{
			cin>>l>>r;
			ans.clear();
			query(1,l,r);
			ll res=0;
			for(auto &[x,y]:ans)
				res+=y-x+1;
			cout<<res<<endl;
		}
	}
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