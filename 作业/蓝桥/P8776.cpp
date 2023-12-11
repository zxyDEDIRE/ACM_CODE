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
struct node{
	int l,r,val;
}t[2][maxn<<2];
int p[maxn];
int n,k;
void pushup(int fl,int rt){
	t[fl][rt].val=max(t[fl][rt<<1].val,t[fl][rt<<1|1].val);
}
void build(int rt,int l,int r){
	t[0][rt]=t[1][rt]={l,r,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void update(int fl,int rt,int l,int k){
	if(t[fl][rt].l==t[fl][rt].r){
		t[fl][rt].val=k;
		return ;
	}
	int mid=(t[fl][rt].l+t[fl][rt].r)>>1;
	if(l<=mid)update(fl,rt<<1,l,k);
	else update(fl,rt<<1|1,l,k);
	pushup(fl,rt);
}
int query(int fl,int rt,int l,int r){
	if(l<=t[fl][rt].l&&t[fl][rt].r<=r){
		return t[fl][rt].val;
	}
	int mid=(t[fl][rt].l+t[fl][rt].r)/2;
	int ans=0;
	if(l<=mid)ans=max(ans,query(fl,rt<<1,l,r));
	if(r>mid)ans=max(ans,query(fl,rt<<1|1,l,r));
	return ans;
}
int dp[maxn][2];
void dfs(int rt)
{
	cout<<t[0][rt].l<<" "<<t[0][rt].r<<endl;
	if(t[0][rt].l==t[0][rt].r)return ;
	dfs(rt<<1);
	dfs(rt<<1|1);
}
void solve()
{
	cin>>n>>k;
	int ma=0;
	for(int i=1;i<=n;i++)
		cin>>p[i],ma=max(ma,p[i]);
	build(1,1,ma);
	int ans=k;
	for(int i=k+1;i<=n;i++)
	{
		dp[i-k][0]=max(dp[i-k][0],query(0,1,1,p[i-k])+1);
		update(0,1,p[i-k],dp[i-k][0]);
		dp[i][1]=max(dp[i][1],query(1,1,1,p[i])+1);
		dp[i][1]=max(dp[i][1],query(0,1,1,p[i])+k+1);
		update(1,1,p[i],dp[i][1]);
		ans=max(dp[i][1],ans);
		ans=max(dp[i-k][0],ans);
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}