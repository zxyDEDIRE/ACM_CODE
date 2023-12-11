/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
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
void solve()
{
	string str;
	int n;
	cin>>n>>str;
	double ma=0;
	for(int i=0;i<n;i++)
	{
		vector<int>cnt(30,0);
		int sum=0;
		for(int j=i;j<n;j++)
		{
			int x=str[j]-'a';
			if(cnt[x]>0)sum+=cnt[x];
			cnt[x]++;
			if(j>i){
				ma=max(ma,1.0*sum/(j-i+1));
			}
		}
	}
	printf("%.10lf\n",ma);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}