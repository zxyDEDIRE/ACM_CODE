/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
	ll x,y,z;
}p[maxn];
struct Seg{
	int l,r,val;
}t[maxn<<2];
int s[maxn],tot;
ll a[maxn],cnt;
int n,m;
void build(int rt,int l,int r)
{
	t[rt]={l,r,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void add(int rt,int l,int k)
{
	if(t[rt].l==t[rt].r)
	{
		t[rt].val+=k;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)add(rt<<1,l,k);
	else add(rt<<1|1,l,k);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].x;
		if(p[i].x==1)
		{
			cin>>p[i].y;
			s[++tot]=p[i].y;
			a[++cnt]=p[i].y;
		}
		else if(p[i].x==2)
		{
			cin>>p[i].y;
		}
		else if(p[i].x==3)
		{
			cin>>p[i].y>>p[i].z;
			s[p[i].y]+=p[i].z;
			a[++cnt]=s[p[i].y];
		}
		else if(p[i].x==4)
			cin>>p[i].y;
	}
	sort(a+1,a+1+cnt);
	m=unique(a+1,a+1+cnt)-a-1;

	// for(int i=1;i<=m;i++)
	// 	cout<<a[i]<<" ";
	// cout<<endl;

	build(1,1,m);

	tot=0;

	for(int i=1;i<=n;i++)
	{
		auto [fl,x,y]=p[i];

		if(fl==1)
		{
			int fl=lower_bound(a+1,a+1+m,x)-a;
			s[++tot]=fl;
			// cout<<i<<" "<<fl<<endl;
			add(1,fl,1);
		}
		else if(fl==2)
		{
			// cout<<i<<" "<<s[x]<<endl;
			add(1,s[x],-1);
		}
		else if(fl==3)
		{
			ll now=a[s[x]];
			// cout<<i<<" "<<now<<" ";
			now+=y;
			int fl=lower_bound(a+1,a+1+m,now)-a;
			add(1,s[x],-1);
			add(1,fl,1);
			s[y]=fl;
			// cout<<now<<" "<<fl<<" "
		}
		else if(fl==4)
		{
			int ans=query(1,1,s[x]-1);
			cout<<ans<<endl;
		}
	}
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
5 5 10
  1

9
1 5
1 5
1 10
4 3
2 2
4 3
3 3 7
4 3
4 1
*/