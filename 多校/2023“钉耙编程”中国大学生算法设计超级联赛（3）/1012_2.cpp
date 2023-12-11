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
using pll=pair<ll,ll>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=4e6+100;
map<int,int>t[maxn][2];
vector<pii>v[maxn][2];
map<pii,int>root;
int num[maxn];
int n,q,indx;
bool cmp(pii a,pii b){
	return a.first<b.first;
}

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
vector<pii>get_num(ll x,ll y,ll g)
{
	vector<pii>w;
	while(x!=0&&y!=0)
	{
		if(x>y)w.push_back({0,x/y}),x%=y;
		else w.push_back({1,y/x}),y%=x;
	}
	reverse(w.begin(),w.end());
	return w;
}
void insert(vector<pii>w, int g)
{
	int _g=0;
	if(w[0].first==1)_g=0;
	else _g=1;

	if(!root.count({g,_g}))
		root[{g,_g}]=++indx;

	int rt=root[{g,_g}];
	for(auto [x,y]:w)
	{
		// cout<<rt<<" "<<x<<" "<<y<<endl;
		if(!t[rt][x].count(y))
			t[rt][x][y]=++indx;
		rt=t[rt][x][y];
		// cout<<"rt "<<rt<<endl;
		num[rt]++;
	}
	// cout<<endl;
}
int query(vector<pii>w,int g)
{ 
	int _g=0;
	if(w[0].first==1)_g=0;
	else _g=1;


	// cout<<"G "<<g<<endl;
	if(!root.count({g,_g})){
		// cout<<"SDF"<<endl;
		// cout<<0<<endl;
		return 0;
	}

	int rt=root[{g,_g}];
	int ans=0,fl=1;
	// for(auto [x,y]:w)
	for(int i=0;i<w.size();i++)
	{
		int x=w[i].first;
		int y=w[i].second;
		int flag=0;
		// cout<<rt<<" "<<x<<" "<<y<<" "<<i<<endl;
		if(!t[rt][x].count(y))
		{
			// cout<<"SDF"<<endl;
			fl=0;
			if(i!=w.size()-1)break;
			int fl=lower_bound(v[rt][x].begin(),v[rt][x].end(),pii{y,0})-v[rt][x].begin();
			if(fl==v[rt][x].size())break;
			if(fl==0)ans+=v[rt][x].back().second;
			else ans+=v[rt][x].back().second-v[rt][x][fl-1].second;
			break;
		}
		rt=t[rt][x][y];
		// cout<<"rt "<<rt<<" "<<i<<endl;
	}
	// cout<<endl;
	// cout<<"fl "<<fl<<endl;
	if(fl)ans+=num[rt];
	// cout<<ans<<endl;
	return ans;
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		ll x,y;
		cin>>x>>y;
		ll g=gcd(x,y);
		vector<pii>w=get_num(x,y,g);
		// cout<<"SIZE "<<w.size()<<endl;
		// for(auto [x,y]:w)
		// 	cout<<x<<" "<<y<<endl;
		insert(w,g);
		// cout<<endl;
	}
	// for(int i=1;i<=indx;i++)
	// {
	// 	cout<<"I "<<i<<endl;
	// 	for(auto [x,y]:v[i])
	// 		cout<<x<<" "<<y<<endl;
	// }cout<<endl;

	for(int i=1;i<=indx;i++)
	{
		v[i][0].clear();
		v[i][1].clear();
		for(auto j:t[i][0])v[i][0].push_back(j);
		for(auto j:t[i][1])v[i][1].push_back(j);
		sort(v[i][0].begin(),v[i][0].end());
		sort(v[i][1].begin(),v[i][1].end());
		if(v[i][0].size())
		{
			v[i][0][0].second=num[v[i][0][0].second];
			for(int j=1;j<v[i][0].size();j++)
				v[i][0][j].second=v[i][0][j-1].second+num[v[i][0][j].second];
		}
		if(v[i][1].size())
		{
			v[i][1][0].second=num[v[i][1][0].second];
			for(int j=1;j<v[i][1].size();j++)
				v[i][1][j].second=v[i][1][j-1].second+num[v[i][1][j].second];
		}
	}
	while(q--)
	{
		ll x,y;
		cin>>x>>y;
		// cout<<"X Y "<<x<<" "<<y<<endl;
		ll g=gcd(x,y);
		ll res=0;
		vector<pii>w=get_num(x,y,g);
		// cout<<"SIZE "<<w.size()<<endl;
		// for(auto [x,y]:w)
		// 	cout<<x<<" "<<y<<endl;
		if(x==y)
		{
			res+=query({{1,1}},g);
			res+=query({{0,1}},g);
		}
		else res+=query(w,g);
		cout<<res<<endl;
	}
 
	for(int i=1;i<=indx;i++)
	{
		t[i][0].clear();
		t[i][1].clear();
		num[i]=0;
	}
	root.clear();
	indx=0;
}
signed main(){
	// freopen("C:\\Users\\tob\\Desktop\\in.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
1 1
4 6
2 2

1
5 2
9 6
1 3
10 4
6 7
4 3
2 7
2 2

1
1 1
5 2
1 1

1
1 1
2 4
2 2

1
1 1
1 2
1 1
*/