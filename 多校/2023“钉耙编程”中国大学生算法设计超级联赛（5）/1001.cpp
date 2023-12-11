#include<bits/stdc++.h>
using namespace std;
//#define double long double//wa了就试一下
const double eps=1e-6;
int cmpb(double x)
{
    if(fabs(x)<eps) return 0;
    if(x>0) return 1;
    return -1;
}
struct point{
    int x,y;
};
const int N=1e4+10;
point s[N];
int n,m;
inline long long cro(point a,point b,point c)
{
    int x=b.x-a.x,y=b.y-a.y,x1=c.x-a.x,y1=c.y-a.y;
    return 1ll*x*y1-1ll*x1*y;
}
inline long long dot(point a,point b,point c){  //点积 p0为角点
    int x=b.x-a.x,y=b.y-a.y,x1=c.x-a.x,y1=c.y-a.y;
    return 1ll*x*x1+1ll*y*y1;
}
inline long long db(int x)
{
    return 1ll*x*x;
}
inline double dict(point a,point b)
{
    return sqrt(db(a.x-b.x)+db(a.y-b.y));
}
inline double getDis(point p0,point p1,point p2){
     if(cmpb(dict(p0,p1))==0) return dict(p0,p2);//p0 p1共同点
     else if(cmpb(dot(p0,p1,p2))==-1) return dict(p0,p2);//钝角
     else if(cmpb(dot(p1,p0,p2))==-1) return dict(p1,p2);//钝角
     return abs(cro(p0,p1,p2))/dict(p0,p1);  //点到线的距离
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    clock_t start, finish;
    start = clock();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].x>>s[i].y;
    }
    point o;
    for(int i=1;i<=m;i++)
    {
        cin>>o.x>>o.y;
        double ans=1e20;
        for(int j=1;j<n;j++)
        {
            ans=min(ans,getDis(s[j],s[j+1],o));
        }
        cout<<fixed<<setprecision(4)<<ans<<'\n';
    }
    finish = clock();
    cout << "the time cost is" <<\
    double(finish - start) / CLOCKS_PER_SEC;
    return 0;
}
