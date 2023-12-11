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
const int INF=1e9+7;
const int maxn=1e6+100;
char s[maxn];
ll n,m,k,ans;
void solve()
{
	cin>>n>>m>>k>>s+1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='x')cnt++;
		s[i+n]=s[i];
	}
	ans=(ll)(k/cnt);
	ans*=n;
	int T=n*2;
	if((int)(k/cnt)==m-1)T=n;
	else if((int)(k/cnt)==m)T=0;
	k%=cnt;
	ll ma=0;
	cnt=0;
	if(k&&T==n*2){
		for(int i=n,r=n;i>=1;i--)
		{
			if(s[i]=='x')cnt++;
			while(cnt<=k&&r<T)
			{
				if(cnt+(s[r+1]=='x'?1:0)>k)break;
				if(s[r+1]=='x')cnt++;
				r++;
			}
			while(cnt>k){
				if(s[r]=='x')cnt--;
				r--;
			}
			if(T==n*2&&r<n)break;
			ma=max(ma,1ll*(r-i+1));
		}
	}
	if(k)
	{
		cnt=(s[1]=='x'?1:0);
		for(int i=1,r=1;i<=n;i++)
		{
			while(cnt<=k&&r<n)
			{
				if(cnt+(s[r+1]=='x'?1:0)>k)break;
				if(s[r+1]=='x')cnt++;
				r++;
			}
			while(cnt>k){
				if(s[r]=='x')cnt--;
				r--;
			}
			if(s[i]=='x')cnt--;
			ma=max(ma,1ll*(r-i+1));
		}
	}
	
	// cout<<ma<<" "<<ans<<" "<<ma+ans<<endl;
	cout<<ma+ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}