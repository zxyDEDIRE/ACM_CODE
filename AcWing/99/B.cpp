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
map<int,int>a,b;
int n,s;
void solve()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		char op;
		int x,y;
		cin>>op>>x>>y;
		if(op=='B')
		{
			a[x]+=y;
		}
		else if(op=='S')
		{
			b[x]+=y;
		}
	}
	vector<pii>sa,sb;
	for(auto [x,y]:a)
		sa.push_back({x,y});
	for(auto [x,y]:b)
		sb.push_back({x,y});
	sort(sa.begin(),sa.end(),[&](pii a,pii b){
		return a.first>b.first;
	});
	sort(sb.begin(),sb.end(),[&](pii a,pii b){
		return a.first<b.first;
	});
	for(int i=min(s,(int)sb.size())-1;i>=0;i--)
		cout<<"S "<<sb[i].first<<" "<<sb[i].second<<endl;
	for(int i=0;i<min(s,(int)sa.size());i++)
		cout<<"B "<<sa[i].first<<" "<<sa[i].second<<endl;
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