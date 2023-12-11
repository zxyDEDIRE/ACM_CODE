#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,ll>;
const ll INF=1e18;
const int maxn=4e6+100;
struct Edge{int to,w,next;}edge[maxn];
int head[maxn],cnt;
int dfn[maxn],low[maxn],indx;
stack<pii>s;
int n,m;
ll ans;
void init(){
	while(!s.empty())s.pop();
	memset(dfn+1,0,sizeof(int)*n);
	memset(low+1,0,sizeof(int)*n);
	memset(head+1,0,sizeof(int)*n);
	cnt=1; indx=0; ans=INF;
}
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void tarjan(int x,int fa){
	dfn[x]=low[x]=++indx;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			s.push({x,edge[i].w});
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x])
			{
				vector<ll>w;
				pii v;
				do{
					v=s.top();s.pop();
					w.push_back(v.second);
				}while(v.first!=x);

				sort(w.begin(),w.end());

				if(w.size()==1)ans=min(ans,w[0]);
				else if(w.size()==2)ans=min(ans,w[0]+w[1]);
				else ans=min(ans,min(w[0]+w[1],w[2]));
			}
		}
		else if(dfn[x]>dfn[y] &&i!=(fa^1))
		{
			low[x]=min(low[x],dfn[y]);
			s.push({x,edge[i].w});
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int T;cin>>T;
	while(T--){
		cin>>n>>m;
		init();
		for(int i=1;i<=m;i++){
			int x,y,w;
			cin>>x>>y>>w;
			add(x,y,w);
			add(y,x,w);
		}
		tarjan(1,0);
		cout<<ans<<endl;
	}
	return 0;
}