#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

string s[N];
int sum[N], sg[N];
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> s[i];
    
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j < m; j ++){
            sum[i] += (s[i][j] == '1');
        }
    }

    int res = 0;
    if(m % 2 == 0){
        for(int i = 1; i <= n; i ++) res += (sum[i] - 2);
        if(res & 1) cout << "Alice";
        else cout << "Bob";
        return 0;
    }
    
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        if(s[i][m / 2] == '1'){
            int l = m / 2, r = m / 2;
            int flag = 0;
            while(l >= 0){
                if(s[i][-- l] == '1') flag |= 1;
                if(s[i][++ r] == '1') flag |= 2;
            }
            if(flag == 3){ // 除去中间木块，两边都有
                res += (sum[i] - 3);
                sum[i] = 3;
                cnt ++;
            }
            else{ // 有一边无木块，那最多是取到只剩中间木块
                res += (sum[i] - 1);
                sum[i] = 0;
            }
        } 
        else{ // 无中心木块，和情况一相同直接取
            res += (sum[i] - 2);
            sum[i] = 0;
        }
    }
	// printf("res = %d cnt = %d\n", res, cnt);
	if(res & 1){ // 当前情况对A有利
        if(cnt & 1) cout << "Alice"; // A先手直接将一个可以改变奇偶的行取两边，在总数奇偶不变的情况下cnt --
        else cout << "Alice"; // A不首先动可以改变奇偶的行，当B先做出行动，模仿其行动抵消
    }
    else{ // 当前情况对B有利
        if(cnt & 1) cout << "Alice";// A先手直接将一个可以改变奇偶的行取中间，改变总数奇偶的情况下cnt--
        else cout << "Bob"; // A任意时刻对改变奇偶的行进行操作B进行模仿即可抵消
    }
    return 0;
}
