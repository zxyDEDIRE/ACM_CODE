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
int n,x;
void solve()
{
	cin>>n>>x;
	int flag=0,fl=0;
	int s=n;
	for(int i=0;i<=62;i++)
	{
		int a=(s&(1ll<<i));
		int b=(x&(1ll<<i));
		if(!a&&b){cout<<-1<<endl;return ;}
		if(a==1&&b==1)flag=1;
		if(a==1&&b==0&&flag){cout<<-1<<endl;return ;}
		if(a&&!b)fl=1;
		if(!a&&fl)
		{
			n&=(((1ll<<61)-1)^((1ll<<i)-1));
			fl=0;
			s=(s&(((1ll<<61)-1)^((1ll<<i)-1)))|(1ll<<i);
		}
	}
	if(n==x)cout<<s<<endl;
	else cout<<-1<<endl;
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
1010
1000
*/