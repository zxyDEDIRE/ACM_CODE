#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 200010;
const int mod = 998244353;

struct Matrix {
	int v[3][3]; 
	Matrix(int t = 0) {
		memset(v, 0, sizeof v);
		if (t) {
			for (int i = 0; i < 3; i++) {
				v[i][i] = 1;
			}
		}
	}
	Matrix operator*(Matrix b) {
		Matrix res = 0;
		static unsigned long long tmp[3][3];
		memset(tmp, 0, sizeof tmp);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j <= i; j++) {  
				for (int k = 0; k <= i; k++) {
					tmp[i][j] += 1ull * v[i][k] * b.v[k][j];
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				res.v[i][j] = tmp[i][j] % mod;    
			}
		}
		return res;
	}
	Matrix operator&(Matrix b) {
		Matrix res = 0;
		for (int k = 0; k < 3; k++) {
			for (int j = 0; j < 3; j++) {
				(res.v[0][j] += 1ll * v[0][k] * b.v[k][j] % mod) %= mod;
			}
		}
		return res;
	}
	Matrix operator+(Matrix b) {
		Matrix res = *this;
		for (int i = 0; i < 3; i++) {
			(res.v[0][i] += b.v[0][i]) %= mod;
		}
		return res;
	}
} mat, one = 1;

struct Node {
	int l, r;
	Matrix tag, vec;
	bool f;
} tr[N << 2]; 

void pushup(int u) {
	tr[u].vec = tr[u << 1].vec + tr[u << 1 | 1].vec;
}

void build(int u, int l, int r) {
	tr[u].l = l, tr[u].r = r;
	tr[u].tag = 1;
	if (l == r) {
		tr[u].vec.v[0][0] = tr[u].vec.v[0][1] = 0;
		tr[u].vec.v[0][2] = 1;
		tr[u].f = false;
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void pushtag(int u, Matrix& mat) {
	tr[u].f = true;
	tr[u].vec = tr[u].vec & mat;
	tr[u].tag = tr[u].tag * mat;
}

void pushdown(int u) {
	if (tr[u].f) {
		pushtag(u << 1, tr[u].tag);
		pushtag(u << 1 | 1, tr[u].tag);
		tr[u].f = false;
		tr[u].tag = one;
	}
}

void modify(int u, int l, int r) {
	if (tr[u].l >= l && tr[u].r <= r) return pushtag(u, mat);
	int mid = tr[u].l + tr[u].r >> 1;
	pushdown(u);
	if (l <= mid) modify(u << 1, l, r);
	if (r > mid) modify(u << 1 | 1, l, r);
	pushup(u);
}

int query(int u, int l, int r) {
	if (tr[u].l >= l && tr[u].r <= r) return tr[u].vec.v[0][0];
	int mid = tr[u].l + tr[u].r >> 1, res = 0;
	pushdown(u);
	if (l <= mid) (res += query(u << 1, l, r)) %= mod;
	if (r > mid) (res += query(u << 1 | 1, l, r)) %= mod;
	return res; 
}

signed main() {
	freopen("C:\\Users\\tob\\Desktop\\in.txt","r",stdin);
	cin.tie(0)->sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	build(1, 1, n);
	for (int i = 0; i < q; i++) {
		int op, l, r, x;
		cin >> op >> l >> r;
		if (op == 0) {
			cin >> x;
			mat = 1;
			mat.v[1][0] = 1; 
			if (l > 1) modify(1, 1, l - 1);
			if (r < n) modify(1, r + 1, n);   
			mat = 1;
			mat.v[1][0] = mat.v[2][2] = 1;
			mat.v[2][0] = mat.v[2][1] = x;
			modify(1, l, r);
		} else {
			mat = 1;
			mat.v[1][0] = 1; 
			modify(1, 1, n);
			cout << query(1, l, r) << '\n';
		}
	}
	return 0;
}
/*
6 5
0 1 6 27392
0 6 6 30142
1 3 5
1 1 3
1 4 6

6 3
0 1 6 3
0 6 6 5
1 3 3
*/