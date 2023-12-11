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
string str;
int p[maxn];
int n;
void solve()
{
	cin>>n>>str;str=" "+str;
	int a=0,b=0;
	int ans=1;
	int now=1;
	int len=1,t;
	for(int i=2;i<=n;i++)
	{
		int q;

		if(str[i]==str[i-1])
			now*=2,q=now;
		else now=1,q=1;
		now%=mod;
		ans+=q;
		ans%=mod;
	}


	cout<<ans<<endl;
}
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
/*
9
101101111

1

1*0
100

1*0*1
10011

1*0*1*1
1001111
1001101

1*0*1*1*0
100110100

1*0*1*1*0*1
10011010011

1*0*1*1*0*1*1
1001101001101
1001101001111

1*0*1*1*0*1*1*1
2*2

1*0*1*1*0*1*1*1*1
2*2*2

8 4 2 1 1 2 1 1 1 
*/