#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=1e9+7;
const int maxn=1e3+100;
class DSU{
public:
	vector<int>f,num;
	DSU(){}
	void init(int n){
		f.resize(n+1);
		iota(f.begin(),f.end(),0);
	}
	int find(int r){
		return f[r]=f[r]==r?f[r]:find(f[r]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void merge(int x,int y){
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
			f[fb]=fa;
	}
}dsu;

class MstKru{
public:
	struct node{int x,y,w,fl;}p[maxn];
	bool mst[maxn][maxn];
	int maxD[maxn][maxn];
	vector<int>v[maxn];
	int n,m;
	MstKru(){}
	void init(int _n){
		n=_n;m=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mst[i][j]=0;
				maxD[i][j]=0;
			}
			v[i]={i};
		}
	}
	void add(int x,int y,int w){
		p[++m]={x,y,w};
	}
	int run()
	{
		sort(p+1,p+1+m,[&](node a,node b){return a.w<b.w;});
		dsu.init(n);
		ll ans=0;
		int cnt=n;
		for(int i=1;i<=m;i++)
		{
			auto &[x,y,w,fl]=p[i];
			if(!dsu.same(x,y))
			{
				cnt--;
				int fa=dsu.find(x);
				int fb=dsu.find(y);
				ans+=w;	fl=1;
				dsu.merge(x,y);
				for(auto _i:v[fa])
					for(auto _j:v[fb])
						maxD[_i][_j]=maxD[_j][_i]=w;
				for(auto _i:v[fb])
					v[fa].push_back(_i);
			}
			if(cnt==1)break;
		}
		if(cnt!=1)return -2;
		ll res=INF;
		for(int i=1;i<=m;i++)
		{
			if(p[i].fl)continue;
			auto [x,y,w,fl]=p[i];
			res=min(res,ans+w-maxD[x][y]);
		}
		if(res==INF)return -1;
		return res;
	}
}mst;


void solve()
{
	int n,m;
	cin>>n>>m;
	mst.init(n);
	for(int i=1;i<=m;i++){
		int x,y,w;cin>>x>>y>>w;
		mst.add(x,y,w);
	}
	int ans=mst.run();
	if(ans==-2)cout<<"No way\n";
	else if(ans==-1)cout<<"No second way\n";
	else cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	for(int i=1;i<=__;i++){
		cout<<"Case #"<<i<<" : ";
		solve();
	}
	return 0;
}
/*
Case #1 : No second way
*/