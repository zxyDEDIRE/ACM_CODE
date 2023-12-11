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
const int maxn=1e6+100;
struct node{
	int l,r,val,lazy;
}t[maxn];
int p[maxn];
int n,q;
void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		t[rt<<1].val+=t[rt].lazy*(t[rt<<1].r-t[rt<<1].l+1);
		t[rt<<1|1].val+=t[rt].lazy*(t[rt<<1|1].r-t[rt<<1|1].l+1);
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;
		t[rt].lazy=0;
	}
}
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].val+=k*(t[rt].r-t[rt].l+1);
		t[rt].lazy+=k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
int query(int rt,int l)
{
	if(t[rt].l==t[rt].r){
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)return query(rt<<1,l);
	else return query(rt<<1|1,l);
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	build(1,1,n);
	while(q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int l,r;
			cin>>l>>r;
			update(1,l,r,1);
		}
		else
		{
			int id;
			cin>>id;
			int now=query(1,id);
			update(1,id,id,-now);
			int x=p[id];
			while(now)
			{
				if(x<=9)break;
				int y=0;
				while(x){
					y+=x%10;
					x/=10;
				}
				now--;
				x=y;
			}
			p[id]=x;
			cout<<x<<endl;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}