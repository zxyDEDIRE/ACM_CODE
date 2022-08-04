/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct Seg{
	int l,r,cnt;
	ll val;
}t[maxn<<2];
struct node{
	ll x,op;
	ll val;
	bool operator<(const node&a)const{
		if(a.x==x)return a.op<op;
		else return a.x<x;
	}
};
int op[maxn];
int b[maxn];
int n,m,cnt;
ll tmp,res;
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].val=t[rt].cnt=0;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt)
{
	t[rt].cnt=min(t[rt<<1].cnt,t[rt<<1|1].cnt);
	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
}
void add(int rt,int fl,ll w)
{
	if(t[rt].l==t[rt].r)
	{
		t[rt].cnt++;
		tmp=t[rt].l;
		if(t[rt].val<=fl)
			t[rt].val=fl+w;
		else 
			t[rt].val=t[rt].val+w;
		res=t[rt].val;
		return ;
	}
	int x=t[rt<<1].cnt;
	int y=t[rt<<1|1].cnt;
	if(x<=y)add(rt<<1,fl,w);
	else add(rt<<1|1,fl,w);
	pushup(rt);
}
void sub(int rt,int l)
{
	if(t[rt].l==t[rt].r){
		t[rt].cnt--;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)sub(rt<<1,l);
	else sub(rt<<1|1,l);
	pushup(rt);
}
void solve()
{
	cin>>n>>m;
	priority_queue<node>q;
	for(int i=1;i<=n;i++)
	{
		ll x,y;
		cin>>x>>y;
		q.push({x,1,y});
	}
	build(1,1,m);
	for(int i=1;i<=n*2;i++)
	{
		node t=q.top();q.pop();
		ll x=t.x;
		ll val=t.val;
		ll op=t.op;
		if(op==1)
		{
			add(1,x,val);
			q.push({res,-1,tmp});
		}
		else 
		{
			tmp=t.val;
			sub(1,t.val);
		}

		//cout<<x<<" "<<op<<" "<<val<<" "<<tmp<<endl;
	}
	cout<<t[1].val<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1
5 3
2 4
1 3
5 1
3 4
4 2

1 3
2 4
3 4
4 2
5 1


1 3 1
2 4 2
3 4 3
4 2
5 1

1 1 1 1 1 1 0
0 1 1 1 1 1 0 
0 0 1 1 1 1 1

1 1 1 1 1 1 1
0 1 1 1 1 0 0 
0 0 1 1 1 1 1

0 0 0 0 0 0 0
0 0 0 0 0 0 0 
0 0 0 0 0 0 0


1
3 2
1 3
2 3
3 4

1 3
2 3
3 4

1 1 1 1 
0 1 1 1 1
*/