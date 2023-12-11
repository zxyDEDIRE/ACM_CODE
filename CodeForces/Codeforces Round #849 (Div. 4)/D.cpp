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
map<int,int>mp1,mp2;
set<int>s1,s2;
string str;
int n;
void solve()
{
	mp1.clear();
	mp2.clear();
	s1.clear();
	s2.clear();
	cin>>n>>str;
	for(auto i:str){
		s1.insert(i-'a');
		mp1[i-'a']++;
	}
	int ans=s1.size();
	for(auto i:str)
	{
		int x=i-'a';
		mp2[x]++;
		s2.insert(x);

		mp1[x]--;
		if(!mp1[x])
			s1.erase(x);
		ans=max(ans,(int)(s1.size()+s2.size()));
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