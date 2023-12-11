/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
string s,t;
int n;
void solve()
{
	cin>>n>>s>>t;
	int num_a=0,num_b=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]!=t[i])num_a++;
		if(s[i]!=t[n-i-1])num_b++;
	}
	if(num_a==0){
		cout<<0<<endl;
		return ;
	}
	if(num_b==0){
		cout<<2<<endl;
		return ;
	}
	int ans=INF;

	if(num_a%2==0)
	{
		ans=min(ans,num_a*2);
	}
	else
	{
		ans=min(ans,num_a*2-1);
	}

	if(num_b%2==0)
	{
		ans=min(ans,num_b*2-1);
	}
	else
	{
		ans=min(ans,num_b*2);
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
1
5
ffcde
edcba
*/