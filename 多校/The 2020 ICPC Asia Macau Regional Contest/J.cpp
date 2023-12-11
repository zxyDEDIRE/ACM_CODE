#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using Vec = vector<pii>;

const int N = 2e5 + 10;

int n, m, c[N], v[N];

struct node{
	int l, r, sum, ty_sum; // 珠宝数量， 珠宝种类的数量
	ll val; // 价值之和
	Vec max_sum;
}tr[N * 4];

int T[N];
struct seg{
	int ls, rs;
	ll val, max_v;
}t[N * 40];

void build(int p, int l, int r){
	// tr[p] = {l, r, 0, 0, 0};
	// tr[p].max_sum = vector<pii> (10, {0, 0});
	// if(l == r){
	// 	tr[p].
	// }
}
void solve()
{
		
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	solve();
	return 0;
}