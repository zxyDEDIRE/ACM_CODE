#include<bits/stdc++.h>
using namespace std;
const int N=100005;
#define lson (k<<1)
#define rson (k<<1|1)
#define check (l<=t[k].l&&t[k].r<=r)
#define mid ((t[k].l+t[k].r)>>1)
struct node
{
    int l,r,va,lazyp,lch,rch;
}t[N<<2];
string s;
void pushup(int k)
{
    t[k].va=(t[lson].va+t[rson].va);
    if(t[lson].rch!=t[rson].lch)t[k].va++;
    t[k].lch=t[lson].lch;
    t[k].rch=t[rson].rch;
}
void f(int k)
{
    t[k].lch^=1;
    t[k].rch^=1;
    t[k].lazyp^=1;
}
void pushdown(int k)
{
    if(t[k].lazyp==0)return ;
    f(lson);
    f(rson);
    t[k].lazyp^=1;
}
void build(int k,int l,int r)
{
	
    t[k].l=l;
    t[k].r=r;
    if(l==r)
    {
        t[k].va=0;
        if(s[l-1]=='0')t[k].lch=t[k].rch=0;
        else t[k].lch=t[k].rch=1;
        return ;
    }
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    pushup(k);

}

void modify(int k,int l,int r)
{

	cout<<k<<" "<<t[k].va<<endl;
    if(check)
    {
        f(k);
        return ;
    }
    pushdown(k);
    if(l<=mid)
        modify(lson,l,r);
    if(r>mid)
        modify(rson,l,r);
    pushup(k);
    
}
node query(int k,int l,int r)
{

    node now,ans;
    ans.va=0;
    ans.lch=ans.rch=-1;
    if(check)
        return t[k];
    pushdown(k);
    if(l<=mid)
    {
        now=query(lson,l,r);
        ans.va+=now.va;
        if(ans.rch==-1)ans.rch=now.rch;
        ans.lch=now.lch;
    }
    if(r>mid)
    {
        now=query(rson,l,r);
        ans.va+=now.va;
        if(ans.rch!=now.lch&&ans.rch!=-1)
            ans.va++;
        ans.rch=now.rch;
        if(ans.lch==-1)ans.lch=now.lch;
    }
    return ans;
}

int main()
{
	string a;
	map<string,double>mp;
	mp["°ë¼Û"]=0.5;
	cin>>a;
	cout<<mp[a]<<endl; 
	/*
	vector<int>v;
	v.push_back(1);
	for(auto i:v)cout<<i<<" ";*/
}
