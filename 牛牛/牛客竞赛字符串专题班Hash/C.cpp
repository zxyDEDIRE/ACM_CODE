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
const int maxn=1e6+100;
char ch[maxn];
int lc[maxn];
int N;
struct Manacher{
	void init(char *s){
		int n=strlen(s+1);
		ch[n*2+1]='#';
		ch[0]='@';
		ch[n*2+2]='\0';
		for(int i=1;i<=n;i++)
			ch[i*2]=s[i],ch[i*2-1]='#';
		N=n*2+1;
	}
	void manacher(){
		lc[1]=1;int k=1;
		for (int i=2;i<=N;i++){
			int p = k+lc[k]-1;
			if (i<=p){
				lc[i]=min(lc[2*k-i],p-i+1);
			}else{	lc[i]=1;}
			while(ch[i+lc[i]]==ch[i-lc[i]])lc[i]++;
			if(i+lc[i]>k+lc[k])k=i;
		}
	}
}Manch;
struct node{
	int l,r,id;
}q1[maxn],q2[maxn];
struct Seg{
	int l,r,val,lazy;
}t[maxn<<2];
int ans[maxn];
char s[maxn];
int n,q;
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
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		t[rt<<1].val+=t[rt].lazy*(t[rt<<1].r-t[rt<<1].l+1);
		t[rt<<1|1].val+=t[rt].lazy*(t[rt<<1|1].r-t[rt<<1|1].l+1);
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;
		t[rt].lazy=0;
	}
}
void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		t[rt].val+=k*(t[rt].r-t[rt].l+1);
		t[rt].lazy+=k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
void solve()
{
	scanf("%lld%lld",&n,&q);
	scanf("%s",s+1);
	Manch.init(s);
	Manch.manacher();
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%lld%lld",&l,&r);
		l=l*2-1;
		r=r*2+1;
		int mid=(l+r)>>1;
		q1[i]={l,mid,i};
		q2[i]={mid+1,r,i};
	}

	sort(q1+1,q1+q+1,[&](node a,node b){
		return a.r<b.r;
	});
	build(1,1,n); 
	for(int i=1,j=1;i<=N;i++)
	{
		int l=i-lc[i]+1;
		int r=i+lc[i]-1;
		l=(l+1)>>1;
		r=(r-1)>>1;
		if(lc[i]-1)update(1,l,i>>1,1);
		for(;j<=q&&q1[j].r==i;j++)
		{
			l=(q1[j].l+1)>>1;
			r=(q1[j].r)>>1;
			ans[q1[j].id]+=query(1,l,r);
		}
	}


	sort(q2+1,q2+q+1,[&](node a,node b){
		return a.l>b.l;
	});
	build(1,1,n); 
	for(int i=N,j=1;i>=1;i--)
	{
		int l=i-lc[i]+1;
		int r=i+lc[i]-1;
		l=(l+1)>>1;
		r=(r-1)>>1;
		if(lc[i]-1)update(1,(i+1)>>1,r,1);
		for(;j<=q&&q2[j].l==i;j++)
		{
			l=(q2[j].l+1)>>1;
			r=(q2[j].r)>>1;
			if(l<=r)ans[q2[j].id]+=query(1,l,r);
		}
	}
	for(int i=1;i<=q;i++)
		printf("%lld\n",ans[i]);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
10 310 3
assdadsasd
1 10
1 7
3 6
assdadsasd
1 10
1 7
3 6
*/