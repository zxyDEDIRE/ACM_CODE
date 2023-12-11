#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 25, M = (1 << 20), mod = 998244353;

ll ksm(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

ll ans[N][N], f[M];

int a[N][N];


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++) cin >> a[i][j];
	}
	
	f[0] = 1;
	for(int i = 0; i < (1 << n); i ++){
		int id = __builtin_popcount(i); // 已经选好菜的人数，现在是第id + 1个人选菜
		int sum = 0; // 还没被选的菜的喜好度之和
		for(int j = 0; j < n; j ++){
			if(!(i >> j & 1)){ // 还没被选的菜
				sum += a[id][j]; 
			}
		}
		for(int j = 0; j < n; j ++){
			if(i >> j & 1) continue ;
			ll pi = 1LL * a[id][j] * ksm(sum, mod - 2) % mod;
			ans[id][j] = (ans[id][j] + f[i] * pi % mod) % mod;
			f[i | (1 << j)] = (f[i | (1 << j)] + pi * f[i] % mod) % mod;
		}
	}

	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			cout << ans[i][j];
			if(j != n - 1) cout << " ";
		}
		if(i != n - 1) cout << "\n";
	}
	return 0;
}