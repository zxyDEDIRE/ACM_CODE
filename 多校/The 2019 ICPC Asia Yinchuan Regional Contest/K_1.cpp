#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m;
int a[N][N],b[N][N];
map<pair<int,int>,int>mp;
pair<int,int> id[N*N];
int cnt;
int h[N][N],l[N][N];
int st[N][N][10];
int lg[N];
int qr(int i,int l,int r){
    int le=lg[r-l+1];
    return min(st[i][l][le],st[i][r-(1<<le)+1][le]);
}
int ans=1;


struct SaDown{
    //退火系数
    #define down 0.996
    double ansx,ansy,ansz,answ;
    //评估函数
    double energy(int r,int i,int j){
       
        return  (r-j+1)*qr(i,j,r);
    }
    void sa(int l,int r,int i,int j)
    {
        double t=3000;
        while(t>1e-15)
        {
            double ex=ansx+(rand()*2-RAND_MAX)*t;
            double ew=energy(ex,i,j);
            double de=ew-answ; 
            if(answ<ew)
            {
                ansx=ex;
            }
            else if(exp(-de/t)*RAND_MAX>rand())
            {
                ansx=ex;
            }
            t*=down;
        }
    }
    void doit(int l,int r,int i,int j){
        //退火次数
        for(int k=1;k<=4;k++)
            sa(l,r,i,j);
    }
}sa;

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            id[a[i][j]]={i,j};
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>b[i][j];
            int x=i-id[b[i][j]].first,y=j-id[b[i][j]].second;
            if(mp.count({x,y})) b[i][j]=mp[{x,y}];
            else {
                b[i][j]=++cnt;
                mp[{x,y}]=cnt;
            }
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            if(b[i][j]==b[i+1][j]){
                st[i][j][0]=st[i+1][j][0]+1;
            }
            else{
                st[i][j][0]=1;
            }
        }
    }
    lg[0]=-1;
    for(int i=1;i<=m;i++){
        lg[i]=lg[i>>1]+1;
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<10;k++){
            for(int j=1;j+(1<<k)-1<=m;j++){
                st[i][j][k]=min(st[i][j][k-1],st[i][j+(1<<(k-1))][k-1]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(b[i][j]==b[i][j+1]){
                l[i][j]=l[i][j+1];
            }
            else{
                l[i][j]=j;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int ll=j,rr=l[i][j];
            if((rr-ll+1)*st[i][j][0]<=ans) continue;
            sa.doit(ll,rr,i,j);
            
        }
    }
    cout<<ans<<'\n';
}


int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
