/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
#define endl "\n"
#define pii pair<int,int>
#define pp(x) array<int,x>
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=100;
int mp[N][N];
int dis[N][N];
bool vis[N][N];
int n=5;
void A()
{
    queue<pii>q;
    q.push(pair<int,int>(1,1));
    dis[1][1]=0;
    while(!q.empty())
    {
        pii now;
        now=q.front();q.pop();
        int x=now.first;
        int y=now.second;
        if(vis[x][y])continue;
        vis[x][y]=1;
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx<1||xx>n||yy<1||yy>n)continue;
            if(mp[xx][yy])continue;
            if(dis[xx][yy]>dis[x][y]+1){
                dis[xx][yy]=dis[x][y]+1;
                q.push(pair<int,int>(xx,yy));
            }
        }
    }
}
vector<pii>v;
void dfs(int x,int y,int now)
{
    v.push_back(pair<int,int>(x,y));
    if(x==1&&y==1){
        return ;
    }
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<1||xx>n||yy<1||yy>n)continue;
        if(dis[xx][yy]==dis[x][y]-1){
            dfs(xx,yy,now-1);
            break;
        }
    }
}
void solve()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
            dis[i][j]=INF;
        }
    A();
    dfs(n,n,dis[n][n]);
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        cout<<"("<<v[i].first-1<<", "<<v[i].second-1 <<")"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // int __;cin>>__;
    // while(__--)
        solve();
//  fclose(stdin);
//  fclose(stdout);
    return 0;
}