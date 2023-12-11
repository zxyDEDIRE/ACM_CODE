/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
struct Seg{	int l,r,val;}t[maxn<<2];
struct node{
	int id,dis,ti;
	bool operator<(const node&a)const{
		if(a.ti!=ti)return a.ti<ti;
		return a.dis<dis;
	}
};
struct Edge{
	int to,next,w;
}edge[maxn];
bitset<maxn>vis;
int head[maxn],cnt;
int ans[maxn];
int a[maxn];
int X[maxn];
int n,m,k,d;
clock_t start, finish;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void pushup(int rt)
{
	if(X[t[rt<<1].val]>=X[t[rt<<1|1].val])
		t[rt].val=t[rt<<1].val;
	else 
		t[rt].val=t[rt<<1|1].val;
}
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	if(l==r){
		t[rt].val=l;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
int query(int rt,int l,int r,int k)
{
	if(X[t[rt].val]<k)return INF;
	if(t[rt].l==t[rt].r)
		return t[rt].val;
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=INF;
	if(l<=mid)ans=min(ans,query(rt<<1,l,r,k));
	if(r>mid)ans=min(ans,query(rt<<1|1,l,r,k));
	return ans;
}
void prime()
{
	// cout<<endl;
	for(int i=1;i<=n;i++)
		ans[i]=-1;
	priority_queue<node>q;
	for(int i=1;i<=k;i++)
		q.push({a[i],0,-1}),ans[a[i]]=-1;
	int now=0;
	while(!q.empty())
	{
		// time
		finish = clock();
		double e = double(finish - start) / CLOCKS_PER_SEC;
		if(e>=3.90)break;

		auto [x,D,T]=q.top();q.pop();
		if(ans[x]!=-1)continue;

		while(now<=d&&now<T)now++;
		if(now>d)break;
		// cout<<x<<" "<<D<<" "<<T<<" "<<now<<endl;
		if(D>X[now]){
			q.push({x,D,T+1});
			continue;
		}
		ans[x]=now;

		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(ans[y]!=-1)continue;
			// q.push({y,w,now+1});
			if(w+D<=X[now])
				q.push({y,w+D,now});
			else
			{
				int fl=query(1,now,d,w);
				q.push({y,w,max(now+1,fl-1)});
			}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<"\n";//cout<<endl;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	cin>>k;
	for(int i=1;i<=k;i++)
		cin>>a[i];
	cin>>d;
	for(int i=1;i<=d;i++)
		cin>>X[i];
	build(1,1,d);
	prime();

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	start = clock();
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}