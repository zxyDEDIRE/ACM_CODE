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
long long dp[20000][20];
void solve()
{
	vector<int>nums;
	int x;
	while(cin>>x&&x)
		nums.push_back(x);
    int n=nums.size();
    cout<<"N "<<n<<endl;
    int mod=1e9+7;
    for(int i=0;i<n;i++)
        dp[1<<i][i]=1;
    for(int k=0;k<(1<<n);k++)
    {
        for(int i=0;i<n;i++)
        {
            if(!(k&(1<<i)))continue;
            for(int j=0;j<n;j++)
            {
                if(k&(1<<j))continue;
                cout<<k<<" "<<nums[i]<<" "<<nums[j]<<" "<<nums[i]%nums[j]<<endl;
                if(i==j)continue;
                if(nums[i]%nums[j]==0||nums[j]%nums[i]==0)
                {
                	cout<<"SDf"<<endl;
                (dp[k|(1<<j)][j]+=dp[k][i])%=mod;
                }
                
            }
        }
    }
    long long ans=0;
    for(int i=0;i<n;i++)
        ans=(ans+dp[(1<<n)-1][i])%mod;
    cout<<ans<<endl;
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
[2,3,6]
2 3 6 0
1 2 6 0

1 6 2 =0
*/