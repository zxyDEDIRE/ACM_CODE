#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);
#define int long long
typedef long long ll;
typedef pair<int,int> P;
//const int N=2e5+7;
int dp[103][103][103];
const int N=50;
int dfs(int a,int b,int c)
{
	int &res=dp[a][b][c];
	if(res!=-1)return res;
	//cout<<a<<" "<<b<<" "<<c<<endl;
	if(a<=abs(b-c)||c<=abs(a-b)||b<=abs(a-c)||a>=(b+c)||b>=(a+c)||c>=a+b)return res=0;
	//cout<<"&&&"<<a<<b<<c<<endl;
	if(a==b){
		if(c==1)return res=0;
		else return res=1;
	}
	else if(a==c){
		if(b==1)return res=0;
		else return res=1;
	}
	else if(b==c){
		if(a==1)return res=0;
		else res=1;
	}
	for(int i=a-1;i>=1&&i>abs(b-c)&&i<abs(c+b);i--){
		int t=dfs(i,b,c);
		if(t==0)return res=1;
	}
	for(int i=b-1;i>=1&&i>abs(a-c)&&i<abs(c+a);i--){
		int t=dfs(a,i,c);
		if(t==0)return res=1;
	}
	for(int i=c-1;i>=1&&i>abs(b-a)&&i<abs(a+b);i--){
		int t=dfs(a,b,i);
		if(t==0)return res=1;
	}
	return res=0;
}
void solve()
{
	memset(dp,-1,sizeof(dp));
	//dp[1][1][1]=0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=N;k++){
				dfs(i,j,k);
				//cout<<i<<j<<k<<"=";
				//cout<<dp[i][j][k]<<" \033[0;35m 233 \033[0m";
				// if(dp[i][j][k]){
				// 	cout<<"\033[0;35m1\033[0m ";
				// }
				// else cout<<0<<" ";
				if(i<=abs(j-k)||k<=abs(i-j)||j<=abs(i-k)||i>=(j+k)||j>=(i+k)||k>=i+j)continue;
				if(i>j||j>k||i>k)continue;
				if(dp[i][j][k]==0)cout<<((i-1)^(j-1)^(k-1))<<endl;
			}
			//puts("");
		}
		puts("-----------------");
	}
}
signed main()
{
	//IOS
	int __=1;
	//cin >> __;
	while (__--)
		solve();
}
