/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18+7;
const int maxn=1e6+100;
struct node{
	int l,r,val,lazy,mi;
}t[maxn<<2];
int p[maxn];
int h[maxn];
int c[maxn];
int n,k;
void build(int rt,int l,int r){
	t[rt]={l,r,INF,0,INF};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt){
	t[rt].mi=min(t[rt<<1].mi,t[rt<<1|1].mi);
}
void pushdown(int rt){
	if(t[rt].lazy)
	{
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;
		t[rt<<1].mi+=t[rt].lazy;
		t[rt<<1|1].mi+=t[rt].lazy;
		t[rt].lazy=0;
	}
}
void add(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].mi=min(INF,t[rt].mi+k);
		t[rt].lazy+=k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)add(rt<<1,l,r,k);
	if(r>mid)add(rt<<1|1,l,r,k);
	pushup(rt);
}
void update(int rt,int l,int k){
	if(t[rt].l==t[rt].r){
		t[rt].mi=min(t[rt].mi,k);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,k);
	else update(rt<<1|1,l,k);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].mi;
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=INF;
	if(l<=mid)ans=min(ans,query(rt<<1,l,r));
	if(r>mid)ans=min(ans,query(rt<<1|1,l,r));
	return ans;
}
void solve()
{
	cin>>n>>k;
	build(1,0,k);
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=k;i++)
		cin>>c[i];
	for(int i=1;i<=k;i++)
		cin>>h[i];
	update(1,0,c[p[1]]);
	int last=p[1];
	for(int i=2;i<=n;i++)
	{
		if(p[i]==last)
			add(1,0,k,h[p[i]]);
		else
		{
			int ans_1=t[1].mi+c[p[i]];
			int ans_2=query(1,p[i],p[i])+h[p[i]];
			add(1,0,k,c[p[i]]);
			update(1,last,min(ans_1,ans_2));
		}
		last=p[i];
	}
	cout<<t[1].mi<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}