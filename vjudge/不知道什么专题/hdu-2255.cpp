/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
const int N=400;
int link[N],n,lx[N],ly[N];
int w[N][N];
bitset<N>vx,vy;
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
void solve()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>w[i][j];
            }
        }
        cout<<KM()<<endl;
	}
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}