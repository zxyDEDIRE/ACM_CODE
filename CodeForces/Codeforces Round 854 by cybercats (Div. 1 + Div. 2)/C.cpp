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
	string str,t,s;
	vector<int>v;
	vector<int>cnt(40,0);

	cin>>str;
	for(auto i:str)
		cnt[i-'a']++;
	t=str;
	sort(t.begin(),t.end());
	for(int i=0;i<26;i++)
	{
		if(cnt[i]&1)v.push_back(i);
		for(int j=1;j<=(cnt[i]/2);j++)
			s=s+(char)(i+'a');
	}
	for(int i=1;i<v.size();i++)
		s=s+(char)(v[i]+'a');
	if(v.size())s=s+(char)(v[0]+'a');
	for(int i=25;i>=0;i--)
		for(int j=1;j<=(cnt[j]/2);j++)
			s=s+(char)(i+'a');
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
acaa
bbcca
bcacb

abba
bb
abbaa
abbcc

acffba
aabcff
acffba
*/