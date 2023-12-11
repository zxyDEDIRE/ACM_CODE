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
vector<int>v[30];
int val[1<<26];
int t[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		vector<int>cnt(30,0);
		cin>>s;
		for(auto j:s)
			cnt[j-'a']++;
		for(int j=0;j<26;j++)
		{
			if(cnt[j]&1)t[i]+=(1<<j);
			if(!cnt[j])v[j].push_back(i);
		}
			
	}
	ll ans=0;
	int T=(1<<26)-1;
	for(int i=0;i<26;i++)
	{
		for(auto x:v[i])
		{
			val[t[x]]++;
			ans+=val[t[x]^T^(1<<i)];
		}
		for(auto x:v[i])
			val[t[x]]--;
	}
	cout<<ans<<endl;
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
/*
10001
01100
*/