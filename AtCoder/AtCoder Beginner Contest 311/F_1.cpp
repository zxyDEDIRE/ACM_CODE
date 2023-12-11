#include<iostream>
#include<cstdio>
#include<string.h>
#include<string>
#include<stack>
#include<set>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>


#define ll __int64
#define lll unsigned long long
#define MAX 1000009
#define eps 1e-8

using namespace std;
/*
二维RMQ模板题
同一维一样 用dp[row][col][i][j]表示(row,col)到(row+2^i,col+2^j)矩形内的最小值
查询
*/

int mapp[309][309];
int dp[309][309][9][9];
int flag;

void RMQ_init2d(int m,int n)
{
    for(int i=1; i<=m; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            dp[i][j][0][0] = mapp[i][j];
        }
    }
    int t = log((double)n) / log(2.0);

    for(int i = 0; i<=t; i++)
    {
        for(int j = 0; j<=t; j++)
        {
            if(i==0&&j==0)
                continue;
            for(int row = 1; row+(1<<i)-1<= m; row++)
            {
                for(int col = 1; col+(1<<j)-1<= n; col++)
                {
                    if(i)
                        dp[row][col][i][j]  = max(dp[row][col][i-1][j],dp[row+(1<<(i-1))][col][i-1][j]);
                    else
                        dp[row][col][i][j]  = max(dp[row][col][i][j-1],dp[row][col+(1<<(j-1))][i][j-1]);
                }
            }
        }
    }
}
int RMQ_2d(int x1,int y1,int x2,int y2)
{
    int k1 = log(double(x2 - x1 + 1)) / log(2.0);
    int k2 = log(double(y2 - y1 + 1)) / log(2.0);
    int m1 = dp[x1][y1][k1][k2];
    int m2 = dp[x2 - (1<<k1) + 1][y1][k1][k2];
    int m3 = dp[x1][y2 - (1<<k2) + 1][k1][k2];
    int m4 = dp[x2 - (1<<k1) + 1][y2 - (1<<k2) + 1 ][k1][k2];
    int _max = max(max(m1,m2),max(m3,m4));
    if(mapp[x1][y1]==_max||mapp[x1][y2]==_max||mapp[x2][y1]==_max||mapp[x2][y2]==_max)
        flag = 1;
    return _max;
}

int main()
{
    int n,m,t;
    int x1,x2,y1,y2;
    while(~scanf("%d%d",&m,&n))
    {
        for(int i = 1; i<=m; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                scanf("%d",&mapp[i][j]);
            }
        }
        RMQ_init2d(m,n);
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

            flag = 0;
            int _max = RMQ_2d(x1,y1,x2,y2);
            if(flag == 1)
                printf("%d yes\n",_max);
            else
                printf("%d no\n",_max);
        }
    }
    return 0;
}