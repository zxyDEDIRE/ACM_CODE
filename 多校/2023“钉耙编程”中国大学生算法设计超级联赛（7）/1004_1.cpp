/*！*/
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
int p[maxn];
int mi=INF;
int n;
void doit()
{
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			vector<int>v;
			for(int k=i;k<=j;k++)
				v.push_back(p[k]);
			sort(v.begin(),v.end());
			int len=v.size();
			int mid=len/2;
			int cnt=0;
			for(auto x:v)
				if(x==v[mid])cnt++;
			ma=max(ma,cnt);
		}
	}
	mi=min(mi,ma);
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<"       \n"<<ma<<endl;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	doit();
}
signed main(){
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
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
16
1 1 1 3 3 3 2 2 3 1 3 2 3 3 1 1
 
*/

