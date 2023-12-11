/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int l,r,val,lazy;
}t[maxn<<2];
array<int,4>p[maxn];
vector<pii>v[maxn];
int pre[maxn];
int ans[maxn];
int n,m,q;
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		int m=(t[rt].l+t[rt].r)>>1;
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;

		t[rt<<1].val+=(m-t[rt].l+1)*t[rt].lazy;
		t[rt<<1|1].val+=(t[rt].r-m)*t[rt].lazy;

		t[rt].lazy=0;
	}
}
void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].lazy+=k;
		t[rt].val+=(t[rt].r-t[rt].l+1)*k;
		return ;
	}
	pushdown(rt);
	int m=(t[rt].l+t[rt].r)>>1;
	if(l<=m)	update(rt<<1,l,r,k);
	if(r>m)	update(rt<<1|1,l,r,k);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	pushdown(rt);
	int m=(t[rt].l+t[rt].r)>>1;
	int ans1=0,ans2=0;

	if(l<=m)ans1=query(rt<<1,l,r);
	if(r>m)ans2=query(rt<<1|1,l,r);

	return ans1+ans2;
}
void solve()
{
	cin>>n>>m>>q;
	build(1,1,m+1);
	for(int i=1;i<=q;i++)
	{
		int op,x,y,z;
		cin>>op>>x>>y;
		if(op==1)
			cin>>z;
		else if(op==2)
			pre[x]=i;
		else if(op==3)
			v[pre[x]].push_back({i,y});
		p[i]={op,x,y,z};
	}
	for(int i=1;i<=q;i++)
	{
		auto [op,x,y,z]=p[i];
		if(op==1)
		{
			update(1,x,y,z);
		}
		else if(op==2)
		{
			for(auto &[_i,_y]:v[x])
			{
				ans[_i]=query(1,_y,_y)-y;
				_i=0;
			}
		}
		else if(op==3)
		{
			cout<<query(1,y,y)-ans[i]<<endl;
		}
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