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
const int maxn=5e6+100;
int t[maxn][2];
int num[maxn];
int indx;
vector<int> get_num(int x){
	vector<int>v;
	while(x){
		v.push_back(x%2);x>>=1;
	}
	while(v.size()<20)v.push_back(0);
	reverse(v.begin(),v.end());
	return v;
}
void insert(int x)
{
	int rt=0;
	vector<int> v=get_num(x);
	for(auto y:v)
	{
		if(!t[rt][y])t[rt][y]=++indx;
		rt=t[rt][y];
		num[rt]++;
	}
}
int query(int x)
{
	vector<int>v = get_num(x);
	int ans=0;
	int rt=0;
	int flag=0;
	for(auto y:v)
	{
		ans+=num[t[rt][y]];
		rt=num[t[rt][y^1]];
		if(!rt)break;
	}
	// ans+=num[rt];
	return ans;
}
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		insert(x);
	}
	cout<<query(m)<<endl;
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
/*
001010

101

010
011
100
*/