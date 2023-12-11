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
	int l,r,val;
}t[maxn<<2];
map<int,int>mp;
set<int>s;
void pushup(int rt){
	t[rt].val=min(t[rt<<1].val,t[rt<<1|1].val);
};
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	if(l==r){
		if(s.count(l))t[rt].val=INF;
		else t[rt].val=l;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int k){
	if(t[rt].l==t[rt].r){
		t[rt].val=k;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,k);
	else update(rt<<1|1,l,k);
	pushup(rt);
}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=INF;
	if(l<=mid)ans=min(ans,query(rt<<1,l,r));
	if(r>mid)ans=min(ans,query(rt<<1|1,l,r));
	return ans;
}
void dfs(int rt)
{
	cout<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].val<<endl;
	if(t[rt].l==t[rt].r)return ;
	dfs(rt<<1);
	dfs(rt<<1|1);
}
int p[maxn];
int n,q;
void solve()
{
	cin>>n>>q;
	mp.clear();
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		mp[p[i]]++;
		s.insert(p[i]);
	}
	build(1,0,n+10);
	while(q--)
	{
		int i,w;
		cin>>i>>w;
		int now=p[i];

		mp[now]--;
		if(mp[now]==0&&now<=n)update(1,now,now);

		mp[w]++;
		if(mp[w]==1&&w<=n)update(1,w,INF);
		p[i]=w;

		cout<<t[1].val<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
4 4
0 0 0 0
1 1
2 1
3 2
4 1
*/