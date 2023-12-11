/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p[maxn];
struct Seg{
	struct node{
		int l,r,ma,mi;
	}t[maxn<<2];
	void f(int rt){}
	void pushup(int rt){
		t[rt].ma=max(t[rt<<1].ma,t[rt<<1|1].ma);
		t[rt].mi=min(t[rt<<1].mi,t[rt<<1|1].mi);
	}
	void pushdown(int rt){}
	void build(int rt,int l,int r){
		t[rt]={l,r,0};
		if(l==r){
			t[rt].mi=t[rt].ma=p[l];
			return ;
		};
		int mid=(l+r)>>1;
		build(rt<<1,l,mid);
		build(rt<<1|1,mid+1,r);
		pushup(rt);
	}
	int query(int rt,int l,int r,int op){
		if(l<=t[rt].l&&t[rt].r<=r){
			if(op==1)return t[rt].ma;
			return t[rt].mi;
		}
		int mid=(t[rt].l+t[rt].r)>>1;
		int ans;
		if(op==1)
		{
			ans=0;
			if(l<=mid)ans=max(ans,query(rt<<1,l,r,op));
			if(r>mid)ans=max(ans,query(rt<<1|1,l,r,op));
			return ans;
		}
		ans=INF;
		if(l<=mid)ans=min(ans,query(rt<<1,l,r,op));
		if(r>mid)ans=min(ans,query(rt<<1|1,l,r,op));
		return ans;
	}
}Seg;
int n,q;
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	Seg.build(1,1,n);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int a=Seg.query(1,x,y,1);
		int b=Seg.query(1,x,y,0);
		cout<<a-b<<endl;
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