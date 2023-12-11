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
char c[]={'1','R','O','Y','G','B','I','V'};
int n;
//ROYGBIV
void solve()
{
	cin>>n;
	int x=n/7;
	for(int i=1;i<=x;i++)
		for(int j=1;j<=7;j++)
			cout<<c[j];
	// cout<<endl;
	int y=n%7;
	switch(y)
	{
	case 1:cout<<"G"<<endl;break;
	case 2:cout<<"YG"<<endl;break;
	case 3:cout<<"OYG"<<endl;break;
	case 4:cout<<"ROYG"<<endl;break;
	case 5:cout<<"ROYGB"<<endl;break;
	case 6:cout<<"ROYGBI"<<endl;break;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
0
1
2
3
4
5
6

567 4 123
567 34 123
567 234 123
567 1234   123
567 12345 123
567 123456 123

*/