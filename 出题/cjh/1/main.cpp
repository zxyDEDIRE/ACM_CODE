/*
    n^2log(n) 可以过的几何凸包

    一群小羊正在草坪上吃草，突然来了一群狼要来抓羊，你需要通过建立栅栏将小羊保护起来，
    问最少需要多长的栅栏才能将小羊全部保护起来
*/
#include<bits/stdc++.h>
using namespace std;
using db=double;
struct point{
    db x,y;
    point(){x=0;y=0;}
    point(db _x,db _y){x=_x;y=_y;}
    point operator -(const point &w)const{
        return point(x-w.x,y-w.y);
    }
    point operator +(const point &w)const{
        return point(x+w.x,y+w.y);
    }
    db operator ^(const point &w)const{
        return x*w.y-y*w.x;
    }
    db operator |(const point &w)const{
        return x*w.x+y*w.y;
    }
    db mod(){
        return sqrt(x*x+y*y);
    }
    db mod2(){
        return x*x+y*y;
    }
};

const int N=2e3+10;
int n;
point p[N];
point st[N];
//排序cmp
struct argcmp{//极角排序
    int quad(const point&x) //象限排序 根据题目定义
        {
            if(x.y>0) return 3;
            else if(x.y<0) return 5;
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
        return (x^y)>0; 
    }
};

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string x,y;
        cin>>x>>y;
        p[i]=point(stod(x),stod(y));
    }
    int f=0;
    for(int i=2;i<=n;i++){
        if((p[2]-p[1])^(p[i]-p[i-1])) {
            f=1;break;
        }
    }
    if(!f){
        db ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,(p[i]-p[j]).mod()*2);
            }
        }
        cout<<fixed<<setprecision(10)<<ans<<'\n';
    }
    else{
        db ans=0;
        for(int i=1;i<=n;i++){
            int tp=0;
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                st[++tp]=p[j]-p[i];
            }
            sort(st+1,st+tp+1,argcmp());
            int f=0;
            for(int j=1;j<=tp;j++){
                db t=(st[j]^st[j%tp+1]);
                if(t<0){ 
                    f++;
                }
            }
            if(!f) continue;
            point l,r;
            l=st[1];r=st[1];
            for(int j=1;j<=tp;j++){
                if((st[j]^l)>0){
                    l=st[j];
                }
                else if((st[j]^l)==0&&st[j].mod2()>l.mod2()&&(st[j]|l)>=0){
                    l=st[j];
                }
                if((st[j]^r)<0){
                    r=st[j];
                }
                else if((st[j]^r)==0&&st[j].mod2()>r.mod2()&&(st[j]|r)>=0){
                    r=st[j];
                }
            }
            if((l^r)<=0) continue;
            ans+=r.mod();
        }
        cout<<fixed<<setprecision(10)<<ans<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}

