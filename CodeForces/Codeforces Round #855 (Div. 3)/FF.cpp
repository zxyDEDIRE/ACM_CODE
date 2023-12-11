#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
const int N = 2e5 + 10, M = 1 << 26;
const int K = (1 << 26) - 1;//长度为26的全1二进制数
string s[N];
int t[N], val[M];//t[i]:转化后二进制数 val[i]:计数
vector<int>g[26];//g[i]:没有字符i的字符串的下标
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> s[i];
        int len = s[i].length();
        int vis[30] = {0};
        for(int j = 0; j < len; j ++){
            vis[s[i][j] - 'a'] ++;
        }
        int num = 0;
        for(int j = 0; j < 26; j ++){
            if(vis[j] & 1) num += (1 << j);
            if(!vis[j]) g[j].push_back(i);
        }
        t[i] = num;
    }
    
    ll ans = 0;
    for(int i = 0; i < 26; i ++){//枚举没有i字符的字符串，只有都没有某个字符的字符串才能匹配
        for(int id : g[i]){
            val[t[id]] ++;
            int v = t[id] ^ K ^ (1 << i);//能与si拼接的字符串所代表的二进制数
            ans += val[v];
        }
        for(int id : g[i]) val[t[id]] --;//清除贡献
    }
    cout << ans;
    return 0;
}
