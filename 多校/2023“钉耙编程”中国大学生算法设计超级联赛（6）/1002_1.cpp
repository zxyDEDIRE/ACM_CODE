#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, MAX = 201000;

int sq[N], cnt;
vector<int> g[N];
void init(){
    for(int i = 2; i * i <= MAX; i ++){
        sq[++ cnt] = i * i;
    }
}

int a[N], idx[N], siz[N], len;

struct quer{
    int l, r, id;
}q[N];
bool cmp(const quer &A, const quer &B){
    int id1 = A.l / len, id2 = B.l / len;
    if(id1 != id2) return id1 < id2;
    if(id1 & 1) return A.r < B.r;
    return A.r > B.r;
}


int moans, ans[N];

void add(int l, int r, int id){
	int x = a[id];
    int idxl = lower_bound(g[x].begin(), g[x].end(), l) - g[x].begin();
    if(idxl >= siz[x] || g[x][idxl] > r) return ;
    int idxr = lower_bound(g[x].begin(), g[x].end(), r) - g[x].begin();
    if(idxr >= siz[x]) idxr --;
    moans += (idxr - idxl + 1);
}

void sub(int l, int r, int id){
	int x = a[id];
    int idxl = lower_bound(g[x].begin(), g[x].end(), l) - g[x].begin();
    if(idxl >= siz[x] || g[x][idxl] > r) return ;
    int idxr = lower_bound(g[x].begin(), g[x].end(), r) - g[x].begin();
    if(idxr >= siz[x]) idxr --;
    moans -= (idxr - idxl + 1);
}
int _a[110000];
int _cnt;
void solve(){
    int n, qi;
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        idx[a[i]] = i;
        g[i].clear();
    }

    for(int i = 1; i <= n; i ++){
        int l = lower_bound(sq + 1, sq + 1 + cnt, i) - sq;
        if(sq[l] == i) l ++;
        _cnt=0;
        for(int j = l; sq[j] - i <= n; j ++){
			if(sq[j] - i != i) {
                // g[i].push_back(idx[sq[j] - i]);
                _a[++_cnt]=(idx[sq[j] - i]);
            }
        }
        g[i].resize(_cnt);
        for(int j=0;j<_cnt;j++)
            g[i][j]=_a[j+1];
        sort(g[i].begin(), g[i].end());
        siz[i] = g[i].size();
    }

    cin >> qi;
    for(int i = 1; i <= qi; i ++){
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }

    len = sqrt(n);
    len = max(len, 1);
    sort(q + 1, q + 1 + qi, cmp);
	
	moans = 0;
    for(int i = 1, L = 1, R = 1; i <= qi; i ++){
        int l = q[i].l, r = q[i].r;
        while(R < r) add(L, R, ++ R);
        while(L > l) add(L, R, -- L);
        while(R > r) sub(L, R, R --);
        while(L < l) sub(L, R, L ++);
        ans[q[i].id] = moans;
    }

    for(int i = 1; i <= qi; i ++){
        cout << ans[i] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();

    int t;
    cin >> t;
    while(t --){
        solve();
    }    
    return 0;
}