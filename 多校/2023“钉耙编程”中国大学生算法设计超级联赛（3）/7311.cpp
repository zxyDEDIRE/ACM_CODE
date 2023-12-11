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
using pii=pair<int,vector<ll>>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=50005;
int ans[maxn];
pii p[maxn*3];
int n,m,cnt;
inline int check(vector<ll>&a,vector<ll>&b)
{
	int n=a.size(),i;
	int m=b.size();
	if(a[0]!=b[0])return a[0]<b[0]?-1:1;//gcd
	for(i=1;i<n&&i<m;i+=2)//拐
	{
		if(a[i]==0)return 0;//结尾
		if(a[i]!=b[i])return a[i]<b[i]?-1:1;//拐
		if(a[i+1]<b[i+1]){
			if(i+2>=n)return -1;
			return a[i+2]<b[i]?-1:1;
		}
		if(a[i+1]>b[i+1]){
			if(i+2>=m)return 1;
			return a[i]<b[i+2]?-1:1;
		}
	}
	if(n<m)return -1;
	if(n>m)return 1;
	return 0;
}
inline bool cmp(pii &a,pii &b)
{
	int ans=check(a.second,b.second);
	if(ans)return ans<0;
	return a.first<b.first;
}
inline vector<ll>get_num(ll x,ll y)
{
	vector<ll>w;
	while(1)
	{
		if(x==y)break;
		else if(x>y)
		{
			ll pre=x;
			x%=y;if(!x)x=y;
			w.push_back((pre-x)/y);
			w.push_back(-1ll);
		}
		else
		{
			ll pre=y;
			y%=x;if(!y)y=x;
			w.push_back((pre-y)/x);
			w.push_back(-2ll);
		}
	}
	w.push_back(x);
	reverse(w.begin(),w.end());
	return w;
}
inline void solve()
{
	cin>>n>>m;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		ll x,y;
		cin>>x>>y;
		vector<ll>w=get_num(x,y);
		p[++cnt]={0,w};
	}
	for(int i=1;i<=m;i++)
	{
		ll x,y;
		cin>>x>>y;
		vector<ll>w=get_num(x,y);
		p[++cnt]={-i,w};
		w.push_back(0ll);
		p[++cnt]={i,w};
		ans[i]=0;
	}
	sort(p+1,p+1+cnt,cmp);
	int num=0;
	for(int i=1;i<=cnt;i++)
	{
		auto [x,v]=p[i];
		if(x==0)num++;
		else if(x<0)ans[-x]-=num;
		else ans[x]+=num;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\in.txt","r",stdin);
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
2
3 4
6 9
5 3
1 1
6 3
1 2
2 1
5 3
2 2
7 14
7 14
7 7
7 14

6 9
*/