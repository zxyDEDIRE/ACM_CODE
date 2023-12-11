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
const int d[]={-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int n,a,b,c;
int dfs(array<int,3>a,map<array<int,3>,bool>mp,string str="")
{
	// for(auto i:a)
	// 	cout<<i<<" ";cout<<endl;
	// _sleep(1000);
	str=str+"<"+to_string(a[0])+","+to_string(a[1])+","+to_string(a[2])+">";
	if(mp.count(a)){
	cout<<str<<endl;
		// cout<<"NO"<<endl;
		return 0;
	}
	mp[a]=true;
	set<int>s;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
		{
			array<int,3>b=a;
			b[i]+=d[j];
			if(b[i]<1||b[i]>n)continue;
			s.insert(dfs(b,mp,str));
		}
	}
	int now=0;
	for(auto i:s)
		if(i==now)now++;
	return now;
} 
void solve()
{
	cin>>n>>a>>b>>c;
	cout<<dfs({a,b,c},{})<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}