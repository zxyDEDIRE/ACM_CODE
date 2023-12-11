#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);
#define int long long
typedef long long ll;
typedef pair<int,int> P;
const int N=1e6+7;
const int mod=998244353;
int fa[N];
int n,m;
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void lian(int x,int y)
{
    int xx=find(x);
    int yy=find(y);
    if(xx!=yy)fa[xx]=yy;
}
int vis[N];
void solve()
{
    int x,y;
    for(int i=1;i<=1e6;i++)fa[i]=i;
	while(cin>>x>>y,x!=-1){
        int fl=0;
        n=0;
        vis[x]=1;
        vis[y]=1;
        n=max(x,y);
        lian(x,y);
        while(cin>>x>>y,x){
            vis[x]=1;
            vis[y]=1;
            int xx=find(x);
            int yy=find(y);
            n=max(n,x);
            n=max(n,y);
            if(xx!=yy)fa[xx]=yy;
            else{
                fl=1;
            }
        }
        int num=0;
        for(int i=1;i<=1e6;i++){
            if(fa[i]==i&&vis[i])num++;
        }
        if(num!=1)fl=1;
        if(!fl)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        for(int i=1;i<=1e6;i++)fa[i]=i,vis[i]=0;
    }
}
signed main()
{
	//IOS
	int __=1;
	//cin >> __;
	while (__--)
		solve();
}