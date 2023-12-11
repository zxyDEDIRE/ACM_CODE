/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
ll a,b,c,x,t;
bool A()
{
	int x=b-c;
	int d=2*b-a;
	int len=t-x;
	if((len)%d==0&&(len/d)>=0)return 1;
	else return 0;
}
bool B()
{
	int x=a+c-2*b;
	int d=a-2*b;
	int len=t-x;
	if(len%d==0&&(len/d)>=0)return 1;
	else return 0;
}
bool C()
{
	int x=a-b-c;
	int d=a-2*b;
	int len=t-x;
	if(len%d==0&&(len/d)>=0)return 1;
	else return 0;
}
bool D()
{
	int x=c;
	int d=2*b-a;
	int len=t-x;
	if(len%d==0&&(len/d)>=0)return 1;
	else return 0;
}
void solve()
{
	cin>>a>>b>>c>>t;
	if(b==c)cout<<"Yes"<<endl;
	else if(A())cout<<"Yes"<<endl;
	else if(B())cout<<"Yes"<<endl;
	else if(C())cout<<"Yes"<<endl;
	else if(D())cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
signed main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}