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
const int maxn=1e6+100;
int siz[maxn];
int f[maxn];
int p[maxn];
int n;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void mul(vector<int>&a,int x)
{
	long long tp=0;
	for(int i=0;i<(int)a.size();i++)
	{
		tp+=a[i]*x;
		a[i]=tp%10;
		tp/=10;
	}
	while(tp)
	{
		a.push_back(tp%10);tp/=10;
	}
	while((int)a.size()>n+100) a.pop_back();
}

void solve()
{
	cin>>n;
	// n=100000;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		// if(i&1)p[i]=i+1;
		// else p[i]=i-1;
		f[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		int fa=find(i);
		int fb=find(p[i]);
		if(fa!=fb)
		{
			f[fa]=fb;
			siz[fb]+=siz[fa];
		}
	}
	map<int,int>mp;
	for(int i=1;i<=n;i++)
		if(f[i]==i){
			int x=siz[i];
			for(int j=2;j*j<=x;j++)
			{
				if(x%j==0){
					int cnt=0;
					while(x%j==0)
						x/=j,cnt++;
					mp[j]=max(mp[j],cnt);
				}
			}
			if(x!=1){
				mp[x]=max(mp[x],1);
			}
		}
	// for(auto i:v)
	// 	cout<<i<<" ";cout<<endl;
	vector<int>ans;
	ans.push_back(1);
	for(auto [v,u]:mp)
	{
		while(u--)
		mul(ans,v);
	}
	for(int i=min(n,(int)ans.size());i-1>=0;i--)
	{
		cout<<ans[i-1];
	}
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
/*
8
2 1 4 3 6 5 8 7
*/