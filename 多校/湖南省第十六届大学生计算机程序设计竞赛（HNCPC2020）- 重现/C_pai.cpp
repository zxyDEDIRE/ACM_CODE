#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
const int mod=1e9+7;
const int M=1e6+100;
const int N = 1e6 + 10;
int F[M],INF[M];
int ksm(int b,int p){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
int C(int n,int m){
	return ((F[n]*INF[n-m])%mod*INF[m])%mod;
}
char s[N];
int f[N][2][2];
bool get(int n, int m){ // 判断组合数奇偶性
    return ((n & m) == m);
}
int solve(string str){
    int n = str.size();
    for(int i=1;i<=n;i++)
    	s[i]=str[i-1];
     
    for(int i = 0; i <= n; i ++){
        for(int j = 0; j < 2; j ++){
            for(int k = 0; k < 2; k ++) f[i][j][k] = 0;
        }
    }
 
    f[0][0][0] = 1;
    for(int i = 1; s[i]; i ++){
        int odev = get(n - 1, i - 1);
 
        // 当前为1或由？变成1，若当前位出现的次数为奇数，那么就能改变前i个的奇偶性，0 -> 1，1 -> 0，否则只能直接转移
        if(s[i] == '1' || s[i] == '?'){
            f[i][1][1] = (f[i - 1][1][odev ^ 1] + f[i - 1][0][odev ^ 1]) % mod;
            f[i][1][0] = (f[i - 1][1][odev ^ 0] + f[i - 1][0][odev ^ 0]) % mod;
        }
 
        // 当前为0或由？变成0，因为当前是0所以出现在最终表达式中的次数不影响结果，直接转移 0 -> 0，1 -> 1
        if(s[i] == '0' || s[i] == '?'){
            f[i][0][1] = (f[i - 1][1][1] + f[i - 1][0][1]) % mod;
            f[i][0][0] = (f[i - 1][1][0] + f[i - 1][0][0]) % mod;
        }
    }
    // cout << (f[n][1][1] + f[n][0][1]) % mod << "\n"; // 最终为1的答案之和
    return (f[n][1][1] + f[n][0][1]) % mod;
}
int solve_(string str)
{
	// cin>>str;
	int cnt_1=0,cnt_2=0;
	int n=str.size();
	int res=0;
	for(int i=0;i<str.size();i++)
	{
		int c=(C(n-1,i)&1);
		if(str[i]=='?')
		{
			if (((n - 1) & i) == i)cnt_1++;
			else cnt_2++;
		}
		else if((((n - 1) & i) == i)&&str[i]=='1')res^=1;
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
	if(!res) return 0;
	else return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	F[0]=INF[0]=1;
	for(int i=1;i<M;i++)
	{
		F[i]=F[i-1]*i%mod;
		INF[i]=ksm(F[i],mod-2);
	}
	srand(time(0));
	while(1)
	{
		int L=1e6;
		int n=rand()%L;
		while(!n)n=rand()%L;
		string str="";
		for(int i=1;i<=n;i++)
		{
			int x=rand()%3;
			if(x==0)str=str+'0';
			else if(x==1)str=str+'1';
			else str=str+'?';
		}
		int ans_1=solve(str);
		int ans_2=solve_(str);
		cout<<ans_1<<" "<<ans_2<<endl;
		if(ans_1!=ans_2)
		{
			cout<<n<<endl;
			cout<<str<<endl;
		}
	}

	return 0;
}