#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2010, mod = 1e9 + 7;

int f[N][N][4];
/*
2018 = 3
1009 = 2
2 = 1
1 = 0
*/
void solve(){

	int n = 2000;
	f[1][1][0] = 1;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			for(int )
		}
	}

}

int main()
{
	solve();
	int n, m;
	while(cin >> n >> m){
		ll ans = 0;
		for(int i = 0; i < 3; i ++){
			ans = (ans + f[n][m][i]) % mod;
		}
		cout << ans << "\n";
	}
	return 0;
}