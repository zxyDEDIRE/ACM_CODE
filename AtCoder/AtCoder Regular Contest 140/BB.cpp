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
	vector<int>v;
	string str;
	int n;
	cin>>n>>str;
	for(int i=0;i<n;i++)
	{
		if(str[i]!='R')continue;
		int fl=0;
		while(
			i-fl-1>=0&&
			i+fl+1<n&&
			str[i-fl-1]=='A'&&
			str[i+fl+1]=='C'
		)fl++;
		if(fl)v.push_back(fl);
	}
	sort(v.begin(),v.end());
	int ans=0;
	multiset<int>s;
	for(auto i:v)
		s.insert(i);
	while(s.size())
	{
		if(ans%2==0)
		{
			ans++;
			int now=*s.rbegin();
			s.erase(s.find(now));
			now--;
			if(now)s.insert(now);
		}
		else
		{
			ans++;
			int now=*s.begin();
			s.erase(s.find(now));
			now--;
			// if(now)s.insert(now);
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}