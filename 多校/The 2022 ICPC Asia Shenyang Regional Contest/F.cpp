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
const int maxn=5e6+100;
int p[maxn];
int a[maxn];
ll n,m,step;
ll get(ll x){return x*(x+1)/2;}
bool dfs(int len,int pr,ll s,ll t)
{
	if(s+len==t)
	{
		while(len--)p[step++]=1;
		return true;
	}
	if(pr==1)return false;
	if(s>t)return false;
	if(s+get(m)<t)return false;
	if(len==0)
	{
		if(s==t)return true;
		else return false;
	}
	if(s>=t)return false;
	int l=1,r=min(pr,len);
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(get(mid)+s+len-mid<=t)l=mid;
		else r=mid-1;
	}
	for(int i=r;i>=1;i--)
	{
		p[step++]=i;
		if(dfs(len-i,i,s+get(i),t))return true;
		step--;
	}
	return false;
}
void solve()
{
	cin>>n>>m;
	ll tp=get(n)*get(m);
	step=0;
	if(tp&1){cout<<"No"<<endl;return ;}
	if(n%4==0||(n+1)%4==0)
	{
		int T=dfs(n,n,0,get(n)/2);
		if(T==0){cout<<"No"<<endl;return ;}
		cout<<"Yes"<<endl;
		int fl=0,cnt=0;
		for(int i=0;i<step;i++){
			while(p[i]--)
				a[++cnt]=fl;
			fl^=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cout<<a[i]<<" ";
			cout<<endl;
		}
	}
	else if(m%4==0||(m+1)%4==0)
	{
		int T=dfs(m,m,0,get(m)/2);
		if(T==0){cout<<"No"<<endl;return ;}
		cout<<"Yes"<<endl;
		int fl=0,cnt=0;
		for(int i=0;i<step;i++){
			while(p[i]--)
				a[++cnt]=fl;
			fl^=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cout<<a[j]<<" ";
			cout<<endl;
		}
	}
	else cout<<"No"<<endl;
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