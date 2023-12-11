/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int n;
int C(int x,int y)
{
	int ans=1;
	for(int i=1;i<=y;i++){
		ans=ans*x/i,x--;
		if(ans>n)return ans;
	}
	return ans;
}
bool ok(int k)
{
	int l=0,r=n,ans=0;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(C(k*2+mid,k)<=n)ans=mid,l=mid;
		else r=mid;
	}
	while(ans>1&&C(k*2+ans,k)>n)ans--;
	while(C(k*2+ans,k)<n)ans++;
	if(C(k*2+ans,k)==n)
	{
		int x=k*2+ans;
		int y=k;
		cout<<(x+1)*x/2+y+1<<endl;
		return 1;
	}
	else return 0;
}
void solve()
{
	cin>>n;
	if(n==1){
		cout<<1<<endl;
		return ;
	}
	for(int i=16;i>=1;i--)
		if(ok(i))
			break;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
*/