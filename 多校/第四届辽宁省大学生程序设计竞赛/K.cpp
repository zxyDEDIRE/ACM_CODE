#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
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
	node (){}
	node (int _x,int _y):x(_x),y(_y){}
	bool operator==(const node&a)const{
		if(a.x==x&&a.y==y)return 1;
		return 0;
	}
	bool operator<(const node&a)const{
		if(a.x!=x)return a.x>x;
		return a.y>y;
	}
	void in(){
		string str;cin>>str;
		x=str[0]-'A';
		if(str.size()==2)
			y=str[1]-'0';
		else y=10;
	}
};
vector<node>a(2),b(2),c(5);
map<node,int>mp;
map<vector<int>,double>ok;
double zhege(vector<node>now)
{
	vector<int>k;
	double sum=0;
	for(auto i:now)
		k.push_back(i.x),sum+=i.y;
	if(k.back()==6)k.pop_back();
	if(!ok.count(k))return sum;
	double B=ok[k];
	return 1.0*sum*B;
}
double ff(vector<node>a)
{
	int len=a.size();
	vector<double>dp(len+1,0);
	for(int i=0;i<len;i++)
	{
		if(i<len)
			dp[i+1]=max(dp[i+1],dp[i]+a[i].y);
		if(i+1<len)
			dp[i+2]=max(dp[i+2],dp[i]+zhege({a[i],a[i+1]}));
		if(i+2<len)
			dp[i+3]=max(dp[i+3],dp[i]+zhege({a[i],a[i+1],a[i+2]}));
	}
	return dp.back();
}
double f(vector<node>a)
{
	int len=a.size();
	vector<int>p(len);
	double ans=0;
	for(int i=0;i<len;i++)
		p[i]=i;
	// for(int j=0;j<20;j++)
	do{
		vector<node>now(len);
		for(int i=0;i<len;i++)
			now[i]=a[p[i]];
		ans=max(ans,ff(now));
	}
	while(next_permutation(p.begin(),p.end()));
	return ans;
}
double A(vector<node>x)
{
	double ans=0;
	vector<array<int,3>>F={
		{0,1,2},{0,1,3},{0,1,4},{0,2,3},{0,2,4},{0,3,4},
		{1,2,3},{1,2,4},{1,3,4},
		{2,3,4}
	};
	for(auto [_a,_b,_c]:F)
	{
		vector<node>now=x;
		now.push_back(c[_a]);
		now.push_back(c[_b]);
		now.push_back(c[_c]);
		ans=max(ans,f(now));
	}
	return ans;
}
double B(vector<node>x)
{
	double ans=0;
	for(int i=0;i<7;i++)
		for(int j=10;j>=9;j--)
			if(!mp.count(node(i,j))){
				vector<node>now=x;
				now.push_back(node(i,j));
				ans=max(ans,f(now));
			}
	return ans;
}
double Get(vector<node> a)
{
	double ans=0;
	ans=max(ans,A(a));
	// cout<<"A "<<ans<<endl;
	ans=max(ans,B(a));
	// cout<<"B "<<ans<<endl;
	return ans;
}
/*
0 1 2 3 4 5 6
水火草冰雷岩风
*/
void solve()
{
	mp.clear();
	a[0].in();mp[a[0]]=1;
	a[1].in();mp[a[1]]=1;
	b[0].in();mp[b[0]]=1;
	b[1].in();mp[b[1]]=1;
	for(int i=0;i<5;i++)
		c[i].in(),mp[c[i]]=1;

	double ans_a=0,ans_b=0;
	// for(int I=1;I<=100;I++)
	// {
		ans_a = Get(a);
		ans_b = Get(b);
		
	// }
	cout << fixed << setprecision(2) <<ans_a<<" "<<ans_b<<endl;
	if(ans_a>ans_b)cout<<"Win!\n";
	else cout<<"Lose!\n";
	
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	// 【水+火】蒸发反应，倍增系数2
	ok[{0,1}]=ok[{1,0}]=2;
	// 【水+冰】冻结反应，倍增系数1.5
	ok[{0,3}]=ok[{3,0}]=1.5;
	// 【水+雷】感电反应，倍增系数1.5
	ok[{0,4}]=ok[{4,0}]=1.5;
	// 【火+雷】超载反应，倍增系数1.5
	ok[{1,4}]=ok[{4,1}]=1.5;
	// 【火+草】燃烧反应，倍增系数1.5
	ok[{1,2}]=ok[{2,1}]=1.5;
	// 【火+冰】融化反应，倍增系数3
	ok[{1,3}]=ok[{3,1}]=3;
	// 【冰+雷】超导反应，倍增系数1.5
	ok[{3,4}]=ok[{4,3}]=1.5;
	// 【雷+草】激化反应，倍增系数2
	ok[{2,4}]=ok[{4,2}]=2;
	// 【水+草】绽放反应，倍增系数2
	ok[{0,2}]=ok[{2,0}]=2;
	// 【水+草+雷】超绽放反应，倍增系数4
	ok[{0,2,4}]=ok[{0,4,2}]=ok[{2,0,4}]=ok[{2,4,0}]=ok[{4,0,2}]=ok[{4,2,0}]=4;
	// 【水+草+火】烈绽放反应，倍增系数4
	ok[{0,1,2}]=ok[{0,2,1}]=ok[{1,0,2}]=ok[{1,2,0}]=ok[{2,0,1}]=ok[{2,1,0}]=4;
	// 【岩】不反应

	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1
E10 B9
D4 A2
G9 C4 C1 C2 B3
*/