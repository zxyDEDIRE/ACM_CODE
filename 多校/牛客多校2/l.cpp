#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e9+7;
int n,m,t,res=inf;
int ans[10004][2007];
signed main()
{
    cin>>n>>m;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            ans[i][j]=-inf;
    for(int i=1;i<=m;i++)
    {
        cin>>t;
        while(t--)
        {
            int x,y;cin>>x>>y;
            if(y==1)
                continue;
            if(x==1)//1-y
                ans[i][y]=i;
            else//1-x-y
            {
                ans[i][y]=max(ans[i][y],ans[i-1][x]);
            }
            res=min(res,i-ans[i][m]+1);
        }
    } 
    if(n==1){
    	cout<<0<<endl;
    	return 0;
    }
    if(res==inf)
        res=-1;
    cout<<res<<endl;
    return 0;
}