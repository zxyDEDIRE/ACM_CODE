/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void solve()
{
  string s; cin >> s;
  int n = (int)s.size();
  int x = stoll(s);
  int ans = 0;
  for (int i = 1; i < n; i ++)
    if (n % i == 0)
    {
      int l = n / i;
      int now = stoll(s.substr(0, i));
      int now1 = now - 1; // 如果当前前缀周期单位数不满足要求，就考虑少1的周期数
      string pre = to_string(now); // 比如114514这个数可以114114
      string pre1 = to_string(now1); // 但是114110这个数只考虑113113
      string x1, x2; // 凑成完整与N位数相同的数
      for (int j = 0; j < l; j ++)
      {
        x1 += pre;
        x2 += pre1;
      }
      int y1 = stoll(x1); // 凑位结束后进行转换
      int y2 = stoll(x2); // 当然位数相同比较字典序也是一样的
      if (y1 <= x)
        ans = max(ans, y1);
      if (y2 <= x)
        ans = max(ans, y2);
    }
  int Max = stoll(string(n - 1, '9')); // 考虑奇位可以出现的 999...99
  cout << max(Max, ans) << '\n'; // 形如1111110这样的数都是 999...99
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}