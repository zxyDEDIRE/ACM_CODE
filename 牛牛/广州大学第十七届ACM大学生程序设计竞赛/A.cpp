/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
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
struct node{
	int l,r,mi,ma,lazy;
}t[maxn<<2];
int p[maxn];
int n,k;
void pushup(int rt){
	t[rt].ma=max(t[rt<<1].ma,t[rt<<1|1].ma);
	t[rt].mi=min(t[rt<<1].mi,t[rt<<1|1].mi);
}
void pushdown(int rt){
	if(t[rt].lazy!=0){
		t[rt<<1].mi+=t[rt].lazy;
		t[rt<<1].ma+=t[rt].lazy;
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].mi+=t[rt].lazy;
		t[rt<<1|1].ma+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;
		t[rt].lazy=0;
	}
}
void build(int rt,int l,int r){
	t[rt]={l,r,0,0,0};
	if(l==r){
		t[rt]={l,r,p[l],p[l],0};
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int k){
	if(l<=t[rt].l&&t[rt].r<=r){
		t[rt].lazy-=k;
		t[rt].mi-=k;
		t[rt].ma-=k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
int query(int rt,int l,int r){
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
	for(int i=1;i<=n;i++)
		cin>>p[i];
	build(1,1,n);
	int cnt=0;
	for(int i=1;i+k-1<=n;i++)
	{
		int r=min(n,i+k-1);
		int mi=query(1,i,r);
		int now=query(1,i,i);
		cout<<i<<" "<<mi<<" "<<now<<endl;
		if(now>mi)cnt++;
		if(mi)update(1,i,r,mi);
	}
	for(int i=n-k+2;i<=n;i++)
		if(query(1,i,i))
			cnt++;
	cout<<cnt<<endl;
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