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
	int n,s;
	cin>>n>>s;
	vector<int>v;
	int m=n;
	while(n!=0)
	{
		int x=n%s;
		if(x>=0)v.push_back(x),n/=s;
		else v.push_back(x-s),n=n/s+1;
	}
	reverse(v.begin(),v.end());
	cout<<m<<"=";
	for(auto i:v)
	{
		if(i<=9)cout<<i;
		else cout<<(char)(i-10+'A');
	}
	cout<<"(base"<<s<<")"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
+1 -2 +4 -8
2 / -2 =-1

0 -1

a*x=x*x x*x*x

*/