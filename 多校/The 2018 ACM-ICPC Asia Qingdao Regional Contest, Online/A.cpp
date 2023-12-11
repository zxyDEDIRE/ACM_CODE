#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

int n, m;
bool check(int mid){
	int t = m;
	t -= mid;

	int x = (t + (mid - 1)) / mid;
	return n - m >= x;
}

void solve(){
	cin >> n >> m;

	if(m == 0){
		cout << "0 0\n";
		return ;
	}

	int l = 1, r = m;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid - 1;
		else l = mid + 1;
	}

	cout << m << " " << l << "\n";
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