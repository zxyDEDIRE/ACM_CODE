#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 5e3 + 10;

struct node{
	int w, v;
	bool operator < (const node& A)const{
		return w > A.w;
	}
}s[N];

int n, m;

ll f[N][N]; // 前 i 个物品丢掉总重量为 j 的物品的最小美丽值
ll pre[N];
void solve(){
	int n, W, k;
	cin >> n >> W >> k;
	for(int i = 1; i <= n; i ++){
		cin >> s[i].w >> s[i].v;
	}

	sort(s + 1, s + 1 + n);

	ll val = 0;
	for(int i = 1; i <= n; i ++){
		pre[i] = pre[i - 1] + s[i].w;
		val += s[i].v;
	}
	ll ans = 0;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	solve();
	return 0;
}
/*

*/