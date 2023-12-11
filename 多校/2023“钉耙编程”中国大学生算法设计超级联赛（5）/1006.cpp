#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e5 + 10;

int f[N][4][4]; // 0,1,2,3 分别代表无色，R,G,B 的最大分数 前i个ufo 且此时包1,2的颜色为j,k的最大分数
void solve(){
    string s;
    cin >> s;
    int n = s.length();

    memset(f, -1, sizeof f);
    f[0][0][0] = 0;
    for(int i = 0; i < n; i ++)
    {
        int ch = 0;
        if(s[i] == 'R') ch = 1;
        else if(s[i] == 'G') ch = 2;
        else ch = 3;

        // 本次的ufo丢弃
        for(int j = 0; j <= 3; j ++){ 
            for(int k = 0; k <= 3; k ++){
                f[i + 1][j][k] = f[i][j][k];
            }
        }

        // 本次的ufo拾取
        f[i + 1][ch][0] = max(f[i + 1][ch][0], f[i][0][0]); // 若是-1取max也不会影响结果 所以不用判断状态是否有效
        for(int j = 1; j <= 3; j ++){
            f[i + 1][j][ch] = max(f[i + 1][j][ch], f[i][j][0]);
        }

        if(f[i][ch][ch] != -1){ // 集齐三种同样的颜色
            for(int j = 1; j <= 3; j ++){ // 兑换成j颜色
                f[i + 1][j][0] = max(f[i + 1][j][0], f[i][ch][ch] + 1);
            }
        }

        for(int j = 1; j <= 3; j ++){
            for(int k = 1; k <= 3; k ++){
                if(j != k && j != ch && k != ch){ // 集齐三种不同颜色, 同样本次不得分就不需要判断是否为-1
                    for(int p = 1; p <= 3; p ++){ // 兑换两个p颜色
                        f[i + 1][p][p] = max(f[i + 1][p][p], f[i][j][k]);
                    }
                }
                else if((j != k || j != ch || k != ch) && (j == k || j == ch || k == ch)){ // 有两种颜色一样
                    f[i + 1][k][ch] = max(f[i + 1][k][ch], f[i][j][k]); // 丢弃包1的j 将包2的k转移到包1 将ch放入包2
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= 3; i ++){
        for(int j = 0; j <= 3; j ++){
            ans = max(ans, f[n][i][j]);
        }
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
/*
1
RGBRRRRR
 RRRRRRR 1
   RRRRR 1
     RRR 1
*/