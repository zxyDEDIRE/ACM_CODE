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
const int maxn=2e5+10;
struct node{
	int l,r,val,lazy;
}t[maxn<<2][2];
vector<int>v[maxn];
int dep[maxn],top[maxn],id[maxn],siz[maxn],tot;
int n,q;
void dfs(int x,int fa,int topf)
{
	id[x]=++tot;
	top[x]=topf;
	siz[x]=1;
	dep[x]=dep[fa]+1;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs(y,x,topf);
		siz[x]+=siz[y];
	}
}
void build(int rt,int l,int r)
{
	t[rt][0].l=t[rt][1].l=l;
	t[rt][0].r=t[rt][1].r=r;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int fl,int rt)
{
	t[rt][fl].val=t[rt<<1][fl].val+t[rt<<1|1][fl].val;
}
void pushdown(int fl,int rt)
{
	if(t[rt][fl].lazy!=0)
	{
		t[rt<<1][fl].val+=t[rt][fl].lazy*(t[rt<<1][fl].r-t[rt<<1][fl].l+1);
		t[rt<<1|1][fl].val+=t[rt][fl].lazy*(t[rt<<1|1][fl].r-t[rt<<1|1][fl].l+1);
		t[rt<<1][fl].lazy+=t[rt][fl].lazy;
		t[rt<<1|1][fl].lazy+=t[rt][fl].lazy;
		t[rt][fl].lazy=0;
	}
}
void update(int fl,int rt,int l,int r,int k)
{
	if(l<=t[rt][fl].l&&t[rt][fl].r<=r)
	{
		t[rt][fl].val+=k*(t[rt][fl].r-t[rt][fl].l+1);
		t[rt][fl].lazy+=k;
		return ;
	}
	pushdown(fl,rt);
	int mid=(t[rt][fl].l+t[rt][fl].r)>>1;
	if(l<=mid)update(fl,rt<<1,l,r,k);
	if(r>mid)update(fl,rt<<1|1,l,r,k);
	pushup(fl,rt);
}
int query(int fl,int rt,int l)
{
	if(t[rt][fl].l==t[rt][fl].r)
		return t[rt][fl].val;
	pushdown(fl,rt);
	int mid=(t[rt][fl].l+t[rt][fl].r)>>1;
	if(l<=mid)return query(fl,rt<<1,l);
	else return query(fl,rt<<1|1,l);
	pushup(fl,rt);
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	id[1]=++tot;
	dep[1]=1;
	for(auto y:v[1])
		dfs(y,1,y);
	build(1,1,n);

	while(q--)
	{
		int op;cin>>op;
		if(op==0)
		{
			int x,k,d;
			cin>>x>>k>>d;
			if(x==1)
			{
				update(1,1,1,d,k);
			}
			else if(dep[x]-1>=d)
			{
				int s=dep[x]-d;
				int t=min(dep[x]+d,dep[x]+siz[x]-1);
				if(s==1)
				{
					update(0,1,id[top[x]],id[top[x]]+t-2,k);
					update(0,1,1,1,k);
				}
				else
				{
					update(0,1,id[top[x]]+s-2,id[top[x]]+t-2,k);
				}
			}
			else
			{
				int s=d-dep[x]+2;
				int t=min(dep[x]+d,dep[x]+siz[x]-1);
				update(1,1,1,s,k);
				if(id[top[x]]+s-1<=id[top[x]]+t-2)
					update(0,1,id[top[x]]+s-1,id[top[x]]+t-2,k);
			}
		}
		else
		{
			int x;cin>>x;
			cout<<query(0,1,id[x])+query(1,1,dep[x])<<endl;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3 4
1 2
2 3
0 2 1 0
1 1
1 2
1 3
*/