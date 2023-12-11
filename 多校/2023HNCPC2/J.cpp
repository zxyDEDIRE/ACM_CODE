/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=3e5+100;
struct node_1{
	int l,r,val,id;
}ma[maxn<<2];
struct node_2{
	int l,r,val;
}t[maxn<<2];
set<int>s[maxn];
int p[maxn];
int n;
void pushup(int rt)
{
	if(ma[rt<<1].val>=ma[rt<<1|1].val)
	{
		ma[rt].val=ma[rt<<1].val;
		ma[rt].id=ma[rt<<1].id;
	}
	else
	{
		ma[rt].val=ma[rt<<1|1].val;
		ma[rt].id=ma[rt<<1|1].id;
	}
}
void update1(int rt,int l)
{
	if(ma[rt].l==ma[rt].r)
	{
		if(s[l].size()>=2)
			ma[rt].val=(*s[l].rbegin())-(*s[l].begin());
		else ma[rt].val=0;
		return ;
	}
	int mid=(ma[rt].l+ma[rt].r)>>1;
	if(l<=mid)update1(rt<<1,l);
	else update1(rt<<1|1,l);
	pushup(rt);
}
void build1(int rt,int l,int r)
{
	ma[rt]={l,r,0,0};
	if(l==r){
		ma[rt].id=l;
		if(s[l].size()>=2)
			ma[rt].val=(*s[l].rbegin())-(*s[l].begin());
		return ;
	}
	int mid=(l+r)>>1;
	build1(rt<<1,l,mid);
	build1(rt<<1|1,mid+1,r);
	pushup(rt);
}
void build2(int rt,int l,int r)
{
	t[rt]={l,r,0};
	if(l==r){
		t[rt].val=1;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	build2(rt<<1,l,mid);
	build2(rt<<1|1,mid+1,r);
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
void update(int rt,int l)
{
	if(t[rt].l==t[rt].r){
		t[rt].val=0;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l);
	else update(rt<<1|1,l);
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		s[i].clear();
	for(int i=1;i<=n;i++){
		cin>>p[i];
		s[p[i]].insert(i);
	}
	build1(1,1,n);
	build2(1,1,n);
	ll ans=0;
	while(ma[1].val!=0)
	{
		int id=ma[1].id;
		int l=*s[id].begin();
		int r=*s[id].rbegin();
		s[id].erase(l);
		s[id].erase(r);
		update1(1,id);
		ans+=1ll*query(1,l,r)-1;
		update(1,l);
		update(1,r);
	}
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
/*
0 0 1 1 2 0 0

*/