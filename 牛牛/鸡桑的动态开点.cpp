#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int mod=1e9+7;
typedef long long ll;
#define check() (ql<=l&&r<=qr)
struct node 
{
    int l,r;
    ll sum,lazyp;
}t[N*80];
int dfn=0,root=0;
void pushup(int k)
{
    int ls=t[k].l,rs=t[k].r;
    t[k].sum=(t[ls].sum+t[rs].sum)%mod;
}
void f(int k,ll v,ll len)
{
    t[k].lazyp=(t[k].lazyp+v)%mod;
    t[k].sum=(t[k].sum+v*len%mod)%mod;
}
void pushdown(int k,ll l,ll r)
{
    if(t[k].lazyp==0)return ;
    if(!t[k].l)t[k].l=++dfn;
    if(!t[k].r)t[k].r=++dfn;
    ll mid=l+r>>1;
    f(t[k].l,t[k].lazyp,mid-l+1);
    f(t[k].r,t[k].lazyp,r-mid);
    t[k].lazyp=0;
}
void modify(int &k,int l,int r,int ql,int qr,ll v)
{
    if(!k)k=++dfn;
    if(check())
    {
        f(k,v,r-l+1);
        return ;
    }
    pushdown(k,l,r);
    int mid=(l+r)>>1;
    if(ql<=mid)modify(t[k].l,l,mid,ql,qr,v);
    if(mid<qr)modify(t[k].r,mid+1,r,ql,qr,v);
    pushup(k);
}
ll query(int k,int l,int r,int ql,int qr)
{
    if(!k)return 0;
    if(check())
    {
        return t[k].sum%mod;
    }
    ll ans=0;
    pushdown(k,l,r);
    int mid=(l+r)>>1;
    if(ql<=mid)ans=(ans+query(t[k].l,l,mid,ql,qr)+mod)%mod;
    if(qr>mid)ans=(ans+query(t[k].r,mid+1,r,ql,qr)+mod)%mod;
    return ans%mod;
}
int main()
{

}
