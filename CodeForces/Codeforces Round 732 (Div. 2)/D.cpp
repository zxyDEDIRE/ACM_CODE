/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
const int M=1e5+10;
ll qmi(ll a, ll k)//快速幂模板
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (ll)res * a % mod;
        a = (ll)a * a % mod;
        k >>= 1;
    }
    return res;
}
ll C(ll a, ll b)//通过定理求组合数C(a, b)
{
    ll res = 1;
    for (int i = 1, j = a; i <= b; i ++, j -- )
    {
        res = (ll)res * j % mod;
        res = (ll)res * qmi(i, mod - 2) % mod;
    }
    return res;
}
ll lucas(ll a, ll b)
{
    if (a < mod && b < mod) return C(a, b);
    return (ll)C(a % mod, b % mod)*lucas(a / mod, b / mod) % mod;
}
void solve()
{
	int n;
	string str;
	cin>>n>>str;
	int cnt_1=0;
	int cnt_2=0;
	for(auto i:str)
		if(i=='0')cnt_1++;
	int len=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='1')
			len++;
		else
		{
			if(len)cnt_2+=(len/2);
			len=0;
		}
	}
	if(len)cnt_2+=len/2;
	cout<<lucas(cnt_1+cnt_2,cnt_2)<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}