#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 10, inf = 1e9;

int a[N];
struct query{
    int l, r, idx;
}q[N];
int n, k, len, pre[N];
int son[N * 30][2], tot, id[N][2];

void insert(int x, int idx, int op){
	printf("x = %d idx = %d op = %d\n", x, idx, op);
    int p = 0;
    for(int i = 30; i >= 0; i --){
        int u = x >> i & 1;
        // printf("u = %d\n", u);
        if(!son[p][u]) son[p][u] = ++ tot;
        printf("p = %d\n", son[p][u]);
        p = son[p][u];
        // if(op & 1) id[p][0] = min(id[p][0], idx);
        // if(op & 2) id[p][1] = max(id[p][1], idx);
    }
}

void clear(int p){
    if(son[p][0]) clear(son[p][0]);
    if(son[p][1]) clear(son[p][1]);
    son[p][0] = son[p][1] = 0;
    id[p][0] = inf;
    id[p][1] = -inf;
}


void delet(int x, int idx){ // 删除向左增加的
    int p = 0;
    for(int i = 30; i >= 0; i --){
        int u = x >> i & 1;
        p = son[p][u];
        if(id[p][1] == idx) id[p][1] = -inf;
        son[p][u] = 0;
    }
}

int max_min(int x, int y, int op){
    if(!op) return min(x, y);
    return max(x, y);
}
int get_val(int p, int x, int cnt, int op){
    int u = k >> cnt & 1;
    int v = x >> cnt & 1;
    int ans = -inf;
    if(u){
        if(son[p][!v]) ans = get_val(son[p][!v], x, cnt - 1, op);
        if(son[p][v]) ans = max_min(ans, id[son[p][v]][op], op);
    }
    else{
        if(son[p][v]) ans =  get_val(son[p][!v], x, cnt - 1, op);
    }
    return ans;
}

int get(int x) { return x / len; }
bool cmp(query& A, query& B){
    int al = get(A.l), bl = get(B.l);
    if(al != bl) return al < bl;
    return A.r < B.r;
}


void add(int x, int& res, int op){
    int idx = get_val(0, pre[x], 30, !op);
    if(op == 1) insert(pre[x - 1], x, 3);
    else insert(pre[x - 1], x, 1);
    // res = max(res, abs(x - idx) + 1);
}

int ans[N];
int main(){
	int size(512<<20); // 512M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size)); // YOUR CODE
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < N; i ++){
        id[i][0] = inf;
        id[i][1] = -inf;
    }

    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }

    int qi;
    cin >> qi;
    for(int i = 1; i <= qi; i ++){
        int l, r;
        cin >> l >> r;
        q[i] = {l, r, i};
    }

    len = sqrt(n);
    sort(q + 1, q + 1 + qi, cmp);

    for(int i = 1; i <= qi; ){
        int j = i;
        while(j + 1 <= qi && get(q[j + 1].l) == get(q[i].l)) j ++;
        
        int right = get(q[i].l) * len + len - 1;
        while(i <= j && q[i].r <= right){
            int res = 0;
            auto [l, r, idx] = q[i ++];
            for(int p = l; p <= r; p ++) add(p, res, 1);
            ans[idx] = res;
            for(int p = l; p <= r; p ++) delet(pre[p - 1], p);
        }

        int res = 0;
        int R = right, L = R + 1;
        while(i <= j){
            auto [l, r, idx] = q[i ++];
            while(R < r) add(a[++ R], res, 1);
            int backup = res;
            while(L > 1) add(a[-- L], res, 0);
            ans[idx] = res;
            while(L < right + 1) delet(pre[L - 1], L ++);
            res = backup;
        }
        clear(0); tot = 0;
    }

    for(int i = 1; i <= qi; i ++) cout << ans[i] << "\n";
    	exit(0);
    return 0;
}
