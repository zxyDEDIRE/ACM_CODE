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
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int>p(n+1,0);
	vector<int>sum(n+1,0);
	priority_queue<int>q;
	priority_queue<int,vector<int>,greater<int>>Q;

	for(int i=1;i<=n;i++)
		cin>>p[i];

	int cnt = 0;
	int add = 0;

	for(int i=1;i<=m;i++)
		sum[i]=sum[i-1]+p[i];
	
	int num_m = sum[m];
	for(int i=m;i>=1;i--)
	{
		while(sum[i]<num_m)
		{
			num_m-=q.top()*2;
			q.pop(),cnt++;
		}
		q.push(p[i]);
	}

	num_m = p[m];sum[m]=p[m];
	for(int i=m+1;i<=n;i++)
	{
		sum[i]=sum[i-1]+p[i];
		Q.push(p[i]);
		while(sum[i]-add*2<num_m)
		{
			add+=Q.top();
			Q.pop();
			cnt++;
		}
	}

	cout<<cnt<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
10 4
345875723 -48 384678321 -375635768 -35867853 -35863586 -358683842 -81725678 38576 -357865873
*/