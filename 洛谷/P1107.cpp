/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=2010;
int p[2005][2005];
int dp[maxn][maxn];
int pre[maxn];
int n,h,k;
int read() {
    int s = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
    return f ? -s : s;
}
void solve()
{
	n=read();
	h=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		int x;x=read();
		for(int j=1;j<=x;j++)
		{
			int y;
			y=read();
			p[i][y]++;
		}
	}


	for(int j=h;j>=1;j--)
	{
		for(int i=1;i<=n;i++)
		{
			if(j+k<=h)
				dp[i][j]=max(dp[i][j+1],pre[j+k])+p[i][j];
			else 
				dp[i][j]=dp[i][j+1]+p[i][j];
			pre[j]=max(dp[i][j],pre[j]);
		}
	}
	



	int ma=0;
	for(int i=1;i<=n;i++)
		ma=max(ma,dp[i][1]);
	cout<<ma;

}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}