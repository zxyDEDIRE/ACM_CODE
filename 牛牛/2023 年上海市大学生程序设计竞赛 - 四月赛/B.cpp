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
const int mod=1e9+7;
const int maxn=1e6+100;
string str[]={"01","1000","1010","100","0","0010","110",
"0000","00","0111","101","0100","11","10","111","0110",
"1101","010","000","1","001","0001","011","1001",
"1011","1100"};
map<string,char>mp;
ll dp[maxn][2];
string s;
int n;
void solve()
{
	cin>>s;s=" "+s;
	n=s.size()-1;
	for(int i=0;i<26;i++){
		mp[str[i]]=(char)(i+'a');
		// cout<<str[i]<<" "<<mp[str[i]]<<endl;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=min(4,i);j++)
		{	
			string now=s.substr(i-j+1,j);
			if(!mp.count(now))continue;
			char op=mp[now];
			// cout<<i<<" "<<j<<" "<<now<<" "<<op<<endl;
			if(op=='o')
			{
				(dp[i][1]+=dp[i-j][0]+dp[i-j][1])%=mod;
			}
			else if(op=='p')
			{
				(dp[i][0]+=dp[i-j][0])%=mod;
			}
			else
			{
				(dp[i][0]+=dp[i-j][0]+dp[i-j][1])%=mod;
			}
		}
	}
	cout<<(dp[n][0]+dp[n][1])%mod<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
123456789
---.--.
1110110
*/