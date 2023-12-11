/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
string str;
void solve()
{
	cin>>str;
	int flag=0;
	int n=str.size();
	for(int i=1;i<n;i++)
	{
		if(str[i]!='?')flag=1;

		if(str[i]=='?'&&str[i-1]!='?')
			str[i]=str[i-1];
	}
	for(int i=n-1;i>=0;i--)
	{
		if(str[i]!='?')flag=1;
		if(str[i]=='?'&&str[i+1]!='?')
			str[i]=str[i+1];
	}
	if(flag==0)
		str=string(n,'1');
	cout<<str<<endl;
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
/*
2
????0????1????
1????0????1???
*/