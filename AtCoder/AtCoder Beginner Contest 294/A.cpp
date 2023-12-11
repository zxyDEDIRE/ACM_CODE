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
	srand(time(0));
	int n=1e7;
	for(int i=1;i<=n;i++){
		int x=rand()%INF;
		cout<<x<<" ";
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 freopen("C:\\Users\\tob\\Desktop\\int.txt","w",stdout);
	solve();
//  fclose(stdin);
 fclose(stdout);
	return 0;
}