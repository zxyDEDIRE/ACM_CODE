#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 10;

int n, m, a[N], h[N], t[N], vis[4];

ll sum_h, pre[N][4];

bool check(ll x){
	ll sum[4] = {0};
	for(int i = 1; i <= 3; i ++){
		sum[i] += pre[n][i] * (x / n);
		sum[i] += pre[x % n][i];
	}

	if(sum[1] + sum[2] * 2LL + sum[3] * 3LL < sum_h) return false;

	for(int i = 1; i <= m; i ++){ // 将奇数的用3 / 1 减去
		t[i] = h[i];
		if(t[i] & 1){
			if(t[i] >= 3 && sum[3]){
				t[i] -= 3;
				sum[3] --;
			}
			else if(sum[1]){
				t[i] -= 1;
				sum[1] --;
			}
			else return false;
		}
	}

	if(!sum[3]) return true;

	for(int i = 1; i <= m; i ++){
		if(!t[i]) continue ;
		if(t[i] % 3 == 0){
			ll y = min(sum[3], 1LL * t[i] / 3);
			sum[3] -= y;
			t[i] -= y * 3;
		}
	}

	for(int i = 1; i <= m; i ++){
		if(!t[i]) continue ;
	}
}

void solve(){
	cin >> n;
	memset(vis, 0, sizeof vis);
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		for(int j = 1; j <= 3; j ++) pre[i][j] = 0;
		pre[i][a[i]] = 1;
		for(int j = 1; j <= 3; j ++) pre[i][j] += pre[i - 1][j];
	}

	cin >> m;
	sum_h = 0;
	for(int i = 1; i <= m; i ++){
		cin >> h[i];
		sum_h += h[i];
	}

	ll l = 1, r = sum_h;
	while(l <= r){
		ll mid = (l + r) >> 1;
		if(check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << l << "\n";
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