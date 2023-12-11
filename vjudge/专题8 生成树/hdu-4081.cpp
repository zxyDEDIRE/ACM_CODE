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
const int N=1001;

class PrimMst{
public:
	struct node{
		int id;double dis;
		bool operator<(const node&a)const{
			return a.dis<dis;
		}
	};
	double maxD[N][N],mp[N][N];
	bool mst[N][N];
	double dis[N];
	bool vis[N];
	int pre[N];
	int n;
	PrimMst(){}
	void init(int _n){
		n=_n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				mp[i][j]=INF,mst[i][j]=maxD[i][j]=0;
			vis[i]=0;
			dis[i]=INF;
			pre[i]=1;
		}
	}
	double prim(int s=1)
	{
		priority_queue<node>q;
		q.push({s,dis[s]=0});
		double ans=0;
		while(!q.empty())
		{
			auto [x,W]=q.top();q.pop();
			if(vis[x])continue;
			vis[x]=1;
			ans+=W;
			mst[x][pre[x]]=mst[pre[x]][x]=1;
			for(int y=1;y<=n;y++){
				if(vis[y]&&mp[x][y]<INF)
					maxD[x][y]=maxD[y][x]=max(maxD[pre[x]][y],dis[x]);
				if(mp[x][y]<dis[y]){
					dis[y]=mp[x][y];
					pre[y]=x;
					q.push({y,dis[y]});
				}
			}
		}
		return ans;
	}
	void add(int x,int y,double w){mp[x][y]=w;}
	bool had(int x,int y){return mst[x][y];}
	double getmaxD(int x,int y){return maxD[x][y];}
}_mst;
pii p[maxn];
int w[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second>>w[i];
	_mst.init(n);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			double w=hypot(p[i].first-p[j].first,p[i].second-p[j].second);
			_mst.add(i,j,w);
			_mst.add(j,i,w);
		}
	double sum=_mst.prim();
	double ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(_mst.had(i,j)){
				ans=max(ans,(w[i]+w[j])/(sum-_mst.mp[i][j]));
			}
			else{
				ans=max(ans,(w[i]+w[j])/(sum-_mst.getmaxD(i,j)));
			}
		}
	}
	cout << fixed << setprecision(2) <<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
		// exit(0);
	return 0;
}