#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int n=10,m1=5,m2=5;
int f(){
    return rand()%n+1;
}
void solve()
{
    int s=rand()%10+1;
    cout<<n<<" "<<m1<<" "<<m2<<" "<<s<<endl;
    srand(time(0));
    for(int i=1;i<=m1;i++)
    {
        int x,y,w;
        x=f();
        y=f();
        w=i*2;
        while(x==y)x=f();
        cout<<x<<" "<<y<<" "<<w<<endl;
    }
    for(int i=1;i<=m2;i++)
    {
        int x,y,w;
        x=f();
        y=f();
        w=rand()%10*(rand()%2==0?1:-1);
        while(x==y)x=f();
        cout<<x<<" "<<y<<" "<<w<<endl;
    }
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}