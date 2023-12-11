#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define pii pair<ll, ll>
const ll maxn = 3e5 + 10;
const ll inf = 1e17 + 10;
vector<pii>v[maxn];
int pre[maxn];
ll n, m, q;
ll tr[maxn];
ll ans[maxn];
struct Node{
    int l,r,val;
}t[maxn<<2];
array<int,4>p[maxn];
void build(int rt,int l,int r){
    t[rt]={l,r,0};
    if(l==r)return ;
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
}
void update(int rt,int l,int k){
    if(t[rt].l==t[rt].r){
        t[rt].val+=k;
        return ;
    }
    int mid=(t[rt].l+t[rt].r)>>1;
    if(l<=mid)update(rt<<1,l,k);
    else update(rt<<1|1,l,k);
    t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
int query(int rt,int l,int r){
    if(l<=t[rt].l&&t[rt].r<=r){
        return t[rt].val;
    }
    int mid=(t[rt].l+t[rt].r)>>1;
    int ans=0;
    if(l<=mid)ans+=query(rt<<1,l,r);
    if(r>mid)ans+=query(rt<<1|1,l,r);
    return ans;
}
void add(int x,int k){update(1,x,k);}
int query(int x){return query(1,1,x);}
       
signed main()
{
    cin >> n >> m >> q;
    build(1,1,m+1);
    for(int i=1; i<=q; i++)
    {
        ll t, x, y, z;
        cin >> t >> x >> y;
        if(t == 1)
            cin >> z;
        else if(t == 2)
            pre[x] = i;
        else
            v[pre[x]].push_back({i, y});
        p[i]={t,x,y,z};
    }
    for(int i=1; i<=q; i++)
    {
        auto [t,x,y,z]=p[i];
        if(t == 1)
        {
            add(x, z);
            add(y + 1, -z);
        }
        else if(t == 2)
        {
            for
            for(int j=0; j<v[i].size(); j++)
            {
                int _x = v[i][j].first;
                int _y = v[i][j].second;
                ans[_x] = query(_y) - y;
                _x = 0;
            }
        }
        else
        {
            cout << query(y) - ans[i] << endl;
        }
    }
    return 0;
}
