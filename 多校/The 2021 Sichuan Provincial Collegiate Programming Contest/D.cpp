#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ans;

void get(ll& p, ll& q, ll val){
	if(!p || !q) return ;

	ll sum = min(p, q);
	p -= sum;
	q -= sum;
	ans += sum * val;
}

void solve(){
	ll a, b, c;
	ll x, y, z;
	cin >> a >> b >> c;
	cin >> x >> y >> z;

	ans = 0;
	get(a, y, 1);
	get(a, x, 0);
	get(a, z, -1);
	// cout << "ans1 = " << ans << "\n";

	get(b, z, 1);
	get(b, y, 0);
	get(b, x, -1);
	// cout << "ans2 = " << ans << "\n";

	get(c, x, 1);
	get(c, z, 0);
	get(c, y, -1);

	cout << ans << "\n";
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