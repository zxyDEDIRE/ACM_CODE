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
struct Seg{
	int l,r,_l,_r,val;
	unordered_set<int>s;
}t[maxn<<2];
int n,q;
inline void pushdown(int rt)
{
	if(t[rt].val==1)
	{
		t[rt<<1]._l=t[rt<<1]._r=t[rt<<1|1]._l=t[rt<<1|1]._r=t[rt]._l;
		t[rt<<1].val=t[rt<<1|1].val=1;
		t[rt<<1].s=t[rt].s;
		t[rt<<1|1].s=t[rt].s;
	}
}
inline void pushup(int rt)
{
	if(t[rt<<1]._r==t[rt<<1|1]._l)
	{
		t[rt].val=t[rt<<1].val+t[rt<<1|1].val-1;
	}
	else
	{
		t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
	}
	t[rt].s.clear();
	t[rt].s.insert(t[rt<<1].s.begin(),t[rt<<1].s.end());
	t[rt].s.insert(t[rt<<1|1].s.begin(),t[rt<<1|1].s.end());
	t[rt]._l=t[rt<<1]._l;
	t[rt]._r=t[rt<<1|1]._r;
}
inline void build(int rt,int l,int r)
{
	t[rt]={l,r,1,1,1,{1}};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
inline void update(int rt,int l,int r,int x)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].val=1;
		t[rt]._l=t[rt]._r=x;
		t[rt].s={x};
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,x);
	if(r>mid)update(rt<<1|1,l,r,x);
	pushup(rt);
}
void dfs(int rt)
{
	if(t[rt].l==t[rt].r){
		cout<<t[rt]._l<<" ";
		return ;
	}
	pushdown(rt);
	dfs(rt<<1);
	dfs(rt<<1|1);
}
void solve()
{
	cin>>n>>q;
	build(1,1,n);
	while(q--)
	{
		int l,r,x;
		cin>>l>>r>>x;
		update(1,l,r,x);
		// cout<<t[1].val<<endl;
		cout<<t[1].s.size()<<endl;
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
 // fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
12345
22221
23331

5 1
1 4 2
2 4 3
1 5 2
2 3 1
3 4 2

*/