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
int q[maxn],c;
bool vis[maxn];
void init(int n=maxn-10){
    vis[1]=true;
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            q[c++]=i;
        }
        for(int j=0;1ll*q[j]*i<=n;j++){
            int nu=q[j]*i;
            vis[nu]=true;
            if(i%q[j]==0){
                break;
            }
        }
    }
}

struct Edge{
	int to,next;
}edge[maxn];
int head[maxn],cnt=1;
int dfn[maxn],low[maxn],indx;
int in[maxn],tot;
stack<int>s;
vector<vector<int>>bcc;
int n;

void add(int from,int to){
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	in[x]=1;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			cout<<x<<" --> "<<y<<endl; 
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
		}
		else if(in[y]&&i!=(fa^1)&&dfn[y]<dfn[x]){
			cout<<"back "<<x<<" --> "<<y<<endl;
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(low[x]==dfn[x])
	{
		bcc.push_back(vector<int>());
		int y;
		do{
			y=s.top();s.pop();
			in[y]=0;
			bcc[tot].push_back(y);
		}while(x!=y);
		tot++;
	}
}
void solve()
{
	cin>>n;
	init(n);
	for(int i=1;i<=n;i++)
		for(int j=i+2;j<=min(i+400,n);j++)
			if(vis[abs(i-j)]==false){
				add(i,j);
				add(j,i);
				cout<<i<<" "<<j<<endl;
			}
			cout<<endl;
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i,0);
	for(int i=1;i<=n;i++)
		cout<<i<<" "<<dfn[i]<<" "<<low[i]<<endl;
	cout<<tot<<endl;
	for(int i=0;i<tot;i++)
	{
		for(auto x:bcc[i])
			cout<<x<<" ";cout<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}