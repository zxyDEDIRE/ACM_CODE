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
char p[maxn];
char C[maxn];
int n;
void solve()
{
	cin>>n>>p+1;
	vector<pii>ans;
	vector<int>a,b;
	for(int i=1;i<=n;i++)
		if(p[i]=='0')a.push_back(i);
		else b.push_back(i);


	int l=b[0];
	int r=a.back();
	for(int i=0;i<a.size()-1;i++)
		ans.push_back({a[i],r});
	for(int i=1;i<b.size();i++)
		ans.push_back({l,b[i]});

	
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(i==l||j==r||i==r||j==l)continue;
			ans.push_back({i,j});	
		}
	}

	for(int i=a.size()+1;i<=n;i++)
		if(i!=r)ans.push_back({min(i,r),max(i,r)});
	for(int i=1;i<=a.size();i++)
		if(i!=l)ans.push_back({min(i,l),max(i,l)});

	// for(int i=a.size()+1;i<r;i++)
	// 	ans.push_back({i,r});
	// for(int i=n;i>r;i--)
	// 	ans.push_back({r,i});

	// for(int i=a.size();i>l;i--)
	// 	ans.push_back({l,i});
	// for(int i=1;i<l;i++)
	// 	ans.push_back({i,l});

	if(ans.size()==0){
		cout<<0<<endl;
		return ;
	}
	cout<<ans.size()<<endl;
	for(auto [x,y]:ans)
		cout<<x<<" "<<y<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
16
1010101010101010
1010101010100011

1
3
010
110

1
6
011001
010001
*/