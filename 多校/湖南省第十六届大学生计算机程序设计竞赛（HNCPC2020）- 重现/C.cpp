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
const int mod=1e9+7;
const int M=1e6+100;
int F[M],INF[M];
string str;
int ksm(int b,int p){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
int C(int n,int m){
	return ((F[n]*INF[n-m])%mod*INF[m])%mod;
}
void solve()
{
	int cnt_1=0,cnt_2=0;
	int n=str.size();
	int res=0;
	for(int i=0;i<str.size();i++)
	{
		int c=(((n - 1) & i) == i);
		if(str[i]=='?')
		{
			if (c)cnt_1++;
			else cnt_2++;
		}
		else if(c&&str[i]=='1')res^=1;
	}
	int ans=ksm(2,cnt_2);
	if(cnt_1)
	{
		int sum=0;
		if(res){
			for(int i=0;i<=cnt_1;i+=2)
				sum=(sum+C(cnt_1,i))%mod;
		}
		else{
			for(int i=1;i<=cnt_1;i+=2)
				sum=(sum+C(cnt_1,i))%mod;
		}
		(ans*=sum)%=mod;
		res=1;
	}
	if(!res)cout<<0<<endl;
	else cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	F[0]=INF[0]=1;
	for(int i=1;i<M;i++)
	{
		F[i]=F[i-1]*i%mod;
		INF[i]=ksm(F[i],mod-2);
	}

	while(cin>>str)
		solve();

	return 0;
}
/*
10?100?1010?01?0101?
01?0101?0?0111101011010?01?00?0?1010?
0?1010?1011010?01?01?0
1010?01?0?0
?01?01011111010?01?
010?01?0011010?01?
11010?01?
0?01?0101?
01?0101?0?0111101011010?
?0111101011010?01?00?0?1010?
0?1010?101
*/