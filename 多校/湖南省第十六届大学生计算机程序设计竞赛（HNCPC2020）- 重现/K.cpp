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
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
string str;
int n;
void solve()
{
	int res=1;
	int cnt=0;
	for(int i=n-1;i>=1;i--)
	{
		if(str[i]=='1'){
			if(i+1<n)
				res=(res*(i+cnt+1))%mod;
			cnt++;
		}
		else res=(res*cnt)%mod;
	}
	cout<<res<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>n>>str)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}