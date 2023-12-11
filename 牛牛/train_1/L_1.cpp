#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define ll long long
ll a[N], b[N];
ll sum[N];
char s[N];
ll k;
int num;
int n;

bool check(int x) {
	for (int l = 1; l + x - 1 <= num; l++) {
		int r = min(x + l - 1, num);
		int mid = (l + r) / 2;
		ll all = b[mid] * (mid - l + 1ll) - (sum[mid] - sum[l - 1]);
		all += (sum[r] - sum[mid - 1]) - b[mid] * (r - mid + 1);
		if (all <= k) {
			return 1;
		}
	}
	return 0;
}

void solve() {
	cin>>n>>k>>s+1;
	num=0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '6') {
			a[++num] = i;
		}
	}

	for (int i = 1; i <= num; i++) {
		b[i] = a[i] - i;
	}
   
	for (int i = 1; i <= num; i++) {
		sum[i] = sum[i - 1] + b[i];
	}
	int l = 0, r = N;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l << endl;
}
int main() {
	solve();
}
