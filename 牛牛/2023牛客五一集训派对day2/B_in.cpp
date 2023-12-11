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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=2010;
pii p[maxn];
struct A{
	long long x[N],y[N];
	int n;
	bool check(int i,int j)
	{
	    return abs(x[i]*y[j]-x[j]*y[i])==0;
	} 
	map<pair<__int128,__int128>,int>mp;
	int A_1(int n,pii *p)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			x[i]=p[i].first,y[i]=p[i].second;
		if(n<=2)
			return n;
	    int mx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(check(i,j)) continue;
				__int128 tp=1.0*(x[i]*x[i]+y[i]*y[i])*y[j]-1.0*(x[j]*x[j]+y[j]*y[j])*y[i];
	            __int128 xx=2.0*x[i]*y[j]-2.0*x[j]*y[i];
	            __int128 tp1=(1.0*x[i]*x[i]+y[i]*y[i])*x[j]-1.0*(x[j]*x[j]+y[j]*y[j])*x[i];
	            __int128 yy=2.0*y[i]*x[j]-2.0*y[j]*x[i];
	            if(x[i]==0.0)
	            {
	                tp1=x[i]*x[i]+y[i]*y[i];
	                yy=2*y[i];
	            }
	            if(y[j]==0.0)
	            {
	                tp=x[j]*x[j]+y[j]*y[j];
	                xx=2*x[j];
	            }
	            if(x[j]==0.0)
	            {
	                tp1=x[j]*x[j]+y[j]*y[j];
	                yy=2*y[j];
	            }
	            if(y[i]==0.0)
	            {
	                tp=x[i]*x[i]+y[i]*y[i];
	                xx=2*x[i];
	            }
	            __int128 tx=(tp);
	            tx=tx*1e20/xx;
	            __int128 ty=tp1;
	            ty=ty*1e20/yy;
	           mp[{tx,ty}]++;
	            mx=max(mp[{tx,ty}],mx);
			}   
		}
	   
	    mx*=2;
	    for(int i=1;i<=n;i++)
	    {
	        if(i*(i-1)==mx)
	        {
	        	return i;
	        }
	    }
	}
}s1;
struct B{
	int n;
	double x[maxn],y[maxn];
	map<pii,int> res;
	int B_1(int k,pii *p)
	{
		n=k;
		for(int i=0;i<n;i++)
			x[i]=p[i+1].first,y[i]=p[i+1].second;
		int ans=0;
		for(int i=0;i<n;i++) {
			res.clear();
			for(int j=i+1;j<n;j++)
			{
				if(x[i]*y[j]==x[j]*y[i]) continue;
				double d=x[i]*y[j]-x[j]*y[i],d1=x[i]*x[i]+y[i]*y[i],d2=x[j]*x[j]+y[j]*y[j];
				double X=(y[i]*d2-y[j]*d1)/d,Y=(x[i]*d2-x[j]*d1)/d;
				ans=max(ans,++res[{X,Y}]);
			}
		}
		return ans+1;
	}
}s2;

signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n=5;
	srand(time(0));
	for(int i=1;i<=n;i++)
	{
		p[i].x=rand()%10;
		p[i].y=rand()%10;
	}
	int ans_1=s1().A_1();


//  fclose(stdin);
//  fclose(stdout);
	return 0;
}