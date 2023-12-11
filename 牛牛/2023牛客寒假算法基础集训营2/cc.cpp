#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const int mod = 998244353, M = 4e5 + 10;
struct seg{
    int l, r;
    ll sum, laz;
}tr[M * 4];

void pushup(int p){
    tr[p].sum = (tr[p << 1].sum + tr[p << 1 | 1].sum) % mod;
}

void build(int p, int l,int r){
    tr[p] = {l, r, 0, 0};
    if(l == r)return ;
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
}

void pushdown(int p){
    ll laz = tr[p].laz;
    if(laz){
        tr[p << 1].sum = (tr[p << 1].sum + (tr[p << 1].r - tr[p << 1].l + 1) * laz % mod + mod) % mod;
        
        tr[p << 1 | 1].sum =( tr[p << 1 | 1].sum + (tr[p << 1 | 1].r - tr[p << 1 | 1].l + 1) * laz % mod + mod) % mod;
        
        tr[p << 1].laz = (tr[p << 1].laz + laz + mod) % mod;
        tr[p << 1 | 1].laz = (tr[p << 1 | 1].laz + laz + mod) % mod;
        tr[p].laz = 0;
    }
}

void update(int p, int l, int r, int k){
    if(tr[p].l >= l && tr[p].r <= r){
        tr[p].sum = (tr[p].sum + (tr[p].r - tr[p].l + 1) * k % mod + mod) % mod;
        tr[p].laz = (tr[p].laz + k + mod) % mod;
        return ;
    }
    pushdown(p);
    int mid = (tr[p].l + tr[p].r) >> 1;
    if(l <= mid) update(p << 1, l, r, k);
    if(r > mid) update(p << 1 | 1, l, r, k);
    pushup(p);
}

ll query(int p, int l,int r){
    if(tr[p].l >= l && tr[p].r <= r) return tr[p].sum;
    pushdown(p);
    ll ans = 0;
    int mid = (tr[p].l + tr[p].r) >> 1;
    if(l <= mid) ans = (ans + query(p << 1, l, r)) % mod;
    if(r > mid) ans = (ans + query(p << 1 | 1, l, r)) % mod;
    return ans % mod;
}
struct node{
    int l, r;
}s[M];
int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    build(1, 1, n);

    for(int i = 1; i <= m; i ++){
        scanf("%d%d",&s[i].l,&s[i].r);
		s[i].l = min(s[i].l, n-1);
		s[i].r = min(s[i].r, n-1);
		cout<<"A: "<<s[i].l<<" "<<s[i].r<<endl;
		update(1, s[i].l, s[i].r, 1);
    }
    cout<<endl;
    
    ll ans = 0;
    for(int i = 1; i <= m; i ++){
        update(1, s[i].l, s[i].r, -1);
        int l = max(1,n - s[i].r), r = max(1,n - s[i].l);
        ans = (ans + query(1, l, r)) % mod;
        update(1, s[i].l, s[i].r, 1);
    }
    printf("%lld",ans);
    return 0;
}
/*
2 3
1 2
2 3
3 4
*/