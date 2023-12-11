/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
int p[5];
void solve()
{
	int sum=0;
	for(int i=1;i<=3;i++)
		cin>>p[i],sum+=p[i];
	sort(p+1,p+1+3);
	int ma=0;
	// cout<<sum*sum<<endl;
	for(int i=1;i<=3;i++)
	{
		for(int j=i+1;j<=3;j++)
		{
			if(p[i]==p[j])ma=max(ma,sum*sum);
			else if((p[j]-p[i])%3==0)
				ma=max(ma,sum*sum);
			else
				ma=max(ma,(sum-1)*(sum-1)+1);
		}
	}
	cout<<ma<<endl;
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
1 3 4



0 1 10
2 0 9
1 2 8
3 1 7
2 3 6
1 5 5



0 6 7
2 5 6
4 4 5


2 3 5
*/