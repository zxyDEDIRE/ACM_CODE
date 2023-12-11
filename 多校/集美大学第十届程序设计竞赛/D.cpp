#include<bits/stdc++.h>
using namespace std;
#define double long long //wa了就试一下
const double eps=0;
int cmpb(double x)
{
    if(fabs(x)<=eps) return 0;
    if(x>0) return 1;
    return -1;
}
struct point{
    double x,y;
    int id;
    point(){x=0;y=0;id=0;}
    point(double _x,double _y){x=_x;y=_y;};
    double operator |(const point &w) const//点乘
    {
        return x*w.x+y*w.y;
    }
    double operator ^(const point &w) const//叉乘
    {
        return x*w.y-y*w.x;
    }
    point operator -(const point &w) const
    {
        point res;
        res.x=x-w.x;res.y=y-w.y;
        return res;
    }
    point operator +(const point &w) const
    {
        point res;
        res.x=x+w.x;res.y=y+w.y;
        return res;
    }
    point operator /(double w) const
    {
        point res(x/w,y/w);
        return res;    
    }
    point operator *(double w) const
    {
        point res(x*w,y*w);
        return res;    
    }
    double db(double x)   //平方
    {
        return x*x;
    }
    double dict(point &to)//点距
    {
        return sqrt(db(x-to.x)+db(y-to.y));
    }
    double dz()
    {
        return sqrt(db(x)+db(y));
    }
    void rotate(double _o) //旋转都是逆时针 
    {
        double _x=x,_y=y;
        x=_x*cos(_o)-_y*sin(_o);
        y=_x*sin(_o)+_y*cos(_o);
    }
    double arg()//-pi,pi x轴正方向为0 逆时针
    {
        return atan2(y,x);
    }
};
//排序cmp
struct argcmp{//极角排序
    int quad(const point&x) //象限排序 根据题目定义
        {
            if(x.y<0) return 0;
            else if(x.y>0) return 3;
            else if(x.x>0) return 1;
            else if(x.x<0) return 4;
            return 2;
        };
    bool operator()(const point &x,const point &y) 
    {
        
        int xb=quad(x);
        int yb=quad(y);
        if(xb!=yb)
        {
            return xb<yb;
        }
        return (x^y)>0; //右手定则
    }
};
const int N=4e3+10;
int n;
point p[N];
point st[N];
int cnt=0;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
    }
    int ans=0;
    map<pair<long long,long long>,bool>vis;
    for(int i=1;i<=n;i++){
        cnt=0;
        int u=n+1;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            st[++cnt]=p[j]-p[i];
            long long d=__gcd(abs(st[cnt].x),abs(st[cnt].y));
            st[cnt]=st[cnt]/d;
            vis[{st[cnt].x,st[cnt].y}]=true;
            st[cnt].id=cnt;
            if(u==n+1&&j>i){
                u=cnt;
            }
        }
        for(int j=1;j<=n-1;j++){
            if(vis[{-st[i].x,-st[i].y}]==false){
                st[++cnt].x=-st[i].x;
                st[cnt].y=st[i].y;
                st[cnt].id=-1;
                vis[{-st[i].x,-st[i].y}]=true;
            }
        }
        sort(st+1,st+cnt+1,argcmp());
        map<pair<long long,long long>,int>mx,mi;
        int ip=0;
        for(int j=1;j<=cnt;j++){
            mx[{st[j].x,st[j].y}]=ip;
            if(st[j].id!=-1){
                ip++;
            }
        }
        ip=0;
        for(int j=cnt;j>=1;j--){
            mi[{st[j].x,st[j].y}]=ip;
            if(st[j].id!=-1){
                ip++;
            }
        }
        for(int j=1;j<=cnt+cnt;j++){
            if(st[j].id>=u){
                int s=mx[{st[j].x,st[j].y}],e=mi[{-st[j].x,-st[j].y}];
                int s1=mx[{-st[j].x,-st[j].y}],e1=mi[{st[j].x,st[j].y}];
                if(abs(s1-e1)==abs(s-e)){
                    ans++;
                }
            }
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