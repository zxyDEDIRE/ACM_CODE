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
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=2e6+100;
struct Seg{
	int l,r,val;
}t[maxn<<2];
struct node{
	int op,x,y;
}q[maxn];
vector<int>v;
map<int,int>mp;
map<int,int>s;
int p[maxn];
int n,m,Q;
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt){
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void add(int rt,int x){
	if(t[rt].l==t[rt].r){
		t[rt].val++;
		s[t[rt].l]=1;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(x<=mid)add(rt<<1,x);
	else add(rt<<1|1,x);
	pushup(rt);
}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
void update(int rt,int x,int y)
{
	if(t[rt].l==t[rt].r){
		t[rt].val--;
		if(!t[rt].val)s[t[rt].l]=0;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int L=x+t[rt<<1].val;
	int R=x+t[rt<<1].val+t[rt<<1|1].val;
	if(L>y)update(rt<<1,x,y);
	else update(rt<<1|1,x+t[rt<<1].val,y);
	pushup(rt);
}
void solve()
{
	cin>>n>>Q;
	for(int i=1;i<=n;i++)
		cin>>p[i],v.push_back(p[i]);
	for(int i=1;i<=Q;i++){
		cin>>q[i].op;
		if(q[i].op==1)cin>>q[i].x,v.push_back(q[i].x);
		else cin>>q[i].x>>q[i].y,v.push_back(q[i].x),v.push_back(q[i].y);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<v.size();i++)
		mp[v[i]]=i+1;
	m=v.size();
	// for(int i=1;i<=m;i++)
	// 	cout<<i<<" ";cout<<endl;
	// for(int i=0;i<m;i++)
	// 	cout<<v[i]<<" ";cout<<endl;
	build(1,1,m);
	for(int i=1;i<=n;i++)
		add(1,mp[p[i]]);
	for(int i=1;i<=Q;i++)
	{
		auto [op,x,y]=q[i];
		if(op==1)
		{
			x=mp[x];
			if(!s.count(x)||s[x]==0)
			{
				int ans=query(1,1,x);
				if(ans!=t[1].val)
					update(1,0,ans);
				add(1,x);
			} 
		}
		else if(op==2)
		{
			cout<<query(1,mp[x],mp[y])<<endl;
		}
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
/*
10 2
7 1 7 1 3 9 7 9 10 4
1 8
2 2 8
*/