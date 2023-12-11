#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
struct node
{
	int l,r;
	int ans;
}t[N<<2][2];
#define check (l<=t[k][pos].l&&t[k][pos].r<=r)
#define mid (t[k][pos].l+t[k][pos].r>>1)
void build(int pos,int k,int l,int r)
{
	t[k][pos].l=l;
	t[k][pos].r=r;
	if(l==r)return ;
	build(pos,k<<1,l,mid);
	build(pos,k<<1|1,mid+1,r);
}
void modify(int pos,int k,int op,int v)
{
	if(t[k][pos].l==t[k][pos].r)
	{
		t[k][pos].ans+=v;
		return ;
	}
	if(op<=mid)modify(pos,k<<1,op,v);
	else modify(pos,k<<1|1,op,v);
	t[k][pos].ans=t[k<<1][pos].ans+t[k<<1|1][pos].ans;
}
int query(int pos,int k,int l,int r)
{
	if(check)return t[k][pos].ans;
	int ans=0;
	if(l<=mid)ans+=query(pos,k<<1,l,r);
	if(r>mid)ans+=query(pos,k<<1|1,l,r);
	return ans;
}
int h[N],l[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	build(0,1,1,n);
	build(1,1,1,n);
	while(q--)
	{
		int opt,x,y,x1,y1;
		cin>>opt;
		if(opt==1)
		{
			cin>>x>>y;
			if(h[x]==0)modify(1,1,x,1);
			if(l[y]==0)modify(0,1,y,1);
			h[x]++;
			l[y]++;
		}
		else if(opt==2)
		{
			cin>>x>>y;
			if(h[x]==1)modify(1,1,x,-1);
			if(l[y]==1)modify(0,1,y,-1);
			h[x]--;
			l[y]--;
		}
		else 
		{
			cin>>x>>y>>x1>>y1;
			if(x>x1)swap(x,x1);
			if(y>y1)swap(y,y1);
			int ans1=query(1,1,x,x1);
			int ans2=query(0,1,y,y1);
			if(ans1==(x1-x+1)||ans2==(y1-y+1))
			{
				cout<<"YES"<<'\n';
			}
			else cout<<"NO"<<'\n';
		}
	}
}