/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
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
	int l,r,val,ok,num;
}t[maxn<<2];
int n,q;
void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0,0};
	if(l==r){
		cin>>t[rt].val;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushdown(int rt)
{
	if(t[rt].ok)
	{
		t[rt<<1].val=t[rt<<1|1].val=t[rt].num;
		t[rt<<1].ok=t[rt<<1|1].ok=1;
		t[rt<<1].num=t[rt<<1|1].num=t[rt].num;
		t[rt].ok=0;
	}
}
void update(int rt,int l,int k)
{
	if(t[rt].l==t[rt].r)
	{
		t[rt].val+=k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,k);
	else update(rt<<1|1,l,k);
}
int query(int rt,int l)
{
	if(t[rt].l==t[rt].r)
		return t[rt].val;
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)return query(rt<<1,l);
	else return query(rt<<1|1,l);
}
void solve()
{
	cin>>n;
	build(1,1,n);
	cin>>q;
	while(q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			t[1].ok=1;
			cin>>t[1].num;
		}
		else if(op==2)
		{
			int x,y;
			cin>>x>>y;
			update(1,x,y);
		}
		else if(op==3)
		{
			int x;
			cin>>x;
			cout<<query(1,x)<<endl;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}