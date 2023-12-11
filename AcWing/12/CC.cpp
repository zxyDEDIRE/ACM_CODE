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
	int l,r,val,lazy;
}t[maxn<<2];
int n,m;
inline int read(int &x){
	int s = 0, w = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	x = s*w;
	if(ch=='\n')return 1;
	else return 0;
}
void pushup(int rt)
{
	t[rt].val=min(t[rt<<1].val,t[rt<<1|1].val);
}
void build(int rt,int l,int r){
	t[rt]={l,r,0,0};
	if(l==r){
		read(t[rt].val);
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void pushdown(int rt)
{
	if(t[rt].lazy!=0)
	{
		t[rt<<1].val+=t[rt].lazy;
		t[rt<<1|1].val+=t[rt].lazy;
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;
		t[rt].lazy=0;
	}
}
void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].val+=k;
		t[rt].lazy+=k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=1e16;
	if(l<=mid)ans=min(ans,query(rt<<1,l,r));
	if(r>mid)ans=min(ans,query(rt<<1|1,l,r));
	return ans;
}
void solve()
{
	read(n);
	build(1,1,n);
	read(m);
	while(m--)
	{
		vector<int>v;
		int x;
		while(1)
		{
			 int y=read(x);
			 v.push_back(x);
			 // cout<<x<<endl;
			 if(y==1)break;
		}
		if(v.size()==2)
		{
			int x=v[0],y=v[1],ans=1e16;
			if(x<=y)ans=query(1,x+1,y+1);
			else ans=min(query(1,x+1,n),query(1,1,y+1));
			cout<<ans<<endl;
		}
		else
		{
			int x=v[0],y=v[1],k=v[2];
			if(x<=y)update(1,x+1,y+1,k);
			else update(1,x+1,n,k),update(1,1,y+1,k);
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
	// cout<<(char)(10);
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
0 1 2 3 4
1 2 3 4 5
*/