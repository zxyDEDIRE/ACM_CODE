#include<bits/stdc++.h>
using namespace std;

const int N=3e6+10;
struct pp{
    int a,b,id;
}p[N],p1[N];
vector<int>c;
int n;
inline bool cmp1(pp x,pp y)
{
    if(x.b==y.b)
    {
        return x.a<y.a;
    }
    return x.b<y.b;
}
inline bool cmp2(pp x,pp y)
{
    if(x.a==y.a)
    {
        return x.b<y.b;
    }
    return x.a<y.a;
}
int m;
long long tr[N];
long long tr1[N];
inline int find(int x)
{
    return lower_bound(c.begin(),c.end(),x)-c.begin()+1;
}
inline void init()
{
    for(int i=1;i<=m;i++) tr[i]=1e18;
    for(int i=1;i<=m;i++) tr1[i]=1e18;
}
int lowbit(int x)
{
    return x&-x;
}
void add(int x,long long val){
    for(int i=x;i<=m;i+=lowbit(i)){
        tr[i]=min(tr[i],val);
    }
}
long long qr(int x)
{
    long long res=1e18;
    for(int i=x;i;i-=lowbit(i)) res=min(res,tr[i]);
    return res;
}
void add1(int x,long long val){
    for(int i=x;i;i-=lowbit(i)){
        tr1[i]=min(tr1[i],val);
    }
}
long long qr1(int x)
{
    long long res=1e18;
    for(int i=x;i<=m;i+=lowbit(i)) res=min(res,tr1[i]);
    return res;
}
int solve()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].a;
        p1[i].a=p[i].a;
        c.push_back(p[i].a);
    }
    long long res=0;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].b;
        p1[i].b=p[i].b;
        c.push_back(p[i].b);
        res+=abs(p[i].a-p[i].b);
    }
    sort(c.begin(),c.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    m=c.size();
    sort(p+1,p+n+1,cmp1);
    sort(p1+1,p1+n+1,cmp2);
    init();
    long long ans=res;
    int tp=1;
    for(int i=1;i<=n;i++)
    {
        while(tp<=n&&p1[i].a>=p[tp].b)
        {
            int id=find(p[tp].a);
            add(id,-p[tp].a-p[tp].b-abs(p[tp].a-p[tp].b));
            add1(id,p[tp].a-p[tp].b-abs(p[tp].a-p[tp].b));
            tp++;
        }
        int id=find(p1[i].b);
        ans=min(ans,res-abs(p1[i].a-p1[i].b)+qr(id)+p1[i].a+p1[i].b);
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
            add(id,-p1[tp].a-p1[tp].b-abs(p1[tp].a-p1[tp].b));
            tp++;
        }
        int id=find(p[i].a);
        ans=min(ans,res-abs(p[i].a-p[i].b)+qr1(id)-p[i].a+p[i].b);
        ans=min(ans,res-abs(p[i].a-p[i].b)+qr(id)+p[i].a+p[i].b);
    }
    cout<<ans<<'\n';
    return 0;
}

signed main(){
 freopen("C:\\Users\\tob\\Desktop\\1.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\1.txt","w",stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);cout.tie(nullptr);
    // int __;cin>>__;
    // while(__--)
    clock_t start, finish;
    start = clock();
    /*******代码*******/
    solve();
    /****************/
    finish = clock();
    cout << "the time cost is" <<\
    double(finish - start) / CLOCKS_PER_SEC;
//  fclose(stdin);
//  fclose(stdout);
    return 0;
}