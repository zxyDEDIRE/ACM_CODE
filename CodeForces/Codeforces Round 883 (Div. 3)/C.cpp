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
void solve()
{
	int n,m,h;
	cin>>n>>m>>h;
	vector<array<int,3>>q(n);
	for(int i=1;i<=n;i++)
	{
		vector<int>p(m);
		for(int j=0;j<m;j++)
			cin>>p[j];
		sort(p.begin(),p.end());
		int sum=0;
		int cnt=0;
		int now=0;
		for(auto j:p)
		{
			if(now+j<=h)
			{
				now+=j;
				sum+=now;
				cnt++;
			}
			else break;
		}
		q[i-1]={cnt,sum,i};
	};
	sort(q.begin(),q.end(),[&](array<int,3> a,array<int,3> b){
		if(a[0]!=b[0])return a[0]>b[0];
		if(a[1]!=b[1])return a[1]<b[1];
		return a[2]<b[2];
	});
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<=2;j++)
	// 		cout<<q[i][j]<<" ";cout<<endl;
	// }
	for(int i=0;i<n;i++)
		if(q[i][2]==1){
			cout<<i+1<<endl;
			return ;
		}
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