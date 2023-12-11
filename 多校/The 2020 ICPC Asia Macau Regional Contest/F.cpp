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
vector<int>v[maxn];
int p[maxn];
int n,d,c;
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
void add(int x,int y){
	dsu.merge(x,y);
	v[x].push_back(y);
	v[y].push_back(x);
	p[x]--;
	p[y]--;
}
void f(int l,int r)
{
	int R=l+1;
	for(int i=l;i<=r;i++)
	{
		if(p[i]==0)continue;
		if(R<=i)R=i+1;
		for(int j=R;j<=r;j++)
			if(p[i]){
				add(i,j);
				R++;
			}
			else break;
		if(R>r)R=i+1;
		for(int j=R;j<=r;j++)
			if(p[i]){
				add(i,j);
				R++;
			}
			else break;
	}
}
void solve()
{
	cin>>n>>d>>c;
	dsu.init(n);
	if(1ll*(d+1)*c>n){
		// exit(-1);
		cout<<"No\n";
		return ;
	}
	if((n*d)&1) {
		// exit(-1);
		cout<<"No\n";
		return;
	}
	for(int i=1;i<=n;i++){
		p[i]=d;
		v[i].clear();
	}
	int tot=0;
	for(int i=1;i<c;i++)
		f(tot+1,tot+d+1),tot+=d+1;
	f(tot+1,n);
	int t=0;
	for(int i=1;i<=n;i++){
		if(dsu.find(i)==i) t++;
	}
	if(t!=c){
		// exit(-1);
		cout<<"No\n";
		return;
	}
	for(int i=1;i<=n;i++){
		if(p[i]){
			// exit(-1);
			cout<<"No\n";
			return;
		}
	}
	cout<<"Yes\n";
	for(int i=1;i<=n;i++)
	{
		sort(v[i].begin(),v[i].end());                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
		for(auto x:v[i])
			cout<<x<<" ";
		if(d)
		cout<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}
/*
49999 4 270

1000  200 1
*/