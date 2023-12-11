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
pdd p[30];
int n=20;
double dis(int i,int j)
{
	double now=(p[i].first-p[j].first)*(p[i].first-p[j].first)+(p[i].second-p[j].second)*(p[i].second-p[j].second);
	// now=sqrt(now);
	return now;
}
bool ok(double a,int b)
{
	double x=b*b;
	double ans=abs(x-a);
	if(ans<=0.1)return 1;
	return 0;
}
void solve()
{
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].first>>p[i].second;
		p[i+n].first=p[i].first;
		p[i+n].second=p[i].second;
	}
	for(int i=2;i+1<=n*2;i++)
	{
		double x=dis(i-1,i);
		double y=dis(i,i+1);
		if(ok(x,9)&&ok(y,8))
		{
			pdd a={p[i].first-p[i-1].first,p[i].second-p[i-1].second};
			pdd b={p[i+1].first-p[i].first,p[i+1].second-p[i].second};
			double ans=a.first*b.second-b.first*a.second;
			// cout<<ans<<endl;
			if(ans>0)cout<<"right"<<endl;
			else cout<<"left"<<endl;
			return ;
		}
		else if(ok(x,8)&&ok(y,9))
		{
			pdd a={p[i-1].first-p[i].first,p[i-1].second-p[i].second};
			pdd b={p[i].first-p[i+1].first,p[i].second-p[i+1].second};
			double ans=a.first*b.second-b.first*a.second;
			// cout<<ans<<endl;
			if(ans>0)cout<<"right"<<endl;
			else cout<<"left"<<endl;
			return ;
		}
	}
	cout<<endl;
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