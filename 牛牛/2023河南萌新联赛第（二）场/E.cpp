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
struct node{
	int l,r,val,num;
}t[maxn<<2];
int n;
void build(int rt,int l,int r)
{
	t[rt]={l,r,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt)
{
	t[rt].num=t[rt<<1].num+t[rt<<1|1].num;
}
void pushdown(int rt)
{
	if(t[rt].val)
	{
		t[rt<<1].val=t[rt<<1|1].val=1;
		t[rt<<1].num=t[rt<<1].r-t[rt<<1].l+1;
		t[rt<<1|1].num=t[rt<<1|1].r-t[rt<<1|1].l+1;
	}
}
void update(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].val=1;
		t[rt].num=t[rt].r-t[rt].l+1;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r);
	if(r>mid)update(rt<<1|1,l,r);
	pushup(rt);
}
void solve()
{
	cin>>n;
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		if(i!=1)
			update(1,max(1,i-x),i-1);
		if(i!=n)
			update(1,i+1,min(n,i+x));
	}
	cout<<t[1].num<<endl;
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