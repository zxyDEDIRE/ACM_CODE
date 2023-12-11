#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 10;

int a[N];
void solve(){
    int n, m;
    cin >> n >> m;
	
	for(int i = 1; i <= n; i ++) cin >> a[i];
		
	int sum = 0, min_v = 1e9 + 10;
	for(int i = 1; i <= n; i ++){
		if(a[i] == 0) sum ++;
		else min_v = min(min_v, a[i]);
	}
	
    if(n == m){
        cout << "Richman\n";
        return ;
    }
	
    if(m == sum){
    	cout << min_v - 1 << "\n";
    	return ;
    }
	
	if(m < sum){
		cout << "Impossible\n";
		return ;
	}
	
	m -= sum;
	
    ll ans = 0, cnt = 0;

    int id = 0;
    for(int i = 1; cnt < m; i ++){
    	if(a[i] != 0) cnt ++; 
    	ans += a[i];
        id = i;
    }
	
	// printf("ans = %lld cnt = %lld\n", ans, cnt);
	min_v = 1e9 + 10;
	for(int i = id + 1; i <= n; i ++){
		if(a[i] != 0) min_v = min(min_v, a[i]);
	}
	if(min_v == 1e9 + 10) cout << ans << "\n";
	else cout << ans + (min_v - 1) << "\n";
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
