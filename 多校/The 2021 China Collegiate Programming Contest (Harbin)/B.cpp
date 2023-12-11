#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn = 1e5+100;

int n, p[maxn], f[maxn], last[210];
void solve(){
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> p[i];
	
	int ans = 0;
	for(int j = 2; j <= 200; j ++){
		for(int i = 0; i <= n; i ++) f[i] = 0;
		for(int i = 0; i <= 100; i ++) last[i] = 0;
		
		for(int i = 1; i <= n; i ++){
			if(j - p[i] > 0 && j - p[i] <= 100 && last[j - p[i]]){
				f[i] = f[last[j - p[i]] - 1] + 2;
			}
			last[p[i]] = i;
			f[i] = max(f[i], f[i - 1]);
		}
		ans = max(ans, f[n]);
	}
	cout << ans << "\n";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
		solve();
	return 0;
}