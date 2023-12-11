// #pragma comment(linker, "/STACK:1024000000,1024000000")
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
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
const int maxn=1e7+100, N=1e6+10;
struct Edge{int to,next;}edge[maxn];
int head[maxn],cnt;
bitset<maxn>ok;
bool vis[maxn];
vector<int>v;
int q[N],_cnt;
int res;
int n;
void init(int n=N-10){
    vis[1]=true;
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            q[_cnt++]=i;
        }
        for(int j=0;1ll*q[j]*i<=n;j++){
            int nu=q[j]*i;
            vis[nu]=true;
            if(i%q[j]==0){
                break;
            }
        }
    }
};
bool check(int x,int y){
	if((x+y)%2){
		if(vis[x+y]==false) return true;
	}
	if(abs(x-y)%2){
		if(vis[(abs(x-y))]==false) return true;
	}
	return false;
}
void add(int from,int to){
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dfs(int x)
{
	ok[x]=1;
	v.push_back(x);
	int num=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!ok[y])
			dfs(y);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		ok[i]=0;
	memset(head+1,0,sizeof(int)*cnt);
	cnt=1;
	v.clear();

	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=min(n,i+7);j++){
			if(check(j,i)){
				add(i,j);add(j,i);
			}
		}
	}
	dfs(1);
	for(auto i:v)
		cout<<i<<" ";cout<<endl;

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	init();
	int __=1;cin>>__;
	while(__--)
		solve();

	return 0;
}
/*
3
3
5
7

*/