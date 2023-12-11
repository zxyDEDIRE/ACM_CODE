#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
const int INF = 1e9 + 1;
struct node {
	int x,y;
	bool operator<(const node &tem)const{return y > tem.y;}
};
int hd[N],nxt[N],to[N],cap[N],tot = 1,cur[N],flow[N],pre[N],lst[N];
double val[N],ans = 0,dis[N];
bool vis[N];
int s,t,n;
node p[N];
inline void add(const int u,const int v,const int z,const double k) {nxt[++tot] = hd[u],to[tot] = v,cap[tot] = z,val[tot] = k,hd[u] = tot;}
inline void adds(const int u,const int v,const int z,const double k) {add(u,v,z,k),add(v,u,0,-k);}
inline double calc(const int u,const int v) {return sqrt((double)(p[u].x - p[v].x) * (p[u].x - p[v].x) + (p[u].y - p[v].y) * (p[u].y - p[v].y));}
inline bool SPFA(){
	queue<int>Q;
	for(int i = 1; i <= t; i++) flow[i] = INF,dis[i] = INF,vis[i] = false;
	Q.push(s); vis[s] = 1; dis[s] = 0; pre[t] = -1;
	while (!Q.empty()) {
		int now = Q.front(); Q.pop(),vis[now]=0;
		for (int eg = hd[now]; eg ; eg = nxt[eg]) {
			int v = to[eg];
			if (cap[eg] && dis[v] > dis[now] + val[eg]){
				dis[v] = dis[now] + val[eg],pre[v] = now,lst[v] = eg;
				flow[v] = min(flow[now],cap[eg]);
				if (!vis[v]) vis[v] = true,Q.push(v);
			}
		}
	}
	return pre[t]!=-1;
}

int mcmf(){
	int sum = 0;
	while (SPFA()) {
		int now = t;
		sum += flow[t],ans += flow[t] * dis[t];
		while (now != s){
			now[lst][cap] -= flow[t];
			(now[lst] ^ 1)[cap] += flow[t];
			now = pre[now];
		}
	}
	return sum;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y;
	sort(p+1,p+1+n,[&](node a,node b){
		return a.y<b.y;
	});
	s=n*2+1;
	t=n*2+2;
	for(int i=1;i<=n;i++)
	{
		adds(s,i*2-1,2,0);
		adds(i*2,t,1,0);
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(p[i].y<p[j].y)
				adds(j*2-1,i*2,1,calc(i,j));
	if(mcmf() != n - 1) puts("-1");//如果说有父亲节点的节点个数不足 n - 1 个的话，那么就代表没有解
	else cout << fixed << setprecision(10)<<ans<<endl; 
}
signed main(){
 // freopen("data.in","r",ssdfsdftdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);cout.tie(nullptr);
//     cin>>n;
//     for(int i = 1; i <= n; i++)
//         cin>>p[i].x>>p[i].y;
//     sort(p + 1,p + 1 + n,[&](node a,node b){
//         return a.y<b.y;
//     });
//     s = n << 1 + 1,t = n << 1 + 2;
//     for(int i = 1; i <= n; i++) 
//         adds(s,i,2,0),adds(i + n,t,1,0);
//     for(int i = 1; i <= n; i++) 
//     for(int j = i + 1; j <= n; j++) 
//     if(p[i].y < p[j].y) adds(j,i + n,1,calc(i,j));//两点之间的连边。
//     if(mcmf() != n - 1) puts("-1");//如果说有父亲节点的节点个数不足 n - 1 个的话，那么就代表没有解
//     else cout << fixed << setprecision(10)<<ans<<endl; 
//     return 0;
// }