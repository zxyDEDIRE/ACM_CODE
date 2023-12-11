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
	int l,r,val;
}t[maxn<<2];
vector<int>v;
string x,y;
void build(int rt,int l,int r){
	t[rt]={l,r,1};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushdown(int rt){
	if(t[rt].val==0)
		t[rt<<1].val=t[rt<<1|1].val=0;
}
void update(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].val=0;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r);
	if(r>mid)update(rt<<1|1,l,r);
}
void dfs(int rt)
{
	if(t[rt].l==t[rt].r){
		v.push_back(t[rt].val);
		return ;
	}
	pushdown(rt);
	dfs(rt<<1);
	dfs(rt<<1|1);
}
void solve()
{
	cin>>x>>y;
	int len_x=x.size();
	int len_y=y.size();
	build(1,0,len_y);
	for(int i=0,j;i<len_y;i++)
	{
		j=len_x-len_y+i;
		if(x[j]!='?'&&y[i]!='?'&&x[j]!=y[i]){
			update(1,0,i);
		}
		if(x[i]!='?'&&y[i]!='?'&&x[i]!=y[i]){
			update(1,i+1,len_y);
		}
	}
	dfs(1);
	for(auto i:v)
		cout<<(i==1?"Yes":"No")<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
7-4+3+1
atcoder
o d e r
a d e r
a t e r
a t c r
a t c o

a?c
? c
a c
a ?
*/