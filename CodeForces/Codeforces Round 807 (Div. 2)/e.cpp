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
	int l,r,val,ma,mi,same,lazy;
}t[maxn<<2];
int p[maxn];
int s[maxn];
int a[maxn];
int n,q,flag,ans;
void pushup(int rt)
{
	t[rt].ma=max(t[rt<<1].ma,t[rt<<1|1].ma);
	t[rt].mi=max(t[rt<<1].mi,t[rt<<1|1].mi);
	if(t[rt<<1].same&&t[rt<<1|1].same&&t[rt<<1].val==t[rt<<1|1].val)
	{
		t[rt].val=t[rt<<1].val;
		t[rt].same=1;
	}
	else t[rt].same=0;
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		t[rt<<1].same=t[rt<<1|1].same=1;
		t[rt<<1].val=t[rt<<1|1].val=t[rt].val;
		t[rt<<1].lazy=t[rt<<1|1].lazy=1;
		t[rt].lazy=0;

		if(t[rt].val==1)
		{
			t[rt<<1].ma=t[rt<<1].r;
			t[rt<<1|1].ma=t[rt<<1|1].r;
			t[rt<<1].mi=t[rt<<1|1].mi=0;
		}
		else
		{
			t[rt<<1].mi=t[rt<<1].r;
			t[rt<<1|1].mi=t[rt<<1|1].r;
			t[rt<<1].ma=t[rt<<1|1].ma=0;
		}
	}
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].val=t[rt].ma=0;
	if(l==r)
	{
		
		t[rt].same=1;
		t[rt].val=p[l]%2;
		p[l+1]+=p[l]/2;
		s[l]=t[rt].val;
		if(t[rt].val)t[rt].ma=l;
		else t[rt].mi=l;
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
		t[rt].lazy=1;
		t[rt].same=1;
		t[rt].val=c;
		if(t[rt].val==1)
		{
			t[rt].ma=t[rt].r;
			t[rt].mi=0;
		}
		else
		{
			t[rt].mi=t[rt].r;
			t[rt].ma=0;
		}
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
		if(c==1)return t[rt].ma;
		else return t[rt].mi;
	}
	int ans=0;
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)ans=max(ans,Q(rt<<1,l,r,c));
	if(r>mid)ans=max(ans,Q(rt<<1|1,l,r,c));
	return ans;
}
bool check(int ll,int l,int c)
{
	int t=Q(1,ll,l,c);
	if(t>0)return 1;
	else return 0;
}
int qu(int ll,int rr,int c)
{
	int l=ll,r=rr,ans=0;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(ll,mid,c))ans=mid,r=mid;
		else l=mid;
	}
	//return ans;
	if(check(ll,ans-1,c))return ans-1;
	else return ans;
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		a[i]=x;
		p[x]++;
	}
	build(1,1,2e5+50);
	while(q--)
	{
		int c,x,y;
		cin>>c>>y;
		x=a[c];
		

		flag=1;
		ans=qu(x,2e5+50,1);
		//cout<<x<<endl;
		//cout<<"ans : ";
		//cout<<ans<<endl;
		if(ans==x)
		{
			update(1,x,x,0);//cout<<x<<" "<<x<<"change 0"<<endl;
		}
		else
		{
			update(1,x,ans-1,1);//cout<<x<<" "<<ans-1<<"change 1"<<endl;
			update(1,ans,ans,0);//cout<<ans<<" "<<ans<<"change 0"<<endl;
		}
		flag=1;
		ans=qu(y,2e5+50,0);
		//cout<<y<<endl;
		//cout<<"ans : ";
		//cout<<ans<<endl;
		if(ans==y)
		{
			update(1,y,y,1);//cout<<y<<" "<<y<<"change 1"<<endl;
		}
		else
		{
			update(1,y,ans-1,0);//cout<<y<<" "<<ans-1<<"change 0"<<endl;
			update(1,ans,ans,1);//cout<<ans<<" "<<ans<<"change 1"<<endl;
		}
		a[c]=y;
		cout<<t[1].ma<<endl;
	}
	//
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
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