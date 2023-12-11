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
string str;
int n;
void solve()
{
	cin>>n>>str;
	int a=0;
	int len=0;
	int ma=0;
	for(auto i:str){
		if(i=='1')a++,len++;
		else len=0;
		ma=max(ma,len);
	}
	if(a&1){
		cout<<-1<<endl;
	}
	else if(a==2&&ma==2){
		if(str=="11"||str=="110"||str=="011")cout<<-1<<endl;
		else if(str=="0110")cout<<3<<endl;
		else cout<<2<<endl;
	}
	else cout<<a/2<<endl;
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
/*
0123
0110
1100
0101
5
3
101
6
101101
5
11111
6
000000
30
111011100110101100101000000111


11011

1100
0101
0000



0: 001100
1: 000101
2: 000000

00100


奇数：-1
偶数：
	2：连着的时候：特判
		没有连着：1
	其他：a/2
1100
0101
0000
11011

0110
11
*/