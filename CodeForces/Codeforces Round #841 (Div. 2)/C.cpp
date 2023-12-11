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
void solve()
{
	int n;
	cin>>n;
	// cout<<(int)sqrt(n)*n<<endl;
	vector<int>p(n+1,0);
	vector<int>mp(n*10,0);
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int s=0,ans=0;
	mp[0]=1;
	for(int i=1;i<=n;i++)
	{
		s^=p[i];
		for(int j=0;j*j<=n*2;j++)
			ans+=mp[(j*j)^s];
		mp[s]++;
	}
	cout<<(n*(n+1)/2-ans)<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\a.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\b.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// clock_t start, finish;
	// start = clock();
	int __;cin>>__;
	while(__--)
		solve();
	// finish = clock();
	//  cout << "the time cost is " << double(finish - start) / CLOCKS_PER_SEC;
 // fclose(stdin);
 // fclose(stdout);
	return 0;
}
/*
3
3 1
3 1 2
1
1 2
2
*/