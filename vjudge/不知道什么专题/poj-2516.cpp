/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
const int N=300;
int link[N],lx[N],ly[N];
int w[N][N];
bitset<N>vx,vy;
int n,m,k;
int dfs(int x)
{
    vx[x]=1;
    for(int i=1;i<=n;i++){
        if(!vy[i]&&lx[x]+ly[i]==w[x][i]){
            vy[i]=1;
            if(!link[i]||dfs(link[i])){
                link[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int KM()
{
    for(int i=1;i<=n;i++){
        lx[i]=-INF;
        ly[i]=0;
        link[i]=0;
        for(int j=1;j<=n;j++){
            lx[i]=max(lx[i],w[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        while(1){
            vx.reset();
            vy.reset();
            if(dfs(i))break;
            int d=INF;
            for(int j=1;j<=n;j++){
                if(vx[j]){
                    for(int k=1;k<=n;k++){
                        if(!vy[k])d=min(d,lx[j]+ly[k]-w[j][k]);
                    }
                }
            }
            if(d==INF){
                cout<<"T_T"<<endl;
                return -1;
            }
            for(int j=1;j<=n;j++)if(vx[j])lx[j]-=d;
            for(int j=1;j<=n;j++)if(vy[j])ly[j]+=d;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans+=w[link[i]][i];
    return ans;
}
int ned[N][N];
int had[N][N];
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			cin>>ned[i][j];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=k;j++)
			cin>>had[i][j];
	while(k--)
	{
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}