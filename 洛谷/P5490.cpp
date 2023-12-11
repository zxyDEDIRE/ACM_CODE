/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct node{
	int x,y,h,fl;
}p[maxn];
struct Seg{
	int l,r,cnt,len;
}t[maxn<<2];
int w[maxn];
int n,m;
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt)
{
	if(t[rt].cnt)
	{
		t[rt].len=w[t[rt].r+1]-w[t[rt].l];
	}
	else t[rt].len=t[rt<<1].len+t[rt<<1|1].len;
}
void update(int rt,int l,int r,int c)
{
	//cout<<l<<" "<<r<<endl;
	int R=t[rt].r;
	int L=t[rt].l;
	//cout<<L<<" "<<R<<endl;
	//cout<<w[L]<<" "<<w[R]<<endl;


	if(w[R+1]<=l||w[L]>=r)
		return ;
	if(l<=w[L]&&w[R+1]<=r)
	{
		t[rt].cnt+=c;
		pushup(rt);
		return ;
	}
	update(rt<<1,l,r,c);
	update(rt<<1|1,l,r,c);
	pushup(rt);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		w[i*2-1]=a;
		w[i*2]=c;
		p[i*2-1]={a,c,b,1};
		p[i*2]={a,c,d,-1};
	}
	n<<=1;
	sort(w+1,w+1+n);
	sort(p+1,p+1+n,[&](node a,node b){
		return a.h<b.h;
	});
	m=unique(w+1,w+1+n)-w-1;

	build(1,1,m-1);

	int ans=0;
	for(int i=1;i<n;i++)
	{
		int x=p[i].x;
		int y=p[i].y;
		int h=p[i].h;
		int fl=p[i].fl;
		if(x>y)swap(x,y);
		update(1,x,y,p[i].fl);
		ans+=t[1].len*(p[i+1].h-p[i].h);
	}
	cout<<ans<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}