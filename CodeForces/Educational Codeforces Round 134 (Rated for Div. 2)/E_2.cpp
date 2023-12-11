#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N = 1000020;
char s[N], t[11];

void calPi(char* t, int tlen, vector<int>& pi, int& j) {
	pi.resize(tlen+1, 0);
	for (int i = 1; i < tlen; i++) {
		while (j && t[j] != t[i]) {
			if (pi[j] <= j / 2 || t[i] == t[pi[j]])
				j = pi[j - 1];
			else j = pi[j % (j - pi[j]) + (j - pi[j])];
		}
		if (j || t[j] == t[i]) pi[i+1] = ++j;
		else pi[i+1] = 0;
	}
}

void calPi2(char* st, int slen, int tlen, int j, vector<int>& pi) {
	pi.resize(slen + tlen+1, 0);
	for (int i = slen; i < slen + tlen; i++) pi[i+1] = 0;

	for (int i = slen; i < slen + tlen; i++) {
		int cnt = 0;
		while (j && st[j] != st[i]) {
			if (pi[j] <= j / 2 || st[i] == st[pi[j]])
				j = pi[j];
			else j = pi[j % (j - pi[j]) + (j - pi[j])];
		}
		if (j || st[j] == st[i]) pi[i+1] = ++j;
		else pi[i+1] = 0;
	}
}

void solve() {
	scanf("%s", s);
	int slen = strlen(s);
	vector<int> pi;
	int j = 0;
	calPi(s, slen, pi, j);
	int q;
	scanf("%d", &q);

	while (q--) {
		scanf("%s", t);
		int tlen = strlen(t);
		for (int i = slen; i < slen + tlen; i++) s[i] = t[i - slen];
			calPi2(s, slen, tlen, j, pi);
		for (int i = slen; i < slen + tlen; i++) printf("%d ", pi[i+1]);
			puts("");

		s[slen] = '\0';
	}
}
signed main(){
// freopen("data.in","r",stdin);
// freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}
/*
sdfsfsfdfffsdfs
0 0 0 1 0 1 0 0 0 0 0 1 2 3 4
*/