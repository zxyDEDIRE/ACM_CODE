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
struct V{
	int len,l,r;
	V():len(0),l(0),r(0){}
};
struct P{
	char ch;int num;
	P():ch('#'),num(0){}
};
struct node{
	int l,r;
	V val;
	P _l,_r;
	node():l(0),r(0),val(),_l(),_r(){}
}t[maxn];
char ch[maxn];
int n,m;
V operator+(const V a,const V b){
	if(b.len>a.len)return b;
	else if(b.len<a.len)return a;
	else if(a.l<=b.l)return a;
	return b;
}
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
	if(t[rt<<1]._r.ch==t[rt<<1|1]._l.ch)
	{
		V now;
		now.len=t[rt<<1]._r.num+t[rt<<1|1]._l.num;
		now.l=t[rt<<1].r-t[rt<<1]._r.num+1;
		now.r=t[rt<<1|1].l+t[rt<<1|1]._l.num-1;
		t[rt].val=t[rt].val+now;
	}
	t[rt]._l=t[rt<<1]._l;
	t[rt]._r=t[rt<<1|1]._r;
	if(t[rt<<1]._l.num==t[rt<<1].r-t[rt<<1].l+1&&t[rt<<1]._r.ch==t[rt<<1|1]._l.ch)
		t[rt]._l.num=t[rt<<1]._l.num+t[rt<<1|1]._l.num;

	if(t[rt<<1|1]._r.num==t[rt<<1|1].r-t[rt<<1|1].l+1&&t[rt<<1]._r.ch==t[rt<<1|1]._l.ch)
		t[rt]._r.num=t[rt<<1|1]._r.num+t[rt<<1]._r.num;
}
node query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt];
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	node L,R,ans;
	if(l<=mid)L=query(rt<<1,l,r);
	if(r>mid)R=query(rt<<1|1,l,r);
	ans.val=L.val+R.val;

	ans.l=n+1;
	ans.r=0;

	if(l<=mid)
	{
		ans.l=min(ans.l,L.l);
		ans.r=max(ans.r,L.r);
	}
	if(r>mid)
	{
		ans.l=min(ans.l,R.l);
		ans.r=max(ans.r,R.r);
	}


	if(l<=mid&&r>mid)
		ans._l=L._l,ans._r=R._r;
	else if(l<=mid)
		ans._l=L._l,ans._r=L._r;
	else if(r>mid)
		ans._l=R._l,ans._r=R._r;


	if(L._r.ch==R._l.ch)
	{
		V now;
		now.len=L._r.num+R._l.num;
		now.l=L.r-L._r.num+1;
		now.r=R.l+R._l.num-1;
		ans.val=ans.val+now;
	}

	if(L._l.num==L.r-L.l+1&&L._r.ch==R._l.ch)
		ans._l.num=L._l.num+R._l.num;
	if(R._r.num==R.r-R.l+1&&L._r.ch==R._l.ch)
		ans._r.num=R._r.num+L._r.num;
	return ans;
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(t[rt].l==t[rt].r){
		t[rt]._l.ch=ch[l];
		t[rt]._r.ch=ch[l];
		t[rt]._l.num=t[rt]._r.num=1;
		t[rt].val.len=1;
		t[rt].val.l=t[rt].val.r=l;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,char a)
{
	if(t[rt].l==t[rt].r)
	{
		t[rt]._l.ch=t[rt]._r.ch=a;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,a);
	else update(rt<<1|1,l,a);
	pushup(rt);
}

void solve()
{
	cin>>n>>m>>ch+1;
	build(1,1,n);
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int l,r;
			cin>>l>>r;
			node now=query(1,l,r);
			cout<<now.val.l<<" "<<now.val.r<<endl;
			// cout<<now.l<<" "<<now.r<<endl;
		}
		else if(op==2)
		{
			int x;char ch;
			cin>>x>>ch;
			update(1,x,ch);
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
10 4
aabbbccdde
1 1 5
2 3 a
1 1 5
1 5 7
 

25 2
aaaaaaaaaaaaaaaaaaaaaaaaa
2 15 b
1 13 25
*/