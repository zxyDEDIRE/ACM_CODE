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
const int maxn=1e6;
struct node{
	int l,r,val,ma;
}t[maxn<<2];
vector<int>v[maxn];
int son[maxn],dep[maxn],fa[maxn],siz[maxn];
int top[maxn],id[maxn],di[maxn],tot;
int p[maxn];
int n,q;
void dfs1(int x,int f,int deep)
{
	siz[x]=1;
	fa[x]=f;
	dep[x]=deep;
	int maxson=-1;
	for(auto y:v[x])
	{
		if(y==f)continue;
		dfs1(y,x,deep+1);
		siz[x]+=siz[y];
		if(siz[y]>maxson)
		{
			maxson=siz[y];
			son[x]=y;
		}
	}
}
void dfs2(int x,int topf)
{
	top[x]=topf;
	id[x]=++tot;
	di[tot]=x;
	if(son[x])dfs2(son[x],topf);
	for(auto y:v[x])
	{
		if(y==fa[x]||y==son[x])continue;
		dfs2(y,y);
	}
}
void pushup(int rt)
{
	t[rt].ma=max(t[rt<<1].ma,t[rt<<1|1].ma);
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r)
	{
		t[rt].ma=t[rt].val=p[di[l]];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int k)
{
	if(t[rt].l==t[rt].r)
	{
		t[rt].val=t[rt].ma=k;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,k);
	else update(rt<<1|1,l,k);
	pushup(rt);
}
int qmax(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].ma;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=-INF;
	if(l<=mid)ans=max(ans,qmax(rt<<1,l,r));
	if(r>mid)ans=max(ans,qmax(rt<<1|1,l,r));
	return ans;
}
int qsum(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=qsum(rt<<1,l,r);
	if(r>mid)ans+=qsum(rt<<1|1,l,r);
	return ans;
}
int SUM(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans+=qsum(1,id[top[x]],id[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	ans+=qsum(1,id[x],id[y]);
	return ans;
}
int MAX(int x,int y)
{
	int ans=-INF;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans=max(ans,qmax(1,id[top[x]],id[x]));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	ans=max(ans,qmax(1,id[x],id[y]));
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1,1,1);
	dfs2(1,1);
	for(int i=1;i<=n;i++)
		cin>>p[i];
	build(1,1,n);
	cin>>q;
	while(q--)
	{
		string str;
		cin>>str;
		if(str=="CHANGE")
		{
			int x,k;
			cin>>x>>k;
			update(1,id[x],k);
		}
		else if(str=="QMAX")
		{
			int x,y;
			cin>>x>>y;
			cout<<MAX(x,y)<<endl;
		}
		else
		{
			int x,y;
			cin>>x>>y;
			cout<<SUM(x,y)<<endl;
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
4
1 2
2 3
4 1
-1 -2 -3 -4
12
QMAX 3 4
QMAX 3 3
QMAX 3 2
QMAX 2 3
QSUM 3 4
QSUM 2 1
CHANGE 1 5
QMAX 3 4
CHANGE 3 6
QMAX 3 4
QMAX 2 4
QSUM 3 4

enable
conf t


192.168.1.2
192.168.1.1

192.168.2.2
192.168.2.1

hostname S3560
vlan 10
exit
vlan 20
exit
interface fastEthernet 0/10
switchport access vlan 10
exit

interface fastEthernet 0/20
switchport access vlan 20
exit

interface vlan 10 
ip address 192.168.1.1 255.255.255.0
no shut
exit

interface vlan 20 
ip address 192.168.3.1 255.255.255.0
no shut
exit
*/