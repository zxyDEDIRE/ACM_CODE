#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
struct seg{
	int l,r,num;
	int a[5];
}t[maxn<<2];
bool op[maxn];
int p[maxn],fl[maxn],q[maxn];
int n,x,a,b,tt;
void pushup(int rt)
{
	for(int i=0;i<5;i++)
	{
		t[rt].a[i]=min(t[rt<<1].a[i],t[rt<<1|1].a[i]);
	}	
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].num=0;
	for(int i=0;i<5;i++)
		t[rt].a[i]=r;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int x)
{
	if(t[rt].l==t[rt].r&&t[rt].l==l)
	{
		t[rt].num+=x;
		for(int i=0;i<5;i++)
		{
			if(i<t[rt].num)t[rt].a[i]=2*n;
			else t[rt].a[i]=l;
		}
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,x);
	else update(rt<<1|1,l,x);
	pushup(rt);
}
int main()
{
	cin>>n;
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>a>>b>>tt;
		p[a]=x;op[a]=0;fl[a]=tt;q[a]=b;//cun
		p[b]=x;op[b]=1;					//qu
	}
	build(1,1,2*n);
	for(int i=1;i<=2*n;i++)
	{
		if(op[i]==0)
		{
			if(fl[i]==0)//shekong
			{
				x=t[1].a[0];
				update(1,x,p[i]);
			}
			else//
			{
				x=2*n;
				for(int j=0;j+p[i]<=4;j++){
					x=min(x,t[1].a[j]);
				}
						
				update(1,x,p[i]);
			}
			q[q[i]]=x;
	//		cout<<x<<endl;
			
			
			//	cout<<"-------x--"<<x<<endl;
			ma=max(ma,x);
		}
		else
		{	
			x=q[i];
			update(1,q[i],-p[i]);
		}
	}
	cout<<ma<<endl;
}
/*
2
3 1 3 0
1 2 4 1

4
1 1 8 0
3 2 3 0
1 4 6 0
2 5 7 0

5
1 1 10 0
3 2 9 1
1 4 6 0
2 5 7 0
3 3 8 0

4
1 1 8 1
1 2 5 0
1 3 4 0
1 6 7 0

6
1 1 6 1
1 2 7 1
1 3 8 0
1 4 9 0
1 5 10 1
1 11 12 1

*/
