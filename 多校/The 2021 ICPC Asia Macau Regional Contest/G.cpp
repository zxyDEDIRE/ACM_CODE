#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 110, inf = 1e9;

int n, k, p[N], idx[N];
int f[N][N]; // f[i]:拿到第i个数的最小花费，0：拿到第i个数时在1位置 1：在k位置


void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		cin >> p[i];
		idx[p[i]] = i;
		f[p[i]][i] = 0;
	}

	for(int i = 1; i <= k; i ++){

	}

	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= k; j ++){
			for(int l = 1; l <= k; l ++){
				f[i][l] = min(f[i][l], f[i - 1][j])
			}
		}
	}
	
}


int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t --){
		solve();
	}
	return 0;
}