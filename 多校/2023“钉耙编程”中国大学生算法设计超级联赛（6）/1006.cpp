#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")

#include <bits/stdc++.h>
using namespace std;

const int N = 310;
int pre[N], vis[N * N], sum[N], R[N * N];
void init(){
    for(int i = 1; i <= 300; i ++) vis[i * i] = 1;
    for(int i = 90000; i >= 1; i --){
        if(vis[i]) R[i] = i;
        else R[i] = R[i + 1];
    }
}
int a[N];
map<int, int> mp[N];
void solve(){
    int n=300;
    srand(time(0));
    // cin >> n;
    for(int i = 1; i <= n; i ++){
        // cin >> a[i];
        a[i]=rand()%299+1;
        assert(a[i]<=300&&a[i]>=1);
        mp[i].clear();
        sum[i] = 0;
        pre[i] = pre[i - 1] + a[i];
    }
    

   int ans = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = i; j <= n; j ++){
            if(vis[pre[j] - pre[i - 1]]){
                ans ++;
                sum[i] ++;
                sum[j + 1] --;
            }
            for(int k = i; k <= j; k ++){
                int num = pre[j] - pre[i - 1] - a[k];
                if(R[num] - num <= 300) mp[k][pre[j] - pre[i - 1] - a[k]] ++;
            }
        }
    }

    for(int i = 1; i <= n; i ++){ // 差分 每个点属于几个平方数区间
        sum[i] += sum[i - 1];
    }

    int lans = ans;
    for(int i = 1; i <= n; i ++){ // 枚举要改变的数的位置
        for(int j = 1; j <= 300; j ++){ // 枚举要变成的数
            if(j == a[i]) continue ;
            int res = ans - sum[i];
            for(int k = 1; k <= 300; k ++){ // 枚举平方数
                if(mp[i].count(k * k - j)){
                    res += mp[i][k * k - j];
                }
            }
            lans = max(lans, res);
        }
    }
    cout << lans << "\n";
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    init();

    int t;
    // cin >> t;
    t=5;
        clock_t start, finish;
    start = clock();
    while(t --){
    /*******代码*******/
    solve();
    /****************/
    }    
    finish = clock();
    cout << "the time cost is" <<\
    double(finish - start) / CLOCKS_PER_SEC;
    return 0;
}
