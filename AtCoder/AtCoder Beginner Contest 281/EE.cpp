/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int x,y;
	bool operator<(const node&a)const{
		if(y!=a.y)return y<a.y;
		else return x<a.x; 
	}
};
set<node>s,t;
int ans[maxn];
int p[maxn];
int a[maxn];
int n,m,k,sum;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=m;i++)
		s.insert({i,p[i]});

	for(int i=1;i<=k;i++)
	{
		auto [x,y]=*s.begin();
		t.insert({x,y});
		s.erase({x,y});
		sum+=y;
	}

	ans[m]=sum;


	s.erase({1,p[1]});
	if(t.count({1,p[1]})){
		sum-=p[1];
		t.erase({1,p[1]});
	}
	

	for(int i=m+1;i<=n;i++)
	{
		if(t.size()<k)
			t.insert({i,p[i]}),sum+=p[i]; 
		else
			s.insert({i,p[i]});

		// for(auto [x,y]:t)
			// cout<<x<<" "<<y<<endl;
		// cout<<endl;

		

		if(s.size())
		while((*t.rbegin()).y>(*s.begin()).y)
		{
			auto x=*s.begin();
			s.erase(x);
			t.insert(x);
			sum+=x.y;
			// cout<<sum<<endl;
			// cout<<"x"<<x.y<<" "<<sum<<endl;

			auto y=*t.rbegin();
			s.insert(y);
			t.erase(y);
			sum-=y.y;
			// cout<<"y"<<y.y<<" "<<sum<<endl;
			// cout<<endl;
		}

		// for(auto [x,y]:t)
		// 	cout<<x<<" "<<y<<endl;
		// cout<<endl;


		ans[i]=sum;



		int x=i-m+1;
		int y=p[x];
		s.erase({x,y});
		if(t.count({x,y})){
			sum-=y;
			t.erase({x,y});
		}

	}

	for(int i=m;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;






}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}