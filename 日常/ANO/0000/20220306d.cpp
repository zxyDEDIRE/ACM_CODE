#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4;
int dp[30][30][30];
int dfs(int a,int b,int c)
{
	
    if(a<=0||b<=0||c<=0)return 1;
    if(a>20||b>20||c>20)return dfs(20,20,20);
    if(dp[a][b][c])return dp[a][b][c];
    cout<<a<<" "<<b<<" "<<c<<endl;
    if(a<b&&b<c)return dp[a][b][c]=dfs(a,b,c-1)+dfs(a,b-1,c-1)-dfs(a,b-1,c);
    return dp[a][b][c]=dfs(a-1,b,c)+dfs(a-1,b-1,c)+dfs(a-1,b,c-1)-dfs(a-1,b-1,c-1);
}
signed main()
{
    int a,b,c;
    while(1)
    {
    	cin>>a>>b>>c;
        if(a==-1&&b==-1&&c==-1)break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<dfs(a,b,c)<<endl;
    }
}
/*
6 4 2 3 
.XXX
.XXX
.XXX
...X
..X.
X...
*/
