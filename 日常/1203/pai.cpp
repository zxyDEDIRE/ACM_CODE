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
const int maxn=4e3+100;
vector<pii>v;



class STL_1{
public:
	int f[maxn][23];
	int n,q;
	inline int find(int r,int t){
		return f[r][t]=(f[r][t]==r)?f[r][t]:find(f[r][t],t);
	}
	inline void un(int a,int b,int t)
	{
		int fa=find(a,t);
		int fb=find(b,t);
		f[fa][t]=fb;
	}
	inline void merge(int l,int r)
	{
		int L=n+(n-r+1);
		for(int i=21;i>=0;i--)
		{
			int t=(1<<i);
			if(l+t-1<=r)
			{
				un(l,L,i);
				l+=t;
				L+=t;
			}
		}
	}
	int solve(int _n,int _q)
	{
		n=_n;
		q=_q;
		for(int i=1;i<=n*2;i++)
			for(int j=0;j<=21;j++)
				f[i][j]=i;
		
		for(int i=1;i<=n;i++)
			un(i,n*2-i+1,0);

		for(int i=1;i<=q;i++)
		{
			int l,r;
			// cin>>l>>r;
			l=v[i-1].first;
			r=v[i-1].second;
			merge(l,r);
		}

		for(int t=21;t>=1;t--)
		{
			int len=(1<<(t-1));
			for(int i=1;i<=n*2;i++)
			{
				if(f[i][t]==i)continue;
				int l=i;
				int r=find(i,t);
				un(l,r,t-1);
				un(l+len,r+len,t-1);
			}
		}

		int cnt=0;
		for(int i=1;i<=n;i++)
			if(find(i,0)==find(i+n,0))cnt++;
		// if(cnt==n)cout<<"YES"<<endl;
		// else cout<<"NO"<<endl;
		// cout<<cnt<<endl;
		return cnt;
	}
};
class STL_2{
public:
	int f[maxn][23];
	int n,q;
	inline int find(int r,int t){
		return f[r][t]=(f[r][t]==r)?f[r][t]:find(f[r][t],t);
	}
	inline void un(int a,int b,int t)
	{
		int fa=find(a,t);
		int fb=find(b,t);
		// if(fa>fb)f[fb][t]=fa;
		// else f[fa][t]=fb;
		f[fa][t]=fb;
	}
	inline void merge(int l,int r)
	{
		int L=n+(n-r+1);
		for(int i=21;i>=0;i--)
		{
			int t=(1<<i);
			if(l+t-1<=r)
			{
				un(l,L,i);
				l+=t;
				L+=t;
			}
		}
	}
	int solve(int _n,int _q)
	{
		n=_n;
		q=_q;
		for(int i=1;i<=n*2;i++)
			for(int j=0;j<=21;j++)
				f[i][j]=i;
		
		for(int i=1;i<=n;i++)
			un(i,n*2-i+1,0);

		for(int i=1;i<=q;i++)
		{
			int l,r;
			// cin>>l>>r;
			l=v[i-1].first;
			r=v[i-1].second;
			merge(l,r);
		}
		for(int t=21;t>=1;t--)
		{
			int len=(1<<(t-1));
			for(int i=1;i<=n;i++)
			{
				if(f[i][t]==i)continue;
				int l=i;
				int r=find(i,t);
				un(l,r,t-1);
				un(l+len,r+len,t-1);
			}
		}

		
		
		// for(int i=1;i<=n*2;i++)
		// 	cout<<find(i,0)<<" ";cout<<endl;

		int cnt=n;
		for(int i=1;i<=n;i++)
			if(find(i,0)!=find(i+n,0))cnt--;
		return cnt;
	}
};
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 freopen("C:\\Users\\tob\\Desktop\\0.in","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);


 	srand(time(0));

	while(1)
	{
		// cout<<"A"<<endl;
		int n=1000,m=1000;
		v.resize(m);
		// cout<<"SDf"<<endl;
		for(int i=1;i<=m;i++)
		{
			int l=rand()%n+1;
			int r=rand()%n+1;
			while(l>r||l<=0||r<=0||l>n||r>n){
				l=rand()*7%(n+1)+31;
				r=rand()*7%(n+1)+31;
			}
			v[i-1]={l,r};
		}

		STL_1 a;
		STL_2 b;
		// cout<<"SDf"<<endl;
		int ans_1 = a.solve(n,m);
		int ans_2 = b.solve(n,m);
		// cout<<ans_1<<" "<<ans_2<<endl;
		if(ans_1!=ans_2)
		{
			cout<<n<<" "<<m<<endl;
			for(int i=0;i<m;i++)
				cout<<v[i].first<<" "<<v[i].second<<endl;
			exit(0);
		} 

	}



//  fclose(stdin);
 fclose(stdout);
	return 0;
}