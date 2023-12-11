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
const int N=1e4;
class MatrixTree{
public:
	long long a[100][100];
	long long t[100][100];
	int n;
	void init(int _n){
		n=_n;
		memset(a,0,sizeof(a));
	}
	void add(int x,int y){
		a[x][x]++;
		a[y][y]++;
		a[x][y]--;
		a[y][x]--;
	}
	void del(int x,int y){
		a[x][x]--;
		a[y][y]--;
		a[x][y]++;
		a[y][x]++;
	}
	long long det(int n)
	{
		ll res=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				t[i][j]=a[i][j];
		for(int i=2;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				while(t[j][i]){
					ll T=t[i][i]/t[j][i];
					for(int k=i;k<=n;k++)
						t[i][k]=(t[i][k]-t[j][k]*T);
					for(int k=i;k<=n;k++)
						swap(t[i][k],t[j][k]);
					res=-res;
				}
			}
			if(t[i][i]==0)res=-res;
			res*=t[i][i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				printf("%2d ",t[i][j]);
				cout<<endl;
		}
		if(res<0)res=-res;
		return res;
	}
}mt;
vector<int>v[N];
int id[maxn],tot;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	tot=n;
	mt.init(n*2);
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
		mt.add(x,y);
	}

	for(int i=1;i<n;i++)
		cin>>p[i];
	for(int i=1;i<n;i++){
		int x=p[i];
		id[x]=++tot;
		for(auto y:v[x]){
			if(id[y]){
				mt.add(id[x],id[y]);
				mt.del(x,id[y]);
			}
			else{
				mt.add(id[x],y);
			}
		}
		cout<<mt.det(i+n)<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
5
1 2
1 3
2 4
2 5
1 5 2 3


6
1 2
1 3
2 4
2 5
6 2
6 3

1 5 2 3

*/