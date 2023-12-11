#include<bits/stdc++.h>
using namespace std;
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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());//ull  大概率生成不相同数据
ll getRand(ll l,ll r){
    uniform_int_distribution < ll > uid(l,r);
    return uid(rng);
}
ll getRand(ll l,ll r,ll fl){
	ll now=getRand(l,r);
	while(now==fl)now=getRand(l,r);
	return now;
}
ll getRand(ll l,ll r,set<int>&s){
	ll now=getRand(l,r);
	while(s.count(now))
		now=getRand(l,r);
	return now;
}
vector<pp(3)>v[maxn];
signed main(int argc, char *argv[]){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n=atoi(argv[1]);
	int m=atoi(argv[2]);
	int M=m;
	int k=atoi(argv[3]);
	int q=atoi(argv[4]);
	// int Q=atoi(argv[5]);
	

	int s=getRand(1,n/2);
	int t=getRand(s+1,n);

	int T=1e9;

	vector<int>in(n+1,0);
	vector<pp(4)>p;
	while(m!=0)
	{
		int x=getRand(1,n);
		in[x]++;
		m--;
	}
	for(int i=1;i<=n;i++)
	{
		while(in[i])
		{
			int x=getRand(1,n,i);
			int w=getRand(1,T);
			int op=getRand(1,k);
			// v[x].push_back({x,w,op});
			p.push_back({i,x,w,op});
			in[i]--;
		}
	}
	shuffle(p.begin(),p.end(),rng);
	cout<<n<<" "<<M<<" "<<k<<" "<<s<<" "<<t<<endl;
	for(auto [x,y,w,op]:p)
		cout<<x<<" "<<y<<" "<<w<<" "<<op<<endl;
	cout<<q<<endl;

	while(q--)
	{
		int num=getRand(1,k);
		num=1;
		cout<<num<<endl;
		set<int>s;
		while(num--){
			int x=getRand(1,k,s);
			s.insert(x);
		}
		for(auto i:s)
			cout<<i<<" ";
		cout<<endl;
	}



	return 0;
}