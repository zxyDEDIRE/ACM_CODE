/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int N = 1e6 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
struct node {
    int l, r;
    int val, key;
    int size;
} fhq[N];
int cnt, root;
std::mt19937 rnd(233);
int newnode(int val) {
    fhq[++cnt].val = val;
    fhq[cnt].key = rnd();
    fhq[cnt].size = 1;
    return cnt;
}
void update(int now) {
    fhq[now].size = fhq[fhq[now].l].size + fhq[fhq[now].r].size + 1;
}
void split(int now, int val, int &x, int &y) {
    if (!now) x = y = 0;
    else {
        if (fhq[now].val <= val) {
            x = now;
            split(fhq[now].r, val, fhq[now].r, y);
        } else {
            y = now;
            split(fhq[now].l, val, x, fhq[now].l);
        }
        update(now);
    }
}
int merge(int x, int y) {
    if (!x || !y) return x + y;
    if (fhq[x].key > fhq[y].key) {
        fhq[x].r = merge(fhq[x].r, y);
        update(x);
        return x;
    } else {
        fhq[y].l = merge(x, fhq[y].l);
        update(y);
        return y;
    }
}
int x, y, z;
void add(int val) {
    split(root, val, x, y);
    root = merge(merge(x, newnode(val)), y);
}
void del(int val) {
    split(root, val, x, z);
    split(x, val - 1, x, y);
    y = merge(fhq[y].l, fhq[y].r);
    root = merge(merge(x, y), z);
}
void getrank(int val) {
    split(root, val - 1, x, y);
    cout << fhq[x].size + 1 << "\n";
    root = merge(x, y);
}
void getnum(int rank) {
    int now = root;
    while (now) {
        if (fhq[fhq[now].l].size + 1 == rank) {
            break;
        } else if (fhq[fhq[now].l].size >= rank) now = fhq[now].l;
        else {
            rank -= fhq[fhq[now].l].size + 1;
            now = fhq[now].r;
        }
    }
    cout << fhq[now].val << "\n";
}
void pre(int val) {
    split(root, val - 1, x, y);
    int now = x;
    while (fhq[now].r) now = fhq[now].r;
    cout << fhq[now].val << "\n";
    root = merge(x, y);
}
void nxt(int val) {
    split(root, val, x, y);
    int now = y;
    while (fhq[now].l) now = fhq[now].l;
    cout << fhq[now].val << "\n";
    root = merge(x, y);
}
void run() {
    int opt, x;
    cin >> opt >> x;
    switch (opt) {
        case 1:
            add(x);
            break;
        case 2:
            del(x);
            break;
        case 3:
            getrank(x);
            break;
        case 4:
            getnum(x);
            break;
        case 5:
            pre(x);
            break;
        case 6:
            nxt(x);
            break;
    }
}
void solve()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int q,cnt=0,op;
    cin>>q;
    while(q--)
    {
        cin>>op;
        if(op==1)
        {
            cnt++;
            int x;
            cin>>x;
            add(x);
        }
        else
        {
            int x=(cnt+1)/2;
            getnum(x);
        }
    }
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
//  fclose(stdin);
//  fclose(stdout);
    return 0;
}