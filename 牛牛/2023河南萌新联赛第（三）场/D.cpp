/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int a,s;
void NO(){cout<<"No"<<endl;}
vector<int> get_num(int x)
{
	vector<int>v;
	while(x){
		v.push_back(x%2);
		x/=2;
	}
	while(v.size()<60)v.push_back(0);
	return v;
}
void solve()
{
	cin>>a>>s;
	if(s<a*2)return NO();
	vector<int>x=get_num(a);
	vector<int>y=get_num(s-a*2);
	for(int i=0;i<60;i++)
	{
		if(y[i]==1&&x[i]==1)
			return NO();
	}
	cout<<"Yes"<<endl;
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
1010
 1 1

20

10
26
*/