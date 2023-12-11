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
const int maxn=1e6+100;
 int dp[260000];
    int now[260000];
    int INF=1e9+7;
    int n;
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<pair<int,int>>p;
        n=cost.size();
        for(int j=0;j<=n*500+1000;j++)
        	dp[j]=INF,now[j]=INF;
        dp[1000]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n*500+1000;j++)
            {
                if(dp[j]!=INF&&j>0)
                    now[j-1]=min(now[j-1],dp[j]);
                if(dp[j]!=INF)
                    now[j+time[i-1]]=min(now[j+time[i-1]],dp[j]+cost[i-1]);
            }
            for(int j=0;j<=n*500+1000;j++)
                dp[j]=now[j],now[j]=INF;
        }

        int mi=INF;
        for(int j=1000;j<=n*500+1000;j++)
            mi=min(mi,dp[j]);
        cout<<mi<<endl;
        return mi;
        
    }
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	vector<int>cost,time;
	for(int i=0;i<4;i++){
		int x;cin>>x;
		cost.push_back(x);
	}
	for(int i=0;i<4;i++){
		int x;cin>>x;
		time.push_back(x);
	}
		paintWalls(cost,time);
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
[33,10,6,31,23,3]
[2,1,1,1,1,2]

33 10 6 31 23 3
2 1 1 1 1 2

1 2 3 2
1 2 3 2

250000
1000
*/