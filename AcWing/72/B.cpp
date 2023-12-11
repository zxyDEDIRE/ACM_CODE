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
const ull str_mod=212370440130137957ll;
const ull more=19260817;
const ull prime=233317;
const ull base=131;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int a[maxn];
int n,m,sum;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		sum+=x;
		a[i]=x-y;
	}
	sort(a+1,a+1+n,[&](int a,int b){
		return a>b;
	});
	for(int i=0;i<=n;i++)
	{
		sum-=a[i];
		if(sum<=m){
			cout<<i<<endl;
			return ;
		}
	}
	cout<<-1<<endl;
}
signed main(){
//	freopen("C:\\Users\\19254\\Desktop\\P4011_2.in.txt","r",stdin);
//	freopen("C:\\Users\\19254\\Desktop\\P4011_2.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}