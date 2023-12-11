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
string p[maxn];
string str;
int n;
bool dfs(int x,int s,int y)
{
	if(x>2&&y==0){
		// for(int i=1;i<x;i++)
		// 	cout<<p[i]<<endl;
		return 1;
	}
	if(y==0)return 0;
	for(int i=1;i<=y;i++)
	{
		string now=str.substr(s,i);
		if(now<=p[x-1])continue;
		int flag=0;
		p[x]=now;
		flag = dfs(x+1,s+i,y-i);
		if(flag)return 1;
	}
	return 0;
}
void solve()
{
	cin>>n>>str;
	if(dfs(1,0,n))cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
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

*/