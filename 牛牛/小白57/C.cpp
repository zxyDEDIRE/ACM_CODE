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
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int n,k,a,b;
void solve()
{
	cin>>n>>k>>a>>b;
	if(a==b){
		cout<<"YES"<<endl;
		return ;
	}
	if(max(a-1,n-a)>k&&max(b-1,n-b)>k)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
/*
1
30 15 10 20
*/
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}