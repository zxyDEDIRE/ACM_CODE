#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int s[13][13];
int vis[13][13];
int vis1[10];
void solve()
{
    cin>>n>>m;
    cout<<n<<" "<<m<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>s[i][j];
        }
    }
    cout<<"*"<<endl;
    memset(vis,0,sizeof(vis));
    memset(vis1,0,sizeof(vis1));
    
    int x,y;
    string ans="YES";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vis[i][j])continue;
            x=0,y=0;
            int t=s[i][j];
            if(vis1[t])ans="NO";
            for(int ii=i;ii<=n;ii++){
                if(s[ii][j]!=t)break;
                x++;
            }
            for(int jj=j;jj<=m;jj++){
                if(s[i][jj]!=t)break;
                y++;
            }
            for(int ii=0;ii<x;ii++){
                for(int jj=0;jj<y;jj++){
                    if(vis[ii][jj]!=t)ans="NO";
                    vis[ii][jj]=1;
                }
            }
            vis1[t]=1;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    int __;
    cin>>__;
    //__=1;
    while(__--)solve();
}
/*
3
3 5
00022
00033
44444
3 5
11122
11122
33311
2 5
01234
56789

*/
