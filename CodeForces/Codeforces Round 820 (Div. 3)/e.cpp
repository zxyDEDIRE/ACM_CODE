/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
// #define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
void solve()
{
	for(int i=1;i<=25;i++)
	{
		cout<<"? 1"<<" "<<i+1<<endl;
		int x;
		cin>>x;
		if(x==-1)
		{
			cout<<"! "<<i<<endl;
			return ;
		}
		cout<<"? "<<i+1<<" "<<1<<endl;
		int y;
		cin>>y;
		if(x!=y)
		{
			cout<<"! "<<x+y<<endl;
			return ;
		}
	}
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