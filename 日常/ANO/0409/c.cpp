// Steins;Gate
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define lowbit(x) (x & -x)
using ll = long long;
using pii = pair<int, int>;
using pq = priority_queue<pii, vector<pii>, greater<pii>>;
#define endl '\n'
#define db(x) cerr << "debug: " << (x) << endl;
#define dg(x, y) cerr << "debug: " << (x) << ' ' << (y) << endl;


const int maxn=1e6;
int a[maxn];
int n,x,y;
int solve(int up,int down)
{
	ll res = 0;
		for (int l = 1, r = 1; r <= n; r++) {
			if (a[r] > up || a[r] < down)
				l = r + 1;
			res += r - l + 1;
		}
		return res;
}

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> n >> x >> y;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
	/*
	auto solve = [&](int up, int down) {
		ll res = 0;
		for (int l = 1, r = 1; r <= n; r++) {
			if (a[r] > up || a[r] < down)
				l = r + 1;
			res += r - l + 1;
		}
		return res;
	};*/
	cout << solve(x, y) - solve(x - 1, y) - solve(x, y + 1) + solve(x - 1, y + 1) << endl;

	return (0 ^ 0);
}