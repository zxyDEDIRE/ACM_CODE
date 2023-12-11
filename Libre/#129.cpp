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
vector<string> duval(string const &s) {
    int n = s.size(), i = 0;
    vector<string> factorization;

    while (i < n) {
        int j = i + 1, k = i;

        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j])
                k = i;
            else
                k++;

            j++;
        }

        while (i <= k) {
            factorization.push_back(s.substr(i, j - k));
            i += j - k;
        }
    }

    return factorization;
}
// duval_algorithm
vector<int> duval2(string const &s) {
    int n = s.size(), i = 0;
    vector<int> factorization;

    while (i < n) {
        int j = i + 1, k = i;

        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j])
                k = i;
            else
                k++;

            j++;
        }

        while (i <= k) {
            i += j - k;
            factorization.push_back(i);

        }
    }

    return factorization;
}
void solve()
{
	string s;
    cin >> s;
    auto v = duval2(s);

    for (auto i : v) {
        cout << i << " ";
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