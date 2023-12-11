#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, MAX = 1e5;

int tr[2][N]; // 左端点前缀和  右端点前缀和
int rsum[N][3];
int  n, q;

void update(int id, int i, int w){
	while(i <= n){
		tr[id][i] += w;
		i += (i & -i);
	}
}

int get_sum(int id, int i){
	int ans = 0;
	while(i > 0){
		ans += tr[id][i];
		i -= (i & -i);
	}
	return ans;
}

void solve(){
	for(int i = 1; i <= n; i ++){
		tr[0][i] = tr[1][i] = 0;
		for(int j = 0; j < 3; j ++) rsum[i][j] = 0;
	}
	
	int sum = 0;
	for(int i = 1; i <= q; i ++){
		int op, l, r;
		cin >> op >> l >> r;
		if(op == 1){
			sum ++;
			update(0, l, 1);
			update(1, r, 1);

			for(int j = 0; j < 3; j ++){
				rsum[l][j] += (r - l == j);
			}
		}
		else
		{	
			int ans = sum;

			// 减去不相交的
			ans -= get_sum(1, l - 1);
			ans -= (sum - get_sum(0, r));

			if(l != r){
				// 减去相交的
				ans -= (get_sum(1, r - 1) - get_sum(1, l));
				ans -= (get_sum(0, r - 1) - get_sum(0, l));
				
				// 容斥 + 包含的
				for(int j = l + 1; j <= r - 1; j ++){
					for(int k = 0; k < 3; k ++){
						if(j + k < r) ans += rsum[j][k];
					}
				}
				// printf("ans4 = %d\n",ans);
				ans -= (rsum[l][0] + rsum[r][0]);
			}

			cout << ans << "\n";
		}
	}
}

int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0); cout.tie(0);
	while(cin >> n >> q){
		solve();
	}
	return 0;
}
/*
10 3
1 1 4
1 2 3
2 1 3
10 3
1 1 1
1 2 2
2 1 2
10 3
1 1 1
1 3 3
2 1 3
1 2
1 1 1
2 1 1
4 4
1 1 4
2 2 3
1 1 4
2 2 3


*/