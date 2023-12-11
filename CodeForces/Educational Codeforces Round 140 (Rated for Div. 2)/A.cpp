/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
pii p[10];
void solve()
{
	for(int i=1;i<=3;i++)
		cin>>p[i].first>>p[i].second;
	int x=(p[1].first-p[2].first)*(p[1].first-p[2].first)+(p[1].second-p[2].second)*(p[1].second-p[2].second);
	int y=(p[1].first-p[3].first)*(p[1].first-p[3].first)+(p[1].second-p[3].second)*(p[1].second-p[3].second);
	int z=(p[3].first-p[2].first)*(p[3].first-p[2].first)+(p[3].second-p[2].second)*(p[3].second-p[2].second);
	vector<int>v{x,y,z};
	sort(v.begin(),v.end());
	int k=sqrt(v[0]);
	if(v[2]==v[1]+v[0]&&k*k==v[0])cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}