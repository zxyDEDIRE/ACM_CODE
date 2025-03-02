#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;


class Solution {
public:
	vector<int> findSubstring(string &s, vector<string>& words) {
		vector<int>ans;
		int m=words.size();
		int n=words[0].size();
		int len=s.size();

		for(int i=0;i<n&&i+m*n<len;i++)
		{
			map<string,int>mp;
			for(auto word:words)
				mp[word]++;


			
		}



		return ans;
	}
};


void solve()
{
	// vector<string>words{"foo","bar"};
	// string s = "barfoothefoobarman";
	vector<string>words{"fooo","barr","wing","ding","wing"};
	string s =  "lingmindraboofooowingdingbarrwingmonkeypoundcake";

	Solution a;
	a.findSubstring(s, words);


	// StringHash x,y;
	// string a="asd123";
	// string b="12a123";
	// for(auto i:a)
	// 	x.push_back(i);
	// for(auto i:b)
	// 	y.push_back(i);
	// cout<<x.get(4,6)<<endl;
	// cout<<y.get(4,6)<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}