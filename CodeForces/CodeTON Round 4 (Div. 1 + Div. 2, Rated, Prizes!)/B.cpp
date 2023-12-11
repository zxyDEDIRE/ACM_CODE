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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int n;
void solve()
{
	cin>>n;
	vector<int>v;
	while(n!=1)
	{
		if(n%2==0){
			cout<<-1<<endl;
			return ;
		}
		if(((n-1)/2)&1)n=(n-1)/2,v.push_back(2);
		else n=(n+1)/2,v.push_back(1);
	}
	reverse(v.begin(),v.end());
	cout<<v.size()<<endl;
	for(auto i:v)
		cout<<i<<" ";
	cout<<endl;
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