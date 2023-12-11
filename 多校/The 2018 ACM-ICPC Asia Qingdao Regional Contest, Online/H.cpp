#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 10;

string s;
ll f[N][2]; // 在奇/偶时间到达i点红绿灯前的方案数
void solve(){
	cin >> s;
	int n = s.length();

	f[0][0] = 1;
	ll ans = 0;
	for(int i = 1; i <= n; i ++){
		f[i][0] = 1;
		f[i][1] = 0;
		if(s[i - 1] == '0'){
			ans += (f[i - 1][1] + 2LL * f[i - 1][0]) * (1LL * n - i + 1);
			f[i][0] += f[i - 1][0] + f[i - 1][1];
		}
		else{
			ans += (f[i - 1][0] + 2LL * f[i - 1][1]) * (1LL * n - i + 1);
			f[i][1] += f[i - 1][0] + f[i - 1][1];
		}
	}
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