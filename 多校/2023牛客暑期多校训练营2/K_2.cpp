// Problem: Box
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/57356/K
// Memory Limit: 524288 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e6 + 10;

ll f[N][3]; // 前i个box ，其第i个上有j个盖子的最大值
int n, a[N], b[N];

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) cin >> b[i];

    memset(f, -1, sizeof f);
    if(b[1]) f[1][1] = a[1];
    else f[1][0] = 0;

    for(int i = 2; i <= n; i ++){
        if(f[i - 1][0] != -1){
            if(b[i]){
                f[i][0] = max(f[i][0], f[i - 1][0] + a[i - 1]);
                f[i][1] = max(f[i][1], f[i - 1][0] + a[i]);
            }
            else{
                f[i][0] = max(f[i][0], f[i - 1][0]);
            }
        }
        if(f[i - 1][1] != -1){
            if(b[i]){
                f[i][1] = max(f[i][1], f[i - 1][1] + a[i]);
                f[i][2] = max(f[i][2], f[i - 1][1] - a[i - 1] + a[i]);
            }
            else{
                f[i][0] = max(f[i][0], f[i - 1][1]);
                f[i][1] = max(f[i][1], f[i - 1][1] - a[i - 1] + a[i]);
            }
        }   
        if(f[i - 1][2] != -1){
            if(b[i]){
                f[i][2] = max(f[i][2], f[i - 1][2] + a[i]);
            }
            else{
                f[i][1] = max(f[i][1], f[i - 1][2] + a[i]);
            }
        }
    }
    cout << max(f[n][0], f[n][1]);
	return 0;
}
