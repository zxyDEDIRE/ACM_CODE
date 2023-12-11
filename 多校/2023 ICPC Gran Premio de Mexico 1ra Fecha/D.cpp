/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
const int maxn=1e6+100;
struct Seg{
	int l,r,val;
	int ls,rs;
}t[maxn];
map<int,int>mp;
int n,q,tot;
void f(int rt){
	cout<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].val<<endl;
}
void pushup(int rt)
{
	t[rt].val=0;
	if(t[rt].ls)
		t[rt].val+=t[t[rt].ls].val;
	if(t[rt].rs)
		t[rt].val+=t[t[rt].rs].val;
}
void add(int &rt,int l,int r,int x)
{
	if(!rt)rt=++tot,t[rt].val=0;
	t[rt].l=l;
	t[rt].r=r;
	if(l==r){
		mp[x]=1;
		t[rt].val++;
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid) add(t[rt].ls,l,mid,x);
	else add(t[rt].rs,mid+1,r,x);
	pushup(rt);
	// cout<<l<<" "<<r<<" "<<t[rt].val<<" "<<rt<<endl;
	// cout<<t[1].val<<endl;
}
int queryL(int rt,int x)
{
	if(t[rt].l>x)return 0;
	if(1<=t[rt].l&&t[rt].r<=x)
		return t[rt].val;
	int ans=0;
	if(t[rt].ls)ans+=queryL(t[rt].ls,x);
	if(t[rt].rs)ans+=queryL(t[rt].rs,x);
	return ans;
}
int h(int rt){
	if(rt)return t[rt].val;
	return 0;
}
void update(int rt,int l,int r,int x,int y)
{
	if(l==r){
		t[rt].val--;
		if(t[rt].val==0)mp[l]=0;
		return ;
	}
	int mid=(l+r)>>1;
	int L=x+h(t[rt].ls);
	int R=x+h(t[rt].ls)+h(t[rt].rs);
	if(L>y)
		update(t[rt].ls,l,mid,x,y);
	else
		update(t[rt].rs,mid+1,r,x+h(t[rt].ls),y);
	pushup(rt);
}
int query(int rt,int x,int y)
{
	if(t[rt].l>y)return 0;
	if(x<=t[rt].l &&t[rt].r <=y){
		return t[rt].val;
	}
	int ans=0;
	if(t[rt].ls)ans+=query(t[rt].ls,x,y);
	if(t[rt].rs)ans+=query(t[rt].rs,x,y);
	// cout<<t[rt].l<<" "<<t[rt].r<<" "<<ans<<endl;
	return ans;
}
void solve()
{
	cin>>n>>q;
	int rt=0;
	t[0].val=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		add(rt,1,INF,x);
	}
	while(q--)
	{
		int op,x,y;
		cin>>op;
		if(op==1)
		{
			cin>>x;
			if(!mp.count(x)||mp[x]==0)
			{
				int ans_1=queryL(1,x);
				if(ans_1<t[1].val)
					update(1,1,INF,0,ans_1);
				add(rt,1,INF,x);
			}
		}
		else if(op==2)
		{
			cin>>x>>y;
			cout<<query(1,x,y)<<endl;
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
10 1
7 1 7 1 3 9 7 9 10 4
1 8


1 1 3 4 7 7 7 9 9 10
1 1 3 4 7 7 7 8 9 10
1 1 3 4 7 7 7 8 9 10 20

*/