/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
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
	int n=4;
	int p[10];
	for(int i=1;i<=n;i++)
		p[i]=i;
	int cnt=0;
	do{
		cnt++;
	}while(next_permutation(p+1,p+1+n));
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)
		p[i]=i;
	do{
		cout<<n<<endl;
		for(int i=1;i<=n;i++)
			cout<<p[i]<<" ";
		cout<<endl;
	}while(next_permutation(p+1,p+1+n));
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 freopen("C:\\Users\\tob\\Desktop\\a.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
 // fclose(stdin);
 fclose(stdout);
	return 0;
}