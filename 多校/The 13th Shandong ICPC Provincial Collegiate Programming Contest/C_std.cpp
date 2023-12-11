#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 10;
string s;
int n, m, x;
int rnk[maxn];
bool ok[maxn];
vector<pair<int, int>> e[maxn];
vector<pair<vector<int>, int>> v[maxn];
vector<int> dep[maxn];
inline void dfs(int u, int d)
{
    dep[d].push_back(u);
    for (auto x : e[u])
        dfs(x.first, d + 1);
}
inline bool cmp(pair<vector<int>, int> &x, pair<vector<int>, int> &y)
{
    for (int i = 0; i < x.first.size() && i < y.first.size(); i++)
    {
        if (x.first[i] != y.first[i])
            return x.first[i] < y.first[i];
    }
    return x.first.size() > y.first.size();
}
char ans[maxn];
inline void dfs2(int u, int fa)
{
    vector<pair<int, int>> v;
    for (auto x : e[u])
    {
        dfs2(x.first, u);
        v.push_back({rnk[x.first], x.first});
    }
    sort(v.begin(), v.end());
    int now = 0;
    for (auto x : v)
    {
        ans[x.second] = char('a' + now);
        now++;
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        e[i].clear(), dep[i].clear();
        ok[i] = 0, rnk[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        e[x].push_back({i, -1});
    }
    dfs(0, 0);
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        ok[x] = 1;
    }
    for (int i = n; i >= 0; i--)
    {
        vector<pair<vector<int>, int>> vec;
        if (dep[i].size() == 0)
            continue;
        for (auto x : dep[i])
        {
            vector<int> c;
            if (ok[x])
                c.push_back(0);
            for (auto y : e[x])
                c.push_back(rnk[y.first]);
            sort(c.begin(), c.end());
            vec.push_back({c, x});
        }
        sort(vec.begin(), vec.end(), cmp);
        int now = 1;
        int l = vec.size();
        for (int j = 0; j < l; j++)
        {
            rnk[vec[j].second] = now;
            if (j + 1 < l && vec[j].first != vec[j + 1].first)
                now++;
        }
        cout<<"dep: "<<i<<endl;
        for(auto [x,y]:vec){
            cout<<y<<" "<<rnk[y]<<" ";
            for(auto I:x)
                cout<<I;
            cout<<endl;
        }
    }
    dfs2(0, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i];
    cout << '\n';
}
signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
/*
1 
7 5
0 0 1 1 2 2 3
3 4 5 6 7
*/