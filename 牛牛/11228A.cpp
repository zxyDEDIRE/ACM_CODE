#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
struct node
{
	int l,r;
	int maxn,minn;
	int lazy1,lazy2;
	
	node friend operator +(node a,node b)
	{
		node c;
		c.l=a.l;
		c.r=b.r;
		
		c.maxn=max(a.maxn,b.maxn);
		c.minn=min(a.minn,b.minn);
		
		c.lazy1=0;
		c.lazy2=0x3f3f3f3f;
		
		return c;
	}
}t[N<<2];

void pushup(int k)
{
	t[k]=t[k<<1]+t[k<<1|1];
}

void f(int k,int Max,int Min)
{
	t[k].maxn=max(t[k].maxn,Max);
	t[k].lazy1=max(t[k].maxn,Max);
	
	t[k].minn=min(t[k].minn,Min);
	t[k].lazy2=min(t[k].minn,Min);	
}

void pushdown(int k)
{
	f(k<<1,t[k].lazy1,t[k].lazy2);
	f(k<<1|1,t[k].lazy1,t[k].lazy2);
}

void build(int k,int l,int r)
{
	if(l==r)
	{
		t[k].l=t[k].r=l;
		t[k].maxn=t[k].lazy1=0;
		t[k].minn=t[k].lazy2=0x3f3f3f3f;
		return ;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}

void modify(int k,int l,int r,int Max,int Min)
{
	if(l<=t[k].l&&t[k].r<=r)
	{
		f(k,Max,Min);
		return ;
	}
	int mid=(t[k].l+t[k].r)>>1;
	pushdown(k);
	if(l<=mid)
		modify(k<<1,l,r,Max,Min);
	else 
		modify(k<<1|1,l,r,Max,Min);
	pushup(k);
}

node query(int k,int pos)
{
	if(t[k].l==t[k].r)
		return t[k];
		
	int mid=(t[k].l+t[k].r)>>1;
	pushdown(k);
	
	if(pos<=mid)
		return query(k<<1,pos);
	else 
		return query(k<<1|1,pos);
}

char s[N];
int n;
int p[N];

void init(string &t)
{
	n=0;
	s[n++]='^';
	s[n++]='#';
	for(auto i:t)
	{
		s[n++]=i;
		s[n++]='#';
	}
	s[n++]='@';
}

void manacher()
{
	int mr=0,mid=0;
	for(int i=1;i<n;i++)
	{
		if(i<mr)
			p[i]=min(p[2*mid-i],mr-i);
		else 
			p[i]=i;
			
		while(s[i-p[i]]==s[i+p[i]])p[i]++;
		
		if(i+p[i]<mr)
		{
			mid=i;
			mr=i+p[i];
		}
		
		modify(1,i,i+p[i]-1,0,i);
		modify(1,i-p[i]+1,i,i,0x3f3f3f3f);
	}
}
int main()
{
	string t;
	cin>>t;
	init(t);
	build(1,1,n+2);
	int ans=0;
	manacher();
	for(int i=2;i+3<n;i+=2)
	{
		int l=query(1,i).minn;
		int r=query(1,i+2).maxn;
		//if(l==0||r==0x3f3f3f3f)continue;
		cout<<l<<" "<<r<<endl;
        l=i-l+1;
		r=r-i-1;
		ans=max(ans,l+r);
	}
	cout<<ans;
}
