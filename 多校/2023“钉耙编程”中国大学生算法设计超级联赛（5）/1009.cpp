/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int maxn=1e6+100;
const int N=2e6+100;
struct node{
	int to,next;
}edge[maxn],e[maxn];
int head[maxn],cnt1;
int h[maxn],cnt2;
int son[maxn];
int cnt[maxn];
int lo[N];
int n,ans;
inline void add(int from,int to)
{
	edge[++cnt1].to=to;
	edge[cnt1].next=head[from];
	head[from]=cnt1;
}
inline void add1(int from,int to)
{
	e[++cnt2].to=to;
	e[cnt2].next=h[from];
	h[from]=cnt2;
}
inline void init(){
	lo[0]=-1;
    for(int i = 1; i < N-10; i ++){
        lo[i] = lo[i >> 1] + 1;
    }
    for(int i = 1; i < N-10; i ++){
    	if((1<<lo[i])<i) lo[i]++;
    }
}
inline void dfs(int x,int fa,int topf)
{
	cnt[topf]++;
	if(son[x])dfs(son[x],x,topf);
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==son[x])continue;
		add1(topf,y);
		dfs(y,x,y);
	}
}
inline void dfs1(int x,int dep)
{
	dep+=lo[2*cnt[x]];
	ans=max(ans,dep);
	for(int i=h[x];i;i=e[i].next)
	{
		int y=e[i].to;
		dfs1(y,dep);
	}

}
inline void solve()
{
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		head[i]=h[i]=cnt[i]=0;
	}
	cnt1=cnt2=0;
	
	for(int i=1,x;i<=n;i++)
	{
		cin>>x;
		add(x,i);
	}
	for(int i=1;i<=n;i++)
		cin>>son[i];
	dfs(1,0,1);
	dfs1(1,0);
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	int size(512<<20); // 512M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size)); // YOUR CODE
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	init();
	int __;cin>>__;
	while(__--)
		solve();
	// cout<<lo[6]<<endl;
	// cout<<lo[2]<<endl;
//  fclose(stdin);
//  fclose(stdout);
	exit(0);
}
/*
1
6
0 1 2 3 4 5
0 0 0 0 0 0

1
5
0 1 1 3 4
2 0 0 5 0


5
0 1 1 3 3
2 0 4 0 0
*/