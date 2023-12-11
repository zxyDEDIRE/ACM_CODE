#include<bits/stdc++.h>
using namespace std;

int w[10010], fa[10010], d[10010];//静态数组比动态数组快

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);//加了快一点
    //输入点的权值
    int n, f = 1;
    while(cin >> n){
        if(f) f = 0;
        else cout << '\n';//数据组之间的一个换行
        // vector<int> w(n), fa(n), d(n);
        for(int i = 0; i < n; i++) cin >> w[i], fa[i] = d[i] = i;
        //函数区
        function<int(int)> find;
        find = [&](int x){
            if(x == fa[x]) return x;
            return fa[x] = find(fa[x]);
        };
        auto Vmax = [&](int a, int b){
            if(w[a] == w[b]) return min(a, b);//返回小编号
            else if(w[a] > w[b]) return a;
            else return b;
        };
        auto Vmin = [&](int a, int b){
            return a + b - Vmax(a, b);//反一下就行
        };
        //输入边
        unordered_map<int, int> ump;
        int m, sk = 10010; cin >> m;
        for(int i = 0, a, b; i < m; i++){
            cin >> a >> b;
            if(a > b) swap(a, b);
            ump[a * sk + b] = 1;
        }
        //输入问题
        vector<pair<int, int>> Q;
        int k; cin >> k;
        for(int i = 0; i < k; i++){
            int a, b = -1; string s; cin >> s >> a;
            if(s[0] == 'd'){
                cin >> b;
                if(a > b) swap(a, b);
                ump[a * sk + b] = 0;
                Q.push_back({a, b});
            }else Q.push_back({a, -1});
        }
        reverse(Q.begin(), Q.end());
        //加边（去掉被“摧毁的边”）
        for(auto [k, v] : ump){
            if(!v) continue;
            int a = k / sk, b = k % sk;
            int pa = find(a), pb = find(b);
            if(pa == pb) continue;

            fa[pa] = pb;
            d[pb] = Vmax(d[pb], d[pa]);
        }
        //对问题进行回答
        vector<int> ans;
        for(auto [a, b] : Q){
            if(b == -1){
                int pa = find(a);
                if(w[d[pa]] > w[a]) ans.push_back(d[pa]);//a所在的连通图里，有比a权值大的点
                else ans.push_back(-1);//a所在的连通图里，a是权值最大的
            }else{
                int pa = find(a), pb = find(b);
                if(pa == pb) continue;
                fa[pa] = pb;
                d[pb] = Vmax(d[pb], d[pa]);
            }
        }
        for(auto i = ans.rbegin(); i != ans.rend(); i++) cout << *i << '\n';
    }
    return 0;
}
