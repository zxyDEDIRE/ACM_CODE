#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using pii=pair<int,int>;

const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};


const int maxn = 1e6 + 10;
const int N = 1e3 + 10;

int mpa[N][N];
int mpb[N][N];
pii a[maxn];
pii b[maxn];
int f[maxn];

int n, m;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}

void merge(int x,int y){
	int fa=find(x);
	int fb=find(y);
	if(fa!=fb)f[fa]=fb;
}

bool same(int x,int y){
    if(x==0||y==0)return 0;
	int fa=find(x);
	int fb=find(y);
	if(fa==fb)return 1;
	return 0;
}

int siz[N];
int mp[N][N], col[N][N];

int st[N], l[N], r[N]; // l[i]:左边第一个小于自己的坐标
int L[N], R[N];

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n * m; i ++){
        f[i] = i;
        siz[i] = 0;
    }
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			cin >> mpa[i][j];
            a[mpa[i][j]] = {i, j};
        }
    }
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			cin >> mpb[i][j];
            b[mpb[i][j]] = {i, j};
        }
    }

	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			int now = mpa[i][j];
			for(int k = 0; k < 4; k ++){
				int x = i + dx[k];
				int y = j + dy[k];
				if(x < 1 || y < 1 || x > n || y > m)continue;
				auto [_x, _y] = b[now];
				if(mpa[x][y] == mpb[_x + dx[k]][_y + dy[k]]) merge(now,mpa[x][y]);
			}
		}
	}

    
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(same(mpa[i][j], mpa[i - 1][j])) col[i][j] = col[i - 1][j]+1;  // 每一列的前缀和
            else col[i][j]=1;
        }
    }

    ll ans = 1;
    for(int i = 1; i <= n; i ++){ // 枚举每一行
        for(int j=1;j<=m;j++)
            l[j]=r[j]=L[j]=R[j]=j;

        int cnt = 0;
        for(int j = m; j >= 1; j --){
            while(cnt && col[i][st[cnt]] > col[i][j]) l[st[cnt --]] = j+1;
            st[++ cnt] = j;
            if(same(mpa[i][j], mpa[i][j + 1])) R[j] = R[j + 1];
        }
        while(cnt)
            l[st[cnt--]]=1;


        cnt = 0;
        for(int j = 1; j <= m; j ++){
            while(cnt && col[i][st[cnt]] > col[i][j]) r[st[cnt --]] = j-1;
            st[++ cnt] = j;
            if(same(mpa[i][j], mpa[i][j - 1])) L[j] = L[j - 1];
        }
        while(cnt)
            r[st[cnt--]]=m;


        // cout<<"I "<<i<<endl;
        // for(int j=1;j<=m;j++)
        //     cout<<l[j]<<" ";cout<<endl;
        // for(int j=1;j<=m;j++)
        //     cout<<r[j]<<" ";cout<<endl;
        // for(int j=1;j<=m;j++)
        //     cout<<L[j]<<" ";cout<<endl;
        // for(int j=1;j<=m;j++)
        //     cout<<R[j]<<" ";cout<<endl;

        for(int j = 1; j <= m; j ++){
            int lt = max(l[j], L[j]);
            int rt = min(r[j], R[j]);
            ans = max(ans, 1LL * col[i][j] * (rt-lt+1));
            // cout<<"A"<<j<<" "<<col[i][j]<<" "<<col[i][j] * (rt-lt+1)<<" "<<lt<<" "<<rt<<endl;
        }
        // cout<<endl;
    }
    cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
    solve();
	return 0;
}
/*
3 3
1 2 3
8 9 4
7 6 5

1 2 3
4 9 8
7 6 5


3 3
1 2 3
4 5 6
8 7 9

5 6 1
7 9 3
2 4 8
*/
