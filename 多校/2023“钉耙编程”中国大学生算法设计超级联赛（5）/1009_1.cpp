/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int maxn=2e6+100;
const int N=2e6+100;
struct node{
	int to,next;
}edge[maxn],e[maxn];
int head[maxn],cnt1;
int h[maxn],cnt2;
int son[maxn];
int cnt[maxn];
int lo[maxn];
int n,ans,i,_x,x;
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
	for(i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==son[x])continue;
		add1(topf,y);
		dfs(y,x,y);
	}
}
inline void dfs1(int x,int dep)
{
	// _x = lo[cnt[x]];
	// if((1<<_x)<cnt[x])_x++;
	// dep+=lo[2*cnt[x]]+1;

	dep+=lo[2*cnt[x]];
	cout<<lo[2*cnt[x]]<<endl;
	ans=max(ans,dep);

	for(i=h[x];i;i=e[i].next)
	{
		int y=e[i].to;
		dfs1(y,dep);
	}

}
inline void solve()
{
	// cin>>n;
	n=1e6;
	ans=0;
	for(i=1;i<=n;i++)
	{
		head[i]=h[i]=cnt[i]=0;
	}
	cnt1=cnt2=0;
	for(i=1;i<=n;i++)
	{
		// cin>>x;
		if(i==1)x=0;
		else
		{
			if(i&1)x=i-1;
			else x=i-2;
		}
		add(x,i);
	}
	for(i=1;i<=n;i++){
		if(i&1)son[i]=i+1;
		else son[i]=0;
		// cin>>son[i];
	}
	dfs(1,0,1);
	dfs1(1,0);
	cout<<ans+1<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	int size(512<<20); // 512M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size)); // YOUR CODE
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	init();
	// cout<<lo[4]<<endl;
	int __;cin>>__;
	while(__--){
		solve(); 
	}
//  fclose(stdin);
//  fclose(stdout);
	exit(0);
}
/*
1
8
0 1 2 3 4 5 6 7
2 3 4 5 6 7 8 0

1
5
0 1 2 3 4
2 3 4 5 0


*/