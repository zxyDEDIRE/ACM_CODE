/*！*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const ll mod=(1ll<<30);
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=1e2;
// map<int,set<int>>v;
set<int>v[maxn];
ll w[maxn];
int n,q;
void solve()
{
	// cin>>n>>q;
	n=N;
	q=N;
	ll ans=0;
	srand(time(0));
	while(q--)
	{
		cout<<q<<endl;
		int op,x,y,c;
		// cin>>op;
		op=rand()%4+1;
		if(op==1)
		{
			// cin>>x>>y;
			x=rand()%N+1;
			y=rand()%N+1;
			// x^=ans;
			// y^=ans;
			// cout<<"op "<<op<<" "<<x<<" "<<y<<endl;
			v[x].insert(y);
			v[y].insert(x);
		}
		else if(op==2)
		{
			// cin>>x>>y;
			x=rand()%N+1;
			y=rand()%N+1;
			// x^=ans;
			// y^=ans;
			// cout<<"op "<<op<<" "<<x<<" "<<y<<endl;
			if(v[x].count(y));
				v[x].erase(v[x].find(y));
			if(v[y].count(x))
				v[y].erase(v[y].find(x));
		}
		else if(op==3)
		{
			// cin>>x>>c;
			x=rand()%N+1;
			c=rand()%N+1;
			// x^=ans;
			// c^=ans;
			// cout<<"op "<<op<<" "<<x<<" "<<c<<endl;
			w[x]+=c;
		}
		else
		{
			// cin>>x;
			x=rand()%N+1;
			// x^=ans;
			// cout<<"op "<<op<<" "<<x<<endl;
			// ll now=w[x];
			// for(auto y:v[x]){
			// 	now=(now+w[y]);
			// }.
			// cout<<now<<endl;
			// ans=now%mod;
		}
	}
}
signed main(){
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		clock_t start, finish;
	start = clock();
	/*******代码*******/
	solve();
	/****************/
	finish = clock();
	cout << "the time cost is" <<\
	double(finish - start) / CLOCKS_PER_SEC;
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}