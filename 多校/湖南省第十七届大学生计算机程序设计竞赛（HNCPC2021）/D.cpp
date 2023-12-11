 #include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7, N = 2e6 + 10; 
ll fact[N], infact[N];
ll ksm(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res % mod;
}
void init(){
	fact[0] = infact[0] = 1;
	for(int i = 1; i < N; i ++){
		fact[i] = fact[i - 1] * i % mod;
	}
	
	infact[N - 1] = ksm(fact[N - 1], mod - 2);
	
	for(int i = N - 1; i >= 1; i --){
		infact[i - 1] = infact[i] * i % mod;
	}
}
int n, m;
void solve(){
	ll ans = 0;
	for(int i = 1; i <= n; i ++){
		ll res = fact[i + m - 1] * infact[i - 1] % mod;
		ans = (ans + res) % mod;
	}
	cout << ans << "\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	init();
	while(cin >> n >> m)
		solve(); 
	return 0;
}
