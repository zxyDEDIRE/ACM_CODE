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
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int dp[10][10];
int p[maxn];
string str;
int n;
bool check(int x,int y,int op)
{
	if(op==1)return x<y;
	if(op==2)return x>y;
	if(op==3)return x<y;
	if(op==4)return x>y;
	if(op==5)return x>y;
	if(op==6)return x>y;
	return 0;
}
void solve()
{
	cin>>str;
	n=str.size();
	for(int i=1;i<=n;i++)
		p[i]=str[i-1]-'0';
	for(int i=1;i<=n;i++)
	{
		dp[p[i]][0]++;
		for(int j=1;j<=6;j++)
		{
			for(int k=0;k<10;k++)
			{
				if(check(k,p[i],j))
				{
					dp[p[i]][j]+=dp[k][j-1];
					dp[p[i]][j]%=mod;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=9;i++)
		ans=(ans+dp[i][6])%mod;
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}