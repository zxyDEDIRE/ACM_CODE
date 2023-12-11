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
int T[maxn];
int n,m;
namespace A{
	int p[maxn];
	int ans;
	void dfs(int x,int step,int mi,int ma)
	{
		if(step==m){
			ans=min(ans,ma-mi);
			return ;
		}
		if(x>n)return ;
		for(int i=x;i<=n;i++)
		{
			dfs(i+2,step+1,min(mi,p[i]),max(ma,p[i]));
		}
	}
	int solve()
	{
		// cin>>n>>m;
		if(m==1)return 0;
		for(int i=1;i<=n;i++)
		{
			// cin>>p[i];
			p[i]=T[i];
		}
		ans=INF;
		dfs(1,0,INF,0);
		return ans;
	}
}
namespace B{
	struct node{
		int x,y;
	}p[maxn];
	int t[maxn];
	int a[maxn];
	int b[maxn];
	int solve()
	{
		// cin>>n>>m;
		if(m==1)return 0;
		for(int i=1;i<=n;i++){
			// cin>>p[i].x;
			p[i].x=T[i];
			p[i].y=i;
		}
		sort(p+1,p+1+n,[&](node a,node b){
			return a.x<b.x;
		});a[1]=1;t[1]=0;
		for(int i=2;i<=n;i++)
		{
			if(abs(p[i].y-p[i-1].y)==1)
				t[i]=t[i-1]+1;
			else t[i]=0;
			if(t[i]%2==0)a[i]=1;
		}t[n]=0;b[n]=1;
		for(int i=n-1;i>=1;i--)
		{
			if(abs(p[i].y-p[i+1].y)==1)
				t[i]=t[i+1]+1;
			else t[i]=0;
			if(t[i]%2==0)b[i]=1;
		}
		int mi=INF;int r=1,cnt=0;
		for(int i=1;i<=n;i++){
			while(cnt<m&&r<=n){
				cnt+=a[r];
				r++;
			}
			if(r==i)r++;
			if(cnt==m)mi=min(mi,p[r-1].x-p[i].x);
			else break;
			cnt-=b[i];
		}
		// cout<<mi<<endl;
		return mi;
	}
}
signed main(){
	srand(time(0));
	while(true)
	{
		n=rand()%6+1;
		m=rand()%4+1;
		while(m>(n+1)/2)m=rand()%4+1;
		map<int,int>mp;
		for(int i=1;i<=n;i++)
		{
			T[i]=rand()%100;
			while(mp.count(T[i]))
				T[i]=rand()%100+1;
			mp[T[i]]=1;
		}
		int ans_1=A::solve();
		int ans_2=B::solve();
		if(ans_1!=ans_2)
		{
			cout<<ans_1<<" "<<ans_2<<endl;
			cout<<n<<" "<<m<<endl;
			for(int i=1;i<=n;i++)
				cout<<T[i]<<" ";cout<<endl;
			return 0;
		}

	}



	return 0;
}