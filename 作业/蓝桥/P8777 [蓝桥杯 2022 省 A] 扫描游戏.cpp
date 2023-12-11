/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct SEG{
	struct Seg{
		int l,r,val;
	}t[maxn<<2];
	void pushup(int rt){
		t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
	}
	void build(int rt,int l,int r){
		t[rt]={l,r,0};
		if(l==r)return ;
		int mid=(l+r)>>1;
		build(rt<<1,l,mid);
		build(rt<<1|1,mid+1,r);
	}
	void update(int rt,int l,int k){
		if(t[rt].l==t[rt].r){
			t[rt].val+=k;
			return ;
		}
		int mid=(t[rt].l+t[rt].r)>>1;
		if(l<=mid)update(rt<<1,l,k);
		else update(rt<<1|1,l,k);
		pushup(rt);
	}
	int query(int rt,int l,int r){
		if(l>r)return 0;
		if(l<=t[rt].l&&t[rt].r<=r){
			return t[rt].val;
		}
		int mid=(t[rt].l+t[rt].r)>>1;
		int ans=0;
		if(l<=mid)ans+=query(rt<<1,l,r);
		if(r>mid)ans+=query(rt<<1|1,l,r);
		return ans;
	}
}S,T;
int p[maxn];
int a[maxn];
int n,m,tot;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],a[i]=p[i];
	sort(a+1,a+1+n);
	m=unique(a+1,a+1+n)-a-1;
	for(int i=1;i<=n;i++)
		p[i]=lower_bound(a+1,a+1+m,p[i])-a;
	S.build(1,1,m);
	T.build(1,1,m);
	for(int i=1;i<=n;i++)
		T.update(1,p[i],1);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		T.update(1,p[i],-1);
		long long now=S.query(1,p[i]+1,m)+T.query(1,1,p[i]-1);
		S.update(1,p[i],1);
		ans+=(1+now)*now/2;
		// cout<<now<<" "<<(1+now)*now/2<<endl;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
*/