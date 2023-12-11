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
			f[fa]=fb;
	}
}dsu;

struct node{
	int x,y,w;
}p[maxn];
int id[maxn];
int n,m;
void NO(){cout<<"NO\n";}
inline bool cross(int x1,int x2,int y1,int y2)
{
    if( x1 == x2 || y1 == y2 || x1 == y2 || x2 == y1 )
        return 0;
    if( x1 < x2 && y1 < y2 && x2 < y1 )
        return 1;
    if( x2 < x1 && y2 < y1 && x1 < y2 )
        return 1;
    return 0;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>p[i].x>>p[i].y,p[i].w=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		id[x]=i;
	}
	if(m>n*3+6)return NO();
	for(int i=1;i<=m;i++)
	{
		p[i].x=id[p[i].x];
		p[i].y=id[p[i].y];
		if(p[i].x>p[i].y)swap(p[i].x,p[i].y);
		if(p[i].x+1==p[i].y||(p[i].x==1&&p[i].y==n))
			p[i].w=1;
	}
	dsu.init(m*2+10);
	for(int i=1;i<=m;i++){
		if(p[i].w)continue;
		for(int j=i+1;j<=m;j++){
			if(p[j].w)continue;
			// if(cross(p[i],p[j]))
			if(cross(p[i].x,p[j].x,p[i].y,p[j].y))
			{
				if(!dsu.same(i,j))
				{
					dsu.merge(i,j+m);
					dsu.merge(i+m,j);
				}
				else return NO();
			}
		}
	}
	cout<<"YES\n";


}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}