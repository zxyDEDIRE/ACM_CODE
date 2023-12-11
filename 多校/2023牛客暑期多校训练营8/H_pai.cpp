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
struct ST{
	int f[maxn][30];
	void init(int n,int *p)
	{
		for(int i=1;i<=n;i++)//距离为0初始化 
			f[i][0]=p[i];
		int t=log(n)/log(2)+1;//j定位 
		for(int j=1;j<t;j++)
		{
			for(int i=1;i<=n-(1<<j)+1;i++)
			{
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
				//f[i][j-1]为f[i][j]的长为2^j-1的前半段，另一段为f[i+(1<<(j-1))][j-1] 
			}
		} 
	}
	int query(int l,int r)
	{
		int k=log2(r-l+1);
		return max(f[l][k],f[r-(1<<k)+1][k]);
	}
}st;
vector<int>v[maxn];
int p[maxn];
int n;
int solve()
{
	for(int i=1;i<=n;i++)
		v[i].clear();
	for(int i=1;i<=n;i++){
		v[p[i]].push_back(i);
	}
	st.init(n,p);
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]!=1)continue;
		int l=i,r=n,ans=i;

		auto check=[&](int mid)->bool{
			int len=st.query(i,mid);
			int pre=0;
			// cout<<"len "<<len<<endl;
			for(int j=len;j>=1;j--)
			{
				int fa=lower_bound(v[j].begin(),v[j].end(),i)-v[j].begin();
				int fb=upper_bound(v[j].begin(),v[j].end(),mid)-v[j].begin();
				if(fb-fa<pre)return 0;
				mid=min(mid,v[j][fb-1]);
				pre=fb-fa;
			}
			return 1;
		};


		while(l<r-1)
		{
			int mid=(l+r)>>1;
			if(check(mid))ans=mid,l=mid;
			else r=mid;
		}
		while(ans<n&&check(ans+1))ans++;
		res+=ans-i+1;
	}
	return res;
}
int  cnt[222];
int solve_1()
{
	int ans=0;
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			memset(cnt,0,sizeof(cnt));
			int flag=1;
			for(int k=l;k<=r;k++)
			{
				cnt[p[k]]++;
				if(p[k]>1&&cnt[p[k]]>cnt[p[k]-1])flag=0;
			}
			ans+=flag;
		}
	}
	return ans;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	srand(time(0));

	n=20;
	while(1)
	{
		for(int i=1;i<=n;i++)
			p[i]=rand()%n+1;
		int ans_1=solve();
		int ans_2=solve_1();
		if(ans_1!=ans_2)
		{
			cout<<n<<endl;
			for(int i=1;i<=n;i++)
				cout<<p[i]<<" ";cout<<endl;
			cout<<ans_1<<" "<<ans_2<<endl;
			exit(0);
		}
	}
	


	return 0;
}
/*
20
19 7 10 13 3 9 12 12 11 15 11 1 2 4 15 18 11 3 9 10
*/