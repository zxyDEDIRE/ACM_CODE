/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
string str;
int p[maxn];
int a[maxn];
int b[maxn];
int n,aa,bb;
void solve()
{
	cin>>n>>str;
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i-1];
		b[i]=b[i-1];
		if(str[i-1]=='(')a[i]++,p[i]=1,aa++;
		if(str[i-1]==')')b[i]++,p[i]=0,bb++;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{

	}

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

        solve();
    return 0;
}