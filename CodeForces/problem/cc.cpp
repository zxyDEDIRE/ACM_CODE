#include<iostream>
#include<string.h>
using namespace std;
int t,m;
int dp[1003];
struct poi
{
    int u,v;
}s[103];
int main()
{
    cin>>t>>m;
    for(int i=1;i<=m;i++){
        cin>>s[i].u>>s[i].v;
    }
    //memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=m;i++){
        for(int j=t;j>=s[i].u;j--){
            if(dp[j-s[i].u]!=-1){
                dp[j]=max(dp[j-s[i].u]+s[i].v,dp[j]);
            }
        }
        
    }
    for(int j=1;j<=t;j++){
            cout<<dp[j]<<" ";
        }
        puts("");
    int ans=0;
    for(int i=t;i>=0;i--){
        if(dp[i]!=-1){
            ans=dp[i];
            break;
        }
    }
    cout<<ans<<endl;
}
/*
*/