#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define int long long
const int maxn=1e6+7;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dp[40][40];
int s[40][40];
int n,m,k,ex,ey,sx,sy;
int OK(int x,int y)
{
    return x<=n&&y<=m&&x>=1&&y>=1;
}
int ans=1e9;
void dfs(int x,int y,int p)
{
    if(x==ex&&y==ey){
        ans=min(ans,p);
        return;
    }
    if(dp[x][y]!=-1&&dp[x][y]<=p)return;
    dp[x][y]=p;
    //cout<<x<<" "<<y<<endl;
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(OK(xx,yy)){
            if(s[xx][yy])dfs(xx,yy,p+1);
            else dfs(xx,yy,p);
        }
    }
}
void solve()
{
    memset(dp,-1,sizeof(dp));
    memset(s,0,sizeof(s));
    cin>>n>>m>>k;
    n*=2;
    m*=2;
    cin>>sx>>sy>>ex>>ey;
    //sx+=1,sy+=1,ex+=1,ey+=1;
    sx*=2;
    sy*=2;
    ex*=2;
    ey*=2;
    for(int i=1;i<=k;i++){
        int ax,ay,bx,by;
        cin>>ax>>ay>>bx>>by;
        //ax+=1,ay+=1,bx+=1,by+=1;
        ax*=2;
        ay*=2;
        bx*=2;
        by*=2;
        if(ax==bx){
            for(int i=min(ay,by)+1;i<=max(ay,by);i++){
                s[ax][i]=1;
            }
        }
        else{
            for(int i=min(ax,bx);i<=max(ax,bx);i++){
                s[i][ay]=1;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<s[i][j]<<" ";
    //     }
    //     puts("");
    // }
    dfs(sx+1,sy+1,0);
    cout<<ans<<endl;
}
signed main()
{
    int __=1;
    cin >> __;
    while (__--)
        solve();
}
