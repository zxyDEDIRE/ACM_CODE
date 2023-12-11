#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
string str;
int n,m;
struct SegTree{
	int l,r,val,la,ra,lazy;
}segtree[maxn<<2];


void pushup(int rt)
{
	segtree[rt].val=(segtree[rt<<1].val+segtree[rt<<1|1].val);
	if(segtree[rt<<1].ra!=segtree[rt<<1|1].la)segtree[rt].val++;
	segtree[rt].la=segtree[rt<<1].la;
	segtree[rt].ra=segtree[rt<<1|1].ra;

}
void pushdown(int rt)
{
	if(segtree[rt].lazy==0)return;
	segtree[rt<<1].la^=1;
	segtree[rt<<1].ra^=1;
	segtree[rt<<1].lazy^=1;
	segtree[rt<<1|1].la^=1;
	segtree[rt<<1|1].ra^=1;
	segtree[rt<<1|1].lazy^=1;
	segtree[rt].lazy^=1;
}
void build(int l,int r,int rt)
{
	
	segtree[rt].l=l;
	segtree[rt].r=r;
	if(l==r)
	{
		segtree[rt].val=0;
		if(str[l-1]=='0')segtree[rt].la=segtree[rt].ra=0;
		else segtree[rt].la=segtree[rt].ra=1;
		return ;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
	
}
void update(int l,int r,int rt)
{
//cout<<rt<<" "<<segtree[rt].val<<endl;
//	cout<<l<<" "<<r<<" "<<rt<<endl;
	if(l<=segtree[rt].l&&segtree[rt].r<=r)
	{
		segtree[rt].la^=1;
		segtree[rt].ra^=1;
		segtree[rt].lazy^=1;
		return ;
	}
//	if(segtree[rt].l>r||segtree[rt].r<l)return ;
	pushdown(rt);
	int m=(segtree[rt].l+segtree[rt].r)>>1;
	if(l<=m)update(l,r,rt<<1);
	if(r>m)update(l,r,rt<<1|1);
	pushup(rt);
	
}
SegTree query(int l,int r,int rt)
{
	
//	cout<<l<<" "<<r<<" "<<segtree[rt].l<<" "<<segtree[rt].r<<endl;
	SegTree now,ans;
	ans.val=0;
	ans.la=ans.ra=-1;
	if((l<=segtree[rt].l)&&(segtree[rt].r<=r))
	{
		return segtree[rt];
	}
	pushdown(rt);
//	if(segtree[rt].l>r||segtree[rt].r<l)return ans;
	int m=(segtree[rt].l+segtree[rt].r)>>1;
	if(l<=m)
	{
		now =query(l,r,rt<<1);
		ans.val+=now.val;
		if(ans.ra==-1)ans.ra=now.ra;
		ans.la=now.la;
	}
	if(r>m)
	{
		now =query(l,r,rt<<1|1);
		ans.val+=now.val;
		if(ans.ra!=now.la&&ans.ra!=-1)
            ans.val++;
        ans.ra=now.ra;
        if(ans.la==-1)ans.la=now.la;
	}
	return ans;
}

int main()
{
	cin>>n>>m;
	cin>>str;
	build(1,n,1);
	for(int i=1;i<=m;i++)
	{
		int fl,x,y;
		cin>>fl>>x>>y;
		
		if(fl==1){
			SegTree it=query(x,y,1);
			cout<<it.val<<endl;
		}
		else{
			update(x,y,1);
		} 
	}
}