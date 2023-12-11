/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int mod=998244353;
const int P=998244353;
const int maxn=1e6;
ll A[maxn],inv[maxn];
int pre[maxn];
string str;
int p[30];
void init()
{
	inv[1]=1;
	A[1]=1;
	for(int i=2;i<=1e6;i++)
	{
		inv[i]=(P-P/i)*inv[P%i]%P;
		A[i]=(A[i-1]*i)%P;
	}
}
void solve()
{
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		int x=str[i]-'a'+1;
		p[x]++;
		pre[p[x]]++;
	}
}
int main()
{	
	init();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}