#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <climits>
#include <functional>
#include <cassert>
#include <numeric>
#include <cstring>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define per(i, n) for(int i = (n) - 1; i >= 0; i--)
using ll = long long;
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define mod 998244353
using namespace std;
template<class T, class U>
bool chmax(T &a, const U &b){ return a < b ? (a = b, 1) : 0; }
template<class T, class U>
bool chmin(T &a, const U &b){ return a > b ? (a = b, 1) : 0; }
struct mint {
	ll x;
	mint(ll x = 0) : x((x + mod) % mod){}
	mint operator-() const{ return mint(-x); }
	mint operator+=(const mint &a){
		if((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint &operator++(){
		if(++x == mod) x = 0;
		return *this;
	}
	mint operator++(int){
		mint temp = *this;
		if(++x == mod) x = 0;
		return temp;
	}
	mint &operator-=(const mint &a){
		if((x -= a.x) < 0) x += mod;
		return *this;
	}
	mint &operator--(){
		if(--x < 0) x += mod;
		return *this;
	}
	mint operator--(int){
		mint temp = *this;
		if(--x < 0) x += mod;
		return temp;
	}
	mint &operator*=(const mint &a){
		(x *= a.x) %= mod;
		return *this;
	}
	mint operator+(const mint &a) const{ return mint(*this) += a; }
	mint operator-(const mint &a) const{ return mint(*this) -= a; }
	mint operator*(const mint &a) const{ return mint(*this) *= a; }
	mint pow(ll t) const{
		if(!t) return 1;
		mint res = 1, v = *this;
		while(t){
			if(t & 1) res *= v;
			v *= v;
			t >>= 1;
		}
		return res;
	}
	mint inv() const{ return pow(mod - 2); }
	mint &operator/=(const mint &a){ return (*this) *= a.inv(); }
	mint operator/(const mint &a) const{ return mint(*this) /= a; }
	bool operator==(const mint &a) const{ return x == a.x; }
	bool operator<(const mint &a) const{ return x < a.x; }
	bool operator>(const mint &a) const{ return x > a.x; }
	friend istream &operator>>(istream &is, mint &a){ return is >> a.x; }
	friend ostream &operator<<(ostream &os, const mint &a){ return os << a.x; }
};
struct FastIO {
	char tmp_s[20];
	#define gc getchar
	template <class T>
	inline void read(T &x){
		bool neg = false;
		int c = gc();
		while((c < '0' || c > '9') && c != '-') c = gc();
		if(c == '-') neg = true, c = gc();
		x = c^'0'; c = gc();
		while(c >= '0' && c <= '9') x = x*10 + (c^'0'), c = gc();
		if(neg) x = -x;
	}
	#undef gc
	#define pc putchar
	inline void out(int x){
		if(!x){ pc('0'); return; }
		if(x < 0){ pc('-'); x = -x; }
		char *t = tmp_s;
		while(x){
			int y = x / 10;
			*(t++) = (x - y*10) + '0';
			x = y;
		}
		while(t != tmp_s) pc(*(--t));
	}
	inline void out(ll x){
		if(!x){ pc('0'); return; }
		if(x < 0){ pc('-'); x = -x; }
		char *t = tmp_s;
		while(x){
			ll y = x / 10;
			*(t++) = (x - y*10) + '0';
			x = y;
		}
		while(t != tmp_s) pc(*(--t));
	}
	inline void out(const string &s){
		for(const char &c : s) pc(c);
	}
	#undef pc
	template <class T>
	friend FastIO &operator>>(FastIO &io, T &x){
		io.read(x);
		return io;
	}
	template <class T>
	friend FastIO &operator<<(FastIO &io, const T &x){
		io.out(x);
		return io;
	}
};
FastIO io;
#define cin io
#define cout io
#include <chrono>
template <class Key, int logn = 20>
struct HashSet {
	using uint = unsigned int;
	using ull = unsigned long long;
	private:
	static constexpr unsigned int N = 1 << logn;
	Key *keys;
	bitset<N> flag;
	ull r;
	static constexpr uint shift = 64 - logn;
	ull rng() const{
		ull m = chrono::duration_cast<chrono::nanoseconds>(
						chrono::high_resolution_clock::now().time_since_epoch())
						.count();
		m ^= m >> 16;
		m ^= m << 32;
		return m;
	}
	public:
	HashSet() : keys(new Key[N]), r(rng()){}
	void set(const Key &i){
		uint hash = (ull(i) * r) >> shift;
		while(true){
			if(!flag[hash]){
				keys[hash] = i;
				flag[hash] = 1;
				return;
			}
			if(keys[hash] == i) return;
			hash = (hash + 1) & (N - 1);
		}
	}
	bool find(const Key &i){
		uint hash = (ull(i) * r) >> shift;
		while(true){
			if(!flag[hash]) return false;
			if(keys[hash] == i) return true;
			hash = (hash + 1) & (N - 1);
		}
	}
};
ll d[3][2];
mint dp[2][301][301];
mint (*cur)[301] = dp[0], (*nxt)[301] = dp[1];
constexpr int inf = 1e9;
int main(){
	int n,m;
	cin >> n >> m;
	rep(i, 3) rep(j, 2) cin >> d[i][j];
	HashSet<ll> cnt;
	rep(i, m){
		ll y,x;
		cin >> y >> x;
		y += inf; x += inf;
		cnt.set(y << 32 | x);
	}
	cur[0][0] = 1;
	rep(i, n){
		for(int j = 0; j <= i; j++) for(int k = 0; j+k <= i; k++){
			if(cur[j][k] == 0) continue;
			const int l = i - j - k;
			const ll posy = d[0][0]*j + d[1][0]*k + d[2][0]*l + inf;
			const ll posx = d[0][1]*j + d[1][1]*k + d[2][1]*l + inf;
			if(!cnt.find((posy+d[0][0]) << 32 | (posx+d[0][1]))){
				nxt[j+1][k] += cur[j][k];
			}
			if(!cnt.find((posy+d[1][0]) << 32 | (posx+d[1][1]))){
				nxt[j][k+1] += cur[j][k];
			}
			if(!cnt.find((posy+d[2][0]) << 32 | (posx+d[2][1]))){
				nxt[j][k] += cur[j][k];
			}
		}
		swap(cur, nxt);
		memset(*nxt, 0, 301*301*sizeof(mint));
	}
	mint ans = 0;
	rep(i, n+1) for(int j = 0; i+j <= n; j++) ans += cur[i][j];
	cout << ans.x << "\n";
}