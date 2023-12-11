/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
string f(int x)
{
	char a=('a'+x%26-1);
	if(a=='`')a='z';
	// cout<<x<<" "<<a<<endl;
	string y="";y=y+a;
	if(x>26)return f(x/26)+y;
	else return y;
}
void solve()
{
	// cout<<f(26)<<endl;
	cin>>n>>str;
	int ans=1;

	for(int i=1;i;i++)
	{
		string a=f(i);
		// cout<<a<<endl;
		if(str.find(a)==string::npos)
		{
			cout<<a<<endl;
			return ;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	// cout<<f(26*26)<<endl;
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}