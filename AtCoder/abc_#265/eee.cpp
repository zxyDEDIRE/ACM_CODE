/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
#include <chrono>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;

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
void solve()
{
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}