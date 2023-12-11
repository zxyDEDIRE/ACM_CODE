#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 5e5 + 10;
const ll inf = 1e18;
const int maxn=1e5;
ll W[maxn];
int L[maxn],R[maxn];
int nn,mm;

namespace A{

struct seg{
    int l, r;
    bool operator <(const seg& A){
        if(r == A.r) return l < A.l; 
        return r < A.r;
    }
}s[N];

int lo[N], a[N], n, m;
void init(){
    for(int i = 2; i < N; i ++) lo[i] = lo[i >> 1] + 1;
}

int st[N][20];
void ST(){
    for(int j = 1; (1 << j) <= n; j ++){
        for(int i = 1; i + (1 << j) - 1 <= n; i ++){
            st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
        }
    }
}
int get_min(int l, int r){
    int k = lo[r - l + 1];
    return min(st[l][k], st[r - (1<<k) + 1][k]);
}

ll f[N]; // 前i个区间满足要求的最小花费
int solve(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        st[i][0] = a[i];
    }
    ST();

    cin >> m;
    for(int i = 1; i <= m; i ++){
        cin >> s[i].l >> s[i].r;
    }
    
    sort(s + 1, s + 1 + m);

    for(int i = 1; i <= m; i ++){
        f[i] = inf;
        int l = s[i].l, r = s[i].r;
        for(int j = i; j >= 1 && l <= r; j --){
            f[i] = min(f[i], f[j - 1] + get_min(l, r));
            // printf("get(%d %d) = %d\n", l, r, get_min(l, r));
            l = max(l, s[j - 1].l);
            r = min(r, s[j - 1].r);
        }        
    }
    return f[m];
}
};

namespace B{
const int maxn=1e6;
const int INF=1e9;
using pii=pair<int,int>;
struct Seg{
	int l,r;ll val,lazy;
}t[maxn<<1];
pii p[maxn];
ll w[maxn];
int n,m;
struct ST{
	int f[maxn][30];
	void init()
	{
		for(int i=1;i<=n;i++)//距离为0初始化 
			f[i][0]=w[i];
		int t=log(n)/log(2)+1;//j定位 
		for(int j=1;j<t;j++)
		{
			for(int i=1;i<=n-(1<<j)+1;i++)
			{
				f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
				//f[i][j-1]为f[i][j]的长为2^j-1的前半段，另一段为f[i+(1<<(j-1))][j-1] 
			}
		} 
	}
	int query(int l,int r)
	{
		int k=log2(r-l+1);
		return min(f[l][k],f[r-(1<<k)+1][k]);
	}
}st;
void pushup(int rt)
{
	t[rt].val=min(t[rt<<1].val,t[rt<<1|1].val);
}
void build(int rt,int l,int r){
	t[rt]={l,r,INF};
	if(l==r){
		t[rt].val=w[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		t[rt<<1].val=t[rt].lazy+st.query(t[rt<<1].l,t[rt<<1].r);
		t[rt<<1|1].val=t[rt].lazy+st.query(t[rt<<1|1].l,t[rt<<1|1].r);
		t[rt<<1].lazy=t[rt].lazy;
		t[rt<<1|1].lazy=t[rt].lazy;
		t[rt].lazy=0;
	}
}
void update(int rt,int l,int r,ll k)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		t[rt].val=k+st.query(t[rt].l,t[rt].r);
		t[rt].lazy=k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
ll query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	ll ans=INF;
	if(l<=mid)ans=min(ans,query(rt<<1,l,r));
	if(r>mid)ans=min(ans,query(rt<<1|1,l,r));
	return ans;
}

int solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>p[i].first>>p[i].second;
	sort(p+1,p+1+m);
	build(1,1,n);

	st.init();
	for(int i=2;i<=m;i++)
	{
		auto [l,r]=p[i];
		auto [_l,_r]=p[i-1];
		if(r>_r)
		{
			int upl=max(l,_r+1);
			int upr=r;
			ll qans=query(1,_l,_r);
			update(1,upl,upr,qans);
		}
	}
	// cout<<query(1,p[m].first,p[m].second)<<endl;
	return query(1,p[m].first,p[m].second);
}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    A::init();

    while(1)
    {
    	
    }



    return 0;
}
