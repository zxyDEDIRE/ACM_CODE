#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
using namespace std;
#define LL long long

const int N = 500005;
int T, n, trie[N][26], tot, cnt[N], color[N], ed[N];
LL ans;
map<int, vector<string>> s;
map<int, int> used;
bool ban[N], no;

void insert(int co, string &str){
	int p = 0;
	used[p]++;
	for (int i = 0; i < str.length(); i++){
		int ch = str[i] - 'a';
		if (!trie[p][ch])
			trie[p][ch] = ++tot;
		p = trie[p][ch];
		used[p]++;
	}
	ed[p] = co;
}

void solve(int co, vector<string> &vec){
	used.clear();
	for (string &str: vec)
		insert(co, str);
	int gg = used[0];
	for (auto [x, y]: used){
		if (y < gg) ban[x] = true;
		cnt[x]++;
		if (cnt[x] == 1)color[x] = co;
	}
}

void dfs(int p){
	if (cnt[p]>1){
		ans++;
	}
	int gg=(bool)ed[p],flag=ed[p];
	for (int i=0;i<26&&!no;i++){
		int q=trie[p][i];
		if(q)
		{
			if(!ban[q]){
				if(cnt[q]==1)gg++;
				else if(cnt[q]>1)dfs(q);
			}
			else{
				if(cnt[q]>1||flag!=color[q]&&flag){
					no=true;
					break;
				}
				else{
					if(!flag)gg++;
					flag=color[q];
				}
			}
		}
	}
	if (gg){
		ans += gg - 1;
		cout<<"ans "<<ans<<" "<<gg<<endl;
	}
}

inline void init(){
	s.clear();
	for (int i = 0; i <= tot; i++){
		color[i] = ban[i] = ed[i] = cnt[i] = 0;
		for (int j = 0; j < 26; j++){
			trie[i][j] = 0;
		}
	}
	ans = tot = 0;
	no = false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	int tmp = 0;
	while (T--){
		cout << "Case #" << ++tmp << ": ";
		init();
		cin >> n;
		string str;
		int x;
		map<string, int> val;
		bool flag = false;
		for (int i = 1; i <= n; i++){
			cin >> str >> x;
			if (val.find(str) != val.end()){
				if (val[str] != x){
					no = true;
				}
				continue;
			}
			val[str] = x;
			s[x].push_back(str);
		}
		for (auto &[x,vec]: s)
			solve(x, vec);
		
		if (cnt[0] <= 1) ans = 1;
		else dfs(0);
		
		if (no) cout << -1 << endl;
		else cout << ans << endl;
	}

	return 0;
}
															