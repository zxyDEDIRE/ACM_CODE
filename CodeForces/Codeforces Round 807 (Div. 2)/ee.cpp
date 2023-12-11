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
const int maxn=1e6;
struct Seg{
	int l,r,val,lazy;
}t[maxn<<2];
int p[maxn];
int a[maxn];
int n,q;
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
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
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].val=0;
	if(l==r)
	{
		t[rt].val=p[l]%2;
		p[l+1]+=p[l]/2;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int c)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].val+=c*(t[rt].r-t[rt].l+1);
		t[rt].lazy+=c;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	pushdown(rt);
	if(l<=mid)update(rt<<1,l,r,c);
	if(r>mid)update(rt<<1|1,l,r,c);
	pushup(rt);
}
int Q(int rt,int l,int r,int c)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		int x=t[rt].val;
		if(c==1)return x;
		else return (t[rt].r-t[rt].l+1-x);
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	pushdown(rt);
	int ans=0;
	if(l<=mid)ans+=Q(rt<<1,l,r,c);
	if(r>mid)ans+=Q(rt<<1|1,l,r,c);
	return ans;
}
int query(int rt,int a,int c)
{
	if(t[rt].l==t[rt].r)
	{
		return t[rt].l;
	}
	pushdown(rt);
	int x,y;
	if(c==1)
	{
		x=t[rt<<1].val;
	}
	else
	{
		
		x=(t[rt<<1].r-t[rt<<1].l+1)-t[rt<<1].val;//cout<<x<<endl;
	}

	if(x>=a)
	{
		return query(rt<<1,a,c);
	}
	else
	{
		return query(rt<<1|1,a-x,c);
	}
	pushup(rt);
}
int f(int x,int c)
{
	int a=Q(1,1,x-1,c);
	int t=query(1,a+1,c);
	//cout<<x<<" "<<a<<" "<<c<<endl;
	return t;
}
int res(int rt,int a)
{
	//cout<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].val<<" "<<a<<endl;
	if(t[rt].l==t[rt].r)
		return t[rt].l;
	pushdown(rt);
	if(t[rt<<1].val>=a)
	{
		return res(rt<<1,a);
	}
	else
	{
		return res(rt<<1|1,a-t[rt<<1].val);
	}
}
void dfs(int rt,int l,int r)
{
	cout<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].val<<endl;
	if(t[rt].l==t[rt].r)return;
	int mid=(t[rt].l+t[rt].r)>>1;
	pushdown(rt);
	if(l<=mid)dfs(rt<<1,l,r);
	if(r>mid)dfs(rt<<1|1,l,r);
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p[a[i]]++;
	}
	build(1,1,2e5+50);
	cout<<endl;
	while(q--)
	{
		int fl,x,y,ans;
		cin>>fl>>y;
		x=a[fl];

		ans=f(x,1);
		//cout<<"ans ";
		//cout<<ans<<endl;
		if(ans==x)
		{
			update(1,x,x,-1);//cout<<x<<" "<<x<<"change 0"<<endl;
		}
		else
		{
			update(1,x,ans-1,1);//cout<<x<<" "<<ans-1<<"change 1"<<endl;
			update(1,ans,ans,-1);//cout<<ans<<" "<<ans<<"change 0"<<endl;
		}


		// cout<<"DFS"<<endl;
		// dfs(1,1,10);
		// cout<<"dfs"<<endl;
		//cout<<"sdfdfsdfsdfsfsdfsd"<<endl;
		ans=f(y,0);
		//cout<<"ans ";
		//cout<<ans<<endl;
		if(ans==y)
		{
			update(1,y,y,1);//cout<<y<<" "<<y<<"change 1"<<endl;
		}
		else
		{
			update(1,y,ans-1,-1);//cout<<y<<" "<<ans-1<<"change 0"<<endl;
			update(1,ans,ans,1);//cout<<ans<<" "<<ans<<"change 1"<<endl;
		}
		a[fl]=y;
		cout<<res(1,t[1].val)<<endl;
		//cout<<endl;
	}
	//dfs(1,1,10);
	//cout<<res(1,t[1].val)<<endl;
}
int main()
{	
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
5 4
000001000

01110

5 1
2 2 2 4 5
011110
001110
000001



2 2 2 4 5
2 3
011110
001110
000001
2 3 2 4 5


2 3 2 4 5
5 3
000001
000010


4 1
1011000

1 4
0012000
0010100
*/