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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18+7;
const int maxn=1e6+100;
struct node{
	int x,len;
}p[maxn];
int pre[maxn];
int l[maxn];
int r[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>l[i];
	for(int i=1;i<=n;i++)
		cin>>r[i];
	for(int i=1;i<=n;i++){
		p[i].x=r[i],p[i].len=r[i]-l[i]+1;
		pre[i]=pre[i-1]+p[i].len;
	}
	

	auto f=[&](int l,int r)->int{
		// cout<<l<<" "<<r<<endl;
		int num=2*(r-l+1);
		// cout<<num<<endl;
		int sum=pre[r]-pre[l-1];
		num+=p[r].x-(sum-k);
		// cout<<num<<endl;
		return num;
	};

	int ans=INF;
	int now=0;
	for(int i=1,j=1;i<=n;i++)
	{
		while(now<k&&j<=n){
			now+=p[j].len;
			j++;
		}
		if(now>=k){
			ans=min(ans,f(i,j-1));
			cout<<i<<" "<<j-1<<" "<<now<<" "<<f(i,j-1)<<endl;
		}
		now-=p[i].len;
	}
	if(ans==INF)cout<<-1<<endl;
	else cout<<ans<<endl;
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
10 8
2 2
4 4
6 6
8 8
10 13
15 15
17 17
19 19
21 21
23 26

10 8
2 4 6 8 10 15 17 19 21 23
2 4 6 8 13 15 17 19 21 26


10 13
23 26
26+4

*/