#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);
#define int long long
typedef long long ll;
typedef pair<int,int> P;
const int N = 600 + 10;
char a[N][N];
int f[2][N][N],g[N][N],n,m;

int DP1(int x,int y,int typ) {
    if (x > n || y > m) return -1;

    if (a[x][y] != '.') {
        if (a[x][y] == 'A') return 1;
        else return 0;
    }
    if (x == n && y == m) return 0;

    if (f[typ][x][y] != -1) return f[typ][x][y];

    int nxt1 = DP1(x+1,y,1 - typ),nxt2 = DP1(x,y+1,1-typ);
    if (nxt1 == -1 || nxt2 == -1) {
        if (nxt1 == -1) return f[typ][x][y] = nxt2;
        else return f[typ][x][y] = nxt1;
        return f[typ][x][y];
    }
    if (!typ) return f[typ][x][y] = nxt1 | nxt2;
    else return f[typ][x][y] = nxt1 & nxt2;
    return -1;
}

int DP2(int x,int y,int typ) {
    if (x > n || y > m) return -1;

    if (a[x][y] != '.') {
        if (a[x][y] == 'A') return 0;
        else return 0;
    }
    if (x == n && y == m) return 1;

    if (f[typ][x][y] != -1) return f[typ][x][y];

    int nxt1 = DP2(x+1,y,1 - typ),nxt2 = DP2(x,y+1,1-typ);
    if (nxt1 == -1 || nxt2 == -1) {
        if (nxt1 == -1) return f[typ][x][y] = nxt2;
        else return f[typ][x][y] = nxt1;
        return f[typ][x][y];
    }
    if (!typ) return f[typ][x][y] = nxt1 | nxt2;
    else return f[typ][x][y] = nxt1 & nxt2;
    return -1;
}

int DP3(int x,int y,int typ) {
    if (x > n || y > m) return -1;

    if (a[x][y] != '.') {
        if (a[x][y] == 'A') return 0;
        else return 1;
    }

    if (x == n && y == m) return 0;
    if (f[typ][x][y] != -1) return f[typ][x][y];

    int nxt1 = DP3(x+1,y,1 - typ),nxt2 = DP3(x,y+1,1-typ);
    if (nxt1 == -1 || nxt2 == -1) {
        if (nxt1 == -1) return f[typ][x][y] = nxt2;
        else return f[typ][x][y] = nxt1;
        return f[typ][x][y];
    }
    if (!typ) return f[typ][x][y] = nxt1 | nxt2;
    else return f[typ][x][y] = nxt1 & nxt2;
    return -1;
}

void solve() {
    scanf("%d %d\n",&n,&m);
    for (int i = 1;i <= n;++i) scanf("%s",a[i]+1);
    memset(f,-1,sizeof f);int ans1 = DP1(1,1,0);
    memset(f,-1,sizeof f);int ans2 = DP2(1,1,0);
    memset(f,-1,sizeof f);int ans3 = DP3(1,1,0);
    if (ans1) printf("yes ");
    else printf("no ");
    if (ans2) printf("yes ");
    else printf("no ");
    if (ans3) puts("yes");
    else puts("no");
}

signed main() {
    int T;scanf("%d",&T);
    while (T--) solve();
	return 0;
}