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
int p[maxn];
int n,m;
void solve()
{
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
		cin>>p[i],mp[p[i]]++;
	sort(p+1,p+1+n);
	// for(int i=1;i<=n;i++)
	// 	cout<<p[i]<<" ";
	// cout<<endl;
	m=unique(p+1,p+1+n)-p-1;
	int ans=n/2,sum=0;
	for(int i=1;i<=m;i++)
	{
		sum+=mp[p[i]];
		ans=max(ans,sum*(n-sum));
	}
	cout<<ans<<endl;
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
/*
1 2 2 3 3 4 4 4 6 7 7 9

1 4 2 6 3 9 7

4 6 9
1 2 3 7
5
7

a=8 b=4
1 3 2 6 4 9 7
1 9 2 7 3 6 4
a=8 b=4


1 2 3
1 2 3
*/