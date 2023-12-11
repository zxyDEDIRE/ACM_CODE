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
		int res = 0;
		// unordered_map<int,int>mp;
		bitset<100>mp;
		for(int i = 1; i <= n; i ++){
			if(j - p[i] > 0 && j-p[i]<=100 && mp.count(j - p[i])) {
				res += 2;
				mp.clear();
			}
			else mp[p[i]]++;
		}
		ans = max(ans, res);
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