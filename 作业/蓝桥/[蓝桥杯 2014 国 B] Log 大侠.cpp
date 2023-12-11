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
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int x,y;
	bool operator<(const node&a)const{
		return a.x>x;
	}
};
int p[maxn];
set<node>s;
int n,m;
ll sum=0;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i],sum+=p[i],s.insert({i,p[i]});
	for(int _=1;_<=m;_++)
	{
		int l,r;
		cin>>l>>r;
		auto i=s.lower_bound({l,0});
		vector<node>v;
		for(i;i!=s.end();)
		{
			if((*i).x>r)break;
			int a=(*i).y;
			int b=(log2(a)+1);
			sum=sum-a+b;
			if(b!=2&&b!=1)
				v.push_back({(*i).x,b});
			s.erase(i++);
		}
		for(auto i:v)
			s.insert(i);
		cout<<sum<<endl;
	}

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}