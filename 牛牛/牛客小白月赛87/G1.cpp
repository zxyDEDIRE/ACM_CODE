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
// const int maxn=1e6+100;
const int maxn=2022;
int dp[maxn][maxn];
class Solution {
public:
    
    int p[maxn];
    int ans=1;
    void dfs(int l,int r,int x,int num)
    {
        if(l>=r)return ;
        // ans=max(ans,num);
        // if(l>=r)return ;
        // if(r-l+1<2)return ;
        // if(p[l]+p[r]==x)
        //     dfs(l+1,r-1,x,num+1);
        // if(p[l]+p[l+1]==x)
        //     dfs(l+2,r,x,num+1);
        // if(p[r]+p[r-1]==x)
        //     dfs(l,r-2,x,num+1);
        for(int i=l;i<=r;i++)
            for(int j=i;j<=r;j++)
                dp[i][j]=-1;
        dp[l][r]=1;
        for(int i=l;i<=r;i++)
		{
			for(int j=r;j>=i;j--)
			{
				ans=max(ans,dp[i][j]);
				if(dp[i][j]==-1)continue;
				// cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<p[i]+p[j]<<endl;
				if(i+1<=j && p[i]+p[i+1]==x){
					if(i+2<=r)
						dp[i+2][j]=max(dp[i+2][j],dp[i][j]+1);
					ans=max(ans,dp[i][j]+1);
				}
				if(i<j && p[i]+p[j]==x){
					if(i+1<=r && j-1>=l)
						dp[i+1][j-1]=max(dp[i+1][j-1],dp[i][j]+1);
					ans=max(ans,dp[i][j]+1);
				}
				if(i<=j-1 && p[j]+p[j-1]==x){
					if(j-2>=l)
						dp[i][j-2]=max(dp[i][j-2],dp[i][j]+1);
					ans=max(ans,dp[i][j]+1);
				}
			}
        }
    }
    int maxOperations(vector<int>& a) {
        int x,n=a.size();
        for(int i=0;i<n;i++)
            p[i]=a[i];
        x=p[0]+p[n-1];
        dfs(1,n-2,x,1);
        x=p[0]+p[1];
        dfs(2,n-1,x,1);
        x=p[n-1]+p[n-2];
        dfs(0,n-3,x,1);
        return ans;
    }
};
void solve()
{
	// int n=6;
	int n=2000;
	vector<int>p;
	for(int i=1;i<=n;i++){
		p.push_back(1);
		// int x;cin>>x;
		// p.push_back(x);
	}
	Solution a;
	cout<<a.maxOperations(p)<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int T=1;
	while(T--)
		solve();
	return 0;
}
/*
3 2 1 2 3 4 
1 1 3 3 5

1 1 1 2 5
  1 2 3
*/