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
const int maxn=1e6+100;
struct Seg{
	int l,r,x,y,_x,_y;
}t[maxn<<2];
pii p[maxn];
int n,m;
void pushdown(int rt)
{
	if(t[rt]._x!=0||t[rt]._y!=0)
	{
		t[rt<<1].x+=t[rt]._x;
		t[rt<<1].y+=t[rt]._y;
		t[rt<<1]._x+=t[rt]._x;
		t[rt<<1]._y+=t[rt]._y;
		t[rt<<1|1].x+=t[rt]._x;
		t[rt<<1|1].y+=t[rt]._y;
		t[rt<<1|1]._x+=t[rt]._x;
		t[rt<<1|1]._y+=t[rt]._y;
		t[rt]._x=t[rt]._y=0;
	}
}
void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0,0,0};
	if(l==r){
		t[rt].x=p[l].first;
		t[rt].y=p[l].second;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void update(int rt,int l)
{
	if(t[rt].l==t[rt].r){
		swap(t[rt].x,t[rt].y);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l);
	else update(rt<<1|1,l);
}
pii query(int rt,int l)
{
	if(t[rt].l==t[rt].r)
		return {t[rt].x,t[rt].y};
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)return query(rt<<1,l);
	else return query(rt<<1|1,l);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	build(1,1,n);
	// cout<<endl;
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x,y;
			cin>>x>>y;
			t[1]._x+=x;
			t[1]._y+=y;
		}
		else if(op==2)
		{
			int x;cin>>x;
			update(1,x);
		}
		else if(op==3)
		{
			int x;cin>>x;
			auto now=query(1,x);
			cout<<now.first<<" "<<now.second<<endl;
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
3 1
1 2
2 5
6 2
3 2
*/