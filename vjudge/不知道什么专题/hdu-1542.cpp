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
	double x,y,_y,op;
}a[maxn];
struct Seg{
	int l,r,cv;
	double len;
}t[maxn];
double w[maxn];
int n,m;
void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt)
{
	if(t[rt].cv)
	{
		t[rt].len=w[t[rt].r+1]-w[t[rt].l];
	}
	else if(t[rt].l==t[rt].r)
	{
		t[rt].len=0;
	}
	else
	{
		t[rt].len=t[rt<<1].len+t[rt<<1|1].len;
	}
}
void update(int rt,int l,int r,int c)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		t[rt].cv+=c;
		pushup(rt);
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,c);
	if(r>mid)update(rt<<1|1,l,r,c);
	pushup(rt);
}
void solve()
{
	for(int i=1;i<=n;i++)
	{
		double x,y,_x,_y;
		scanf("%lf%lf%lf%lf",&x,&y,&_x,&_y);
		a[i*2-1]={x,y,_y,1};
		a[i*2]={_x,y,_y,-1};
		w[i*2-1]=y;
		w[i*2]=_y;
	}
	sort(w+1,w+1+n*2);
	m=unique(w+1,w+1+n*2)-w-1;
	sort(a+1,a+1+n*2,[&](node a,node b){
		if(a.x!=b.x)return a.x<b.x;
		else return a.op>b.op;
	});
	for(int i=1;i<=n*2;i++)
	{
		a[i].y=lower_bound(w+1,w+1+m,a[i].y)-w;
		a[i]._y=lower_bound(w+1,w+1+m,a[i]._y)-w;
	}
	build(1,1,m);
	double ans=0;

	for(int i=1;i<=n*2;i++)
	{
		update(1,a[i].y,a[i]._y-1,a[i].op);
		ans+=t[1].len*(a[i+1].x-a[i].x);
	}
	printf("Total explored area: %.2lf\n\n",ans);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int cnt=0;
	while(~scanf("%d",&n)&&n){
		cout<<"Test case #"<<++cnt<<endl;
		solve();
	}
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}