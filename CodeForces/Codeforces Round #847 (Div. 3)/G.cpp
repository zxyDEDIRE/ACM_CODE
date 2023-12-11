#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define int long long
const int N = 200010;
string s;
vector<int>v;
int a[N], cnt, ans, op[N];
ll ksm(ll a, ll p){
	ll t = a ,res = 1 ;
	a = a % p ; 
	while(t){
		if(t & 1) res = res * a % p;
		a = a * a % p;
		t >>= 1 ;
	}
	return res % p;
}
void out(){
	for(int  i = 1; i <= cnt; i ++){
		printf("%d",a[i]);
		if(op[i] == 1) printf("+");
		else if(op[i] == 2) printf("-");
		else if(op[i] == 3) printf("#");
	}
	printf("=%d",ans);
	exit(0) ;
}
void dfs(int id, int res){
	if(id == cnt){
		if(res == ans) out();
		return ;
	}
	op[id] = 1;
	dfs(id + 1, res + a[id + 1]);
	op[id] = 2;
	dfs(id + 1, res - a[id + 1]);
	op[id] = 3;
	if(res && a[id + 1])
	if(res > 0 && a[id + 1] > 0) dfs(id + 1, ksm(res, a[id + 1]));
	return ;
}
signed main()
{
	cin >> s;
	int n = s.length();
	for(int i = 0; i < n; i ++){
		int num = 0;
		while(i < n && s[i] <= '9' && s[i] >= '0'){
			num = num * 10 + (s[i ++] - '0');
		}
		a[++ cnt] = num;
	}
	ans = a[cnt --];
	dfs(1, a[1]);
	puts("-1");
	return 0;
}