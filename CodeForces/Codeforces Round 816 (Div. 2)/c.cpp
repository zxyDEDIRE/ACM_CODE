/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct node{
	int l,r,val,same,num;
}t[maxn<<2];
ll p[maxn];
ll n,m,sum,su;
void pushup(int rt)
{
	if(t[rt<<1].val==t[rt<<1|1].val&&t[rt<<1].same&&t[rt<<1|1].same)
	{
		t[rt].val=t[rt<<1].val;
		t[rt].same=1;
		t[rt].num=t[rt<<1].num+t[rt<<1|1].num;
	}
	else t[rt].same=0;
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].val=t[rt].same=0;
	if(l==r)
	{
		cin>>p[l];
		t[rt].val=p[l];
		t[rt].same=1;
		t[rt].num=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int c)
{
	if(t[rt].l==t[rt].r)
	{
		t[rt].val=c;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(mid<=l)update(rt<<1,l,c);
	else update(rt<<1|1,l,c);
	pushup(rt);
}
int ql(int rt,int l,int c)
{
	if(t[rt].r<=l&&t[rt].same&&t[rt].val==c)
	{
		return t[rt].num;
	}
}
void solve()
{
	cin>>n>>m;
	sum=0,su=0;
	for(int i=1;i<=n;i++)
		su+=i,sum+=su;
	cout<<su<<endl;
	//build(1,1,n);



}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1

1 2 2 4 5
35
29

1 2 3 4 5  35
1 2 2 4 5  29
1 2 2 2 5  23
1 2 1 2 5  35
1 1 1 2 5  25
1 2 1 2 5  35
*/