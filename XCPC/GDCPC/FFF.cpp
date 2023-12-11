#include<bits/stdc++.h>
using namespace std;
const int maxn=1000006;
int n,m;
int op[2*maxn];//0进1出 
int x[2*maxn];//人数 
int kind[2*maxn];//类型，0社恐，1社牛 
int q[2*maxn];//记录出去的时间 

struct node
{
	int l,r;
	int sum;//坐了这么多人
	int a[5];//这个树里面，坐i人的桌子的最小序号 
}t[maxn<<2];


void pushup(int k)
{
	for(int i=0;i<5;i++)
		t[k].a[i]=min(  t[k<<1].a[i] , t[k<<1|1].a[i] );
}

void build(int k,int l,int r)
{
	t[k].l=l;
	t[k].r=r;
	t[k].sum=0;
	if(l==r)
	{
		for(int i=0;i<5;i++)
			t[k].a[i]=l; 
	}
	int mid=(t[k].l+t[k].r)/2;
	
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);	
	pushup(k);
}
//将x位置增加v个 
int modify(int k,int x,int v)
{
	if(t[k].l==x&&t[k].r==x)
	{
		t[k].sum+=v;
		for(int i=0;i<5;i++)
		{
			if(i<t[k].sum)
			{
				t[k].a[i]=maxn;
			}
			else
			{
				t[k].a[i]=l
			}
		}
	}
}


int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int xx,aa,bb,tt;
		cin>>xx>>aa>>bb>>tt;
		x[aa]=x[bb]=xx; 
		op[aa]=0;//进 
		op[bb]=1;//出 
		kind[aa]=tt;//社恐类型 
		q[a]=b;//记录出去的时间 
	}
	build(1,1,2*n); 
}
