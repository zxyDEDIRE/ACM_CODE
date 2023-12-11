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
bitset<maxn>vis;
string str;
int cnt[10];
int n;
int ksm(int b,int p){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
int f(int x,int y)
{
	int ma=0;
	int ans=0;
	int flag=0;
	for(int i=n-1;i>=0;i--)
	{
		int now=str[i]-'A';
		if(flag==0&&now==x)now=y,flag=1;
		if(now<ma)
		{
			vis[i]=1;
			ans-=ksm(10,now);
		}
		else ans+=ksm(10,now);
		ma=max(ma,now);
	}
	return ans;
}
void solve()
{
	cin>>str;
	n=str.size();
	vis.reset();
	ll ans=0;
	int ma=0;
	vector<int>v;
	// cout<<n<<endl;
	memset(cnt,0,sizeof(cnt));
	for(int i=n-1;i>=0;i--)
	{
		int now=str[i]-'A';
		cnt[now]++;
		if(now<ma)
		{
			vis[i]=1;
			ans-=ksm(10,now);
			v.push_back(-ksm(10,now));
		}
		else ans+=ksm(10,now),v.push_back(ksm(10,now));
		ma=max(ma,now);
	}
	// reverse(v.begin(),v.end());
	// for(auto i:v)
	// 	cout<<i<<" ";cout<<endl;
	ll pre=0;
	ll res=ans;
	// cout<<ans<<endl;
	for(int i=0;i<n;i++)
	{
		int now=str[i]-'A';
		if(vis[i])
		{
			res=max(res,ans-pre*2+ksm(10,now)+ksm(10,4));
		}
		else
		{
			res=max(res,ans-pre*2-ksm(10,now)+ksm(10,4));
			if(now!=4)
				pre+=ksm(10,now);
		}
		// cout<<res<<endl;
	}
	for(int i=4;i>=1;i--)
	{
		for(int j=i-1;j>=0;j--)
		{
			res=max(res,f(i,j));
		}
	}
	cout<<res<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
 // fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
-1000 10000 -1 -1 -10 1000 100 1

1
EEEEEEEEEEEEEEEEEEEED
1
DDDDDDDDDDDDDDDDDDDD
19+10
200000
200009000
1
DDDDDDDDDDDDDDDDDDDE
*/