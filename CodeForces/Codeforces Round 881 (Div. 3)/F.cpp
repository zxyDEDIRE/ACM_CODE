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
vector<int>v[maxn];
int dpa[maxn],ma[maxn];
int dpb[maxn],mi[maxn];
int n,tot;
void solve()
{
	cin>>n;
	tot=1;
	dpa[1]=1;
	dpb[1]=0;
	ma[1]=1;
	mi[1]=0;
	for(int i=1;i<=n;i++)
	{
		char op;
		cin>>op;
		if(op=='+')
		{
			++tot;
			int fa,w;
			cin>>fa>>w;

			if(dpa[fa]>0)
				dpa[tot]=dpa[fa]+w;
			else dpa[tot]=w;
			ma[tot]=max(ma[fa],dpa[tot]);


			if(dpb[fa]<0)
				dpb[tot]=dpb[fa]+w;
			else dpb[tot]=w;
			mi[tot]=min(mi[fa],dpb[tot]);

			// cout<<"tot:"<<tot<<" w:"<<w<<" fa:"<<fa<<" ma:"<<ma[tot]<<" mi:"<<mi[tot]<<endl;
		} 
		else if(op=='?')
		{
			int x,y,w;
			cin>>y>>x>>w;
			// cout<<"x "<<x<<" mi "<<mi[x]<<" ma "<<ma[x]<<endl;
			if(w>=mi[x]&&w<=ma[x])cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
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
/*
1
5
+ 1 -1
+ 1 -1
+ 3 1
+ 3 -1
+ 3 1
? 1 6 -1
? 1 6 2
*/