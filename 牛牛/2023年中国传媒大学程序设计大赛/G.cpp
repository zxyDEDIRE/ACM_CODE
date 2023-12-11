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
	int x,id;
	double y;
}p[maxn];
struct Node{
	double x;
	int y,z;
};
struct Seg{
	int l,r,y,z;
	double x;
}t[maxn<<2];
int c[maxn];
int a[maxn];
int n,m,q;
void pushup(int rt){
	auto x=t[rt<<1];
	auto y=t[rt<<1|1];
	auto &now=t[rt];
	if(x.x>y.x)now=x;
	else if(x.x==y.x&&x.y>y.y)now=x;
	else if(x.x==y.x&&x.y==y.y&&x.z<y.z)now=x;
	else now=y;
}
void build(int rt,int l,int r){
	t[rt]={l,r,0,0,0};
	if(l==r){
		t[rt].x=p[l].y;
		t[rt].y=p[l].x;
		t[rt].z=p[l].id;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
Node query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		return {t[rt].x,t[rt].y,t[rt].z};
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	Node ans={0,0,0};
	if(l<=mid){
		auto x=query(rt<<1,l,r);
		if(x.x>ans.x)ans=x;
		else if(x.x==ans.x&&x.y>ans.y)ans=x;
		else if(x.x==ans.x&&x.y==ans.y&&x.z<ans.z)ans=x;
	}
	if(r>mid){
		auto x=query(rt<<1|1,l,r);
		if(x.x>ans.x)ans=x;
		else if(x.x==ans.x&&x.y>ans.y)ans=x;
		else if(x.x==ans.x&&x.y==ans.y&&x.z<ans.z)ans=x;
	}
	return ans;
}
void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i].y>>p[i].x,p[i].id=i-1;
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.x!=b.x)return a.x<b.x;
		if(a.y!=b.y)return a.y>b.y;
		return a.id<b.id;
	});
	build(1,1,n);
	for(int i=1;i<=n;i++)
		a[i]=p[i].x;
	for(int i=1;i<=m;i++)
		cin>>c[i];
	sort(c+1,c+1+m,[&](int a,int b){
		return a>b;
	});
	while(q--)
	{
		int s,k;
		cin>>s>>k;
		int ned=c[k]-s;
		int fl=lower_bound(a+1,a+1+n,ned)-a;
		if(fl>n)cout<<-1<<endl;
		else cout<<query(1,fl,n).z<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}