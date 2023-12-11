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
int dp[111];
string s,t;
int n,m;
void solve()
{
	cin>>s>>t;
	n=s.size();
	m=t.size();
	int ma=0;
	for(int i=0;i<n;i++)
		dp[i]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int len=0;
			while(i+len<n&&j+len<m&&s[i+len]==t[j+len])
				len++;
			if(len>dp[i])
			{
				dp[i]=len;
			}
		}
		ma=max(ma,dp[i]);
	}
	// cout<<"ma "<<ma<<endl;
	if(ma==0){
		cout<<"No"<<endl;
		return ;
	}
	else if(ma==1)
	{
		if(s[0]==t[0])
			cout<<"Yes\n"<<s[0]<<"*"<<endl;
		else if(s.back()==t.back())
			cout<<"Yes\n*"<<s.back()<<endl;
		else cout<<"No"<<endl;
	}
	else
	{
		cout<<"Yes"<<endl;
		cout<<"*";
		for(int i=0;i<n;i++)
			if(dp[i]==ma)
			{
				for(int j=0;j<dp[i];j++)
					cout<<s[i+j];
				cout<<"*\n";
				break;
			}
	}
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
cocodeforces
atcocoder

a b
cadbe
zaybt
*/