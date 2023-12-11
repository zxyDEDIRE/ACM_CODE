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
	int l,r,val,ma,lazy;
}t[maxn<<2];
void build(int rt,int l,int r){
	t[rt]={l,r,0,0,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushdown(int rt)
{

}
void pushup(int rt)
{

}
void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		if(t[rt].ma+k<=0)
		{
			t[rt].val-=k;
			t[rt].ma=0;
			t[rt].lazy+=k;
			return ;
		}
		else if(k)
		{
			t[rt].val+=k*(t[rt].r-t[rt].l+1);
			
		}
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
void solve()
{
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