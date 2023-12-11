#include <bits/stdc++.h>
using namespace std;

const int N = 210, M = 1e5 + 10;

int n, k, row[N][N], col[N][N];
bool check(int x, int y){
	int c = row[x][y];
	if(c == row[x + 1][y] && c == col[y][x] && c == col[y + 1][x]) return false;
	return true;
}
void solve(){
	cin >> n >> k;

	int sum = 2 * n * (n + 1);

	if(sum % k != 0 || n == 1 || k == 1){
		cout << "-1\n";
		return ;
	}

	int cnt = 1;
	for(int i = 1; i <= n + 1; i ++){ // 横行逐一递增赋值，保证同行相邻不同色
		for(int j = 1; j <= n; j ++, cnt ++){
			if(cnt > k) cnt %= k;
			row[i][j] = cnt;
		}
	}

	if(k > n){ // 如果 k > n，说明给行赋值时，任意相邻两行之间颜色不同，继续逐一递增赋值即可，一定不会有环 也可以保证同列颜色不完全相同
		for(int i = 1; i <= n + 1; i ++){
			for(int j = 1; j <= n; j ++, cnt ++){
				if(cnt > k) cnt %= k;
				col[i][j] = cnt;
			}
		}
	}
	else{
		for(int i = 1; i <= n + 1; i ++){ // 首先隔列倒转，能避免相邻列颜色的一样的情况
			for(int j = 1; j <= n; j ++, cnt ++){
				if(cnt > k) cnt %= k;
				if(i & 1) col[i][j] = cnt;
				else col[i][n - j + 1] = cnt;
			}
			if((k & 1) && (i & 1)){ // 如果k是奇数，中间那个数隔列倒转也会相同，于是将其与下一个交换一下避免成环
				for(int j = k / 2 + 1; j <= n; j += k){
					swap(col[i][j], col[i][j + 1]);
				}
			}
		}
	}

	for(int i = 1; i <= n + 1; i ++){
		int flag = 0;
		for(int j = 2; j <= n; j ++){
			if(row[i][j] != row[i][j - 1]){
				flag = 1;
				break;
			}
		}
		if(!flag){
			assert(false);
			cout << "REr" << "\n";
			return ;
		}
		flag = 0;
		for(int j = 2; j <= n; j ++){
			if(col[i][j] != col[i][j - 1]){
				flag = 1;
				break;
			}
		}
		if(!flag){
			assert(false);
			cout << "REc" << "\n";
			return ;
		}
	}

	for(int i = 1; i < n + 1; i ++){
		for(int j = 1; j <= n; j ++){
			if(!check(i, j)){
				assert(false);
				cout << "RE2" << "\n";
				return ;
			}
		}
	}
	for(int i = 1; i <= n + 1; i ++){
		for(int j = 1; j <= n; j ++){
			cout << row[i][j] << " ";
		}
		cout << "\n";
	}  
	for(int i = 1; i <= n + 1; i ++){
		for(int j = 1; j <= n; j ++){
			cout << col[i][j] << " ";
		}
		cout << "\n";
	}  
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t --){
		solve();
	}
	return 0;
}
