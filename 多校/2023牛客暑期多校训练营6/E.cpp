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
int p[maxn];
int n,q;
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	while(q--)
	{
		int l,r,k,fl;
		cin>>l>>r>>k;
		int cnt=0;
		int sum=0;
		for(int i=l;i<=r;i++)
		{
			sum+=p[i];
			if((sum%2)==(p[l]%2))cnt++;
		}
		if(sum%2!=0)cout<<"NO"<<endl;
		else if(cnt<k)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}
signed main(){
 freopen("out.txt","r",stdin);
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
3 1
1 2 3
1 2 1

*/