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
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p[maxn];
int n=20;
void solve()
{
	for(int i=1;i<=n;i++)
		p[i]=i-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)cout<<"  ";
		for(int j=i+1;j<=n;j++)
			cout<<__gcd(p[i],p[j])<<" ";
		cout<<endl;
	}

	for(int i=1;i<n;i++)
		cout<<__gcd(p[i],p[i]+1)<<" ";
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
n次
找到 x y z
*/