#include<bits/stdc++.h>
using namespace std;

const int N=3e6+10;
struct pp{
    int a,b,id;
}p[N],p1[N];
vector<int>c;
long long tr[N];
int n,m;
inline int find(int x)
{
    return lower_bound(c.begin(),c.end(),x)-c.begin()+1;
}
inline void init()
{
    for(int i=1;i<=m;i++) tr[i]=1e18;
}
inline int lowbit(int x)
{
    return x&-x;
}
inline void add(int x,long long val){
    for(int i=x;i<=m;i+=lowbit(i)){
        tr[i]=min(tr[i],val);
    }
}
inline long long qr(int x){
    long long res=1e18;
    for(int i=x;i;i-=lowbit(i)) res=min(res,tr[i]);
    return res;
}
inline void add1(int x,long long val){
    for(int i=x;i;i-=lowbit(i)){
        tr[i]=min(tr[i],val);
    }
}
inline long long qr1(int x){
    long long res=1e18;
    for(int i=x;i<=m;i+=lowbit(i)) res=min(res,tr[i]);
    return res;
}
inline void read(int &x){
   int s = 0, w = 1; char ch = getchar();
   while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
   while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
   x = s*w;
   return ;
}
inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+'0');
}  
int main()
{
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    read(n);
    c=vector<int>(n);
    for(int i=1;i<=n;i++)
    {
        read(p[i].a);
        p1[i].a=p[i].a;
        c[i-1]=(p[i].a);
    }
    long long res=0;
    for(int i=1;i<=n;i++)
    {
        read(p[i].b);
        p1[i].b=p[i].b;
        c.push_back(p[i].b);
        res+=abs(p[i].a-p[i].b);
    }
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    m=c.size();

    sort(p+1,p+n+1,[&](pp x,pp y){
        if(x.b==y.b)return x.a<y.a;
        return x.b<y.b;
    });
    sort(p1+1,p1+n+1,[&](pp x,pp y){
        if(x.a==y.a)return x.b<y.b;
        return x.a<y.a;
    });

    init();
    long long ans=res;
    int tp=1;
    for(int i=1;i<=n;i++)
    {
        while(tp<=n&&p1[i].a>=p[tp].b)
        {
            int id=find(p[tp].a);
            add(id,-p[tp].a-p[tp].b-abs(p[tp].a-p[tp].b));
            tp++;
        }
        int id=find(p1[i].b);
        ans=min(ans,res-abs(p1[i].a-p1[i].b)+qr(id)+p1[i].a+p1[i].b);
    }
    init();
    tp=1;
    for(int i=1;i<=n;i++)
    {
        while(tp<=n&&p1[i].a>=p[tp].b)
        {
            int id=find(p[tp].a);
            add1(id,p[tp].a-p[tp].b-abs(p[tp].a-p[tp].b));
            tp++;
        }
        int id=find(p1[i].a);
        ans=min(ans,res-abs(p1[i].a-p1[i].b)+qr1(id)+p1[i].a-p1[i].b);
    }
    init();
    tp=1;
    for(int i=1;i<=n;i++)
    {
        while(tp<=n&&p[i].b>=p1[tp].a)
        {
            int id=find(p1[tp].b);
            add1(id,-p1[tp].a+p1[tp].b-abs(p1[tp].a-p1[tp].b));
            tp++;
        }
        int id=find(p[i].a);
        ans=min(ans,res-abs(p[i].a-p[i].b)+qr1(id)-p[i].a+p[i].b);
    }
    init();
    tp=1;
    for(int i=1;i<=n;i++)
    {
        while(tp<=n&&p[i].b>=p1[tp].a)
        {
            int id=find(p1[tp].b);
            add1(id,-p1[tp].a-p1[tp].b-abs(p1[tp].a-p1[tp].b));
            tp++;
        }
        int id=find(p[i].a);
        ans=min(ans,res-abs(p[i].a-p[i].b)+qr1(id)+p[i].a+p[i].b);
    }
    write(ans);printf("\n");
    return 0;
}