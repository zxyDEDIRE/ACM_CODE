/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/s
#include<bits/stdc++.h>
using namespace std;
#define int long long
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
int p[maxn];
int n,k,sum;
void solve()
{
	cin>>n>>k;
	k*=2;n--;
	for(int i=1;i<=n;i++)
		cin>>p[i],sum+=p[i];
	if(sum<k){
		cout<<n+1<<endl;
		return ;
	}
	int l=1,r=n,ans=r;

	auto check=[&](int len)->bool{
		int ans=0;
		for(int i=1;i<=len;i++)
			ans+=p[i];
		if(ans<k)return 0;
		for(int i=len+1;i<=n;i++)
		{
			ans=ans-p[i-len]+p[i];
			if(ans<k)return 0;
		}
		return 1;
	};
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	while(ans>1&&check(ans-1))ans--;
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}