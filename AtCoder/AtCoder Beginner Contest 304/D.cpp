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
vector<pii>v[maxn];
map<pii,int>mp;
int pa[maxn];
int pb[maxn];
pii p[maxn];
int w,h,n,numa,numb;
void solve()
{
	cin>>w>>h>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	sort(p+1,p+1+n,[&](pii a,pii b){
		if(a.first!=b.first)return a.first<b.first;
		return a.second<b.second;
	});
	cin>>numa;
	for(int i=1;i<=numa;i++)
		cin>>pa[i];
	cin>>numb;
	for(int i=1;i<=numb;i++)
		cin>>pb[i];
	pa[0]=pb[0]=0;
	for(int i=1;i<=n;i++)
	{
		auto [x,y]=p[i];
		int fa=lower_bound(pa,pa+numa+1,x)-pa;
		int fb=lower_bound(pb,pb+numb+1,y)-pb;
		mp[{fa,fb}]++;
	}
	multiset<int>s;
	for(auto [x,num]:mp)
		s.insert(num);
	if(s.size()!=(numa+1)*(numb+1))cout<<0<<" ";
	else cout<<*s.begin()<<" ";
	cout<<*s.rbegin()<<endl;
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