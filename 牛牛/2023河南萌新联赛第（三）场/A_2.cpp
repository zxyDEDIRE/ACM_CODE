/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int l,r,val,sum,lazy,lazy_1,t;
}t[maxn<<2];
int n,q,ans;
void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0,0,0,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt)
{
	int ti=max(t[rt<<1].t,t[rt<<1|1].t);
	// cout<<endl;
	// cout<<"ti "<<ti<<" "<<t[rt<<1].t<<" "<<t[rt<<1|1].t<<endl;
	if(t[rt<<1].t!=ti)
	{
		t[rt<<1].sum+=t[rt<<1].val*(ti-t[rt<<1].t);
		t[rt<<1].t=ti;
	}
	if(t[rt<<1|1].t!=ti)
	{
		t[rt<<1|1].sum+=t[rt<<1|1].val*(ti-t[rt<<1|1].t);
		t[rt<<1|1].t=ti;
	}
	// cout<<"rt sdf "<<t[rt<<1].sum<<" "<<t[rt<<1|1].sum<<endl;
	t[rt].sum=t[rt<<1].sum+t[rt<<1|1].sum;
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
	t[rt].t=ti;
	// cout<<"rt "<<rt<<" "<<t[rt].sum<<endl;
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		// cout<<t[rt<<1].val<<" "<<t[rt].lazy<<endl;
		t[rt<<1].sum+=t[rt<<1].val*(t[rt].t-t[rt<<1].t)+t[rt].lazy*(t[rt<<1].r-t[rt<<1].l+1);
		t[rt<<1].val+=t[rt].lazy_1*(t[rt<<1].r-t[rt<<1].l+1);
		t[rt<<1].lazy_1+=t[rt].lazy_1;
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1].t=t[rt].t;
		// cout<<"pushdown "<<t[rt<<1].sum<<" "<<t[rt].lazy<<" "<<t[rt<<1].val<<endl;

		t[rt<<1|1].sum+=t[rt<<1|1].val*(t[rt].t-t[rt<<1|1].t)+t[rt].lazy*(t[rt<<1|1].r-t[rt<<1|1].l+1);
		t[rt<<1|1].val+=t[rt].lazy_1*(t[rt<<1|1].r-t[rt<<1|1].l+1);
		t[rt<<1|1].lazy_1+=t[rt].lazy_1;
		t[rt<<1|1].lazy+=t[rt].lazy;
		t[rt<<1|1].t=t[rt].t;

		t[rt].lazy=0;
		t[rt].lazy_1=0;
	}
}
void update(int rt,int l,int r,int w,int ti)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].lazy+=t[rt].lazy_1*(ti-t[rt].t);
		t[rt].val+=(t[rt].r-t[rt].l+1)*w;
		// cout<<"SDF "<<t[rt].sum<<endl;
		t[rt].sum+=t[rt].val*(ti-t[rt].t);
		t[rt].lazy+=w*(ti-t[rt].t);
		// cout<<"SDf "<<t[rt].lazy<<" "<<t[rt].sum<<endl;
		t[rt].lazy_1+=w;
		t[rt].t=ti;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,w,ti);
	if(r>mid)update(rt<<1|1,l,r,w,ti);
	pushup(rt);
}
void query(int rt,int l,int r,int ti)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{	
		// cout<<t[rt].sum<<" "<<t[rt].t<<" "<<t[rt].sum<<endl;
		t[rt].sum+=t[rt].val*(ti-t[rt].t);
		t[rt].t=ti;
		ans+=t[rt].sum;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)query(rt<<1,l,r,ti);
	if(r>mid)query(rt<<1|1,l,r,ti);
	pushup(rt);
}
void solve()
{
	cin>>n>>q;
	build(1,1,n);
	for(int i=1;i<=q;i++)
	{
		int op,x,y,w;
		cin>>op>>x>>y;
		if(op==0)
		{
			cin>>w;
			update(1,x,y,w,i);
		}
		else
		{
			ans=0;
			query(1,x,y,i);
			cout<<ans<<endl;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3 3
0 1 3 1
0 1 2 2
1 1 3

1 1 1
3 3 1
3 3 1 
3*4+5=17
*/