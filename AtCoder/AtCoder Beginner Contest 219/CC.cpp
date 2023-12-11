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
map<char,int>mp;
vector<string>v;
string x;
int n;
void solve()
{
	cin>>x;
	for(int i=0;i<26;i++)
		mp[x[i]]=i;
	cin>>n;
	for(int i=1;i<=n;i++){
		string str;cin>>str;
		v.push_back(str);
	}
	sort(v.begin(),v.end(),[&](string a,string b){
		int len=min(a.size(),b.size());
		for(int i=0;i<len;i++)
		{
			if(a[i]==b[i])continue;
			return mp[a[i]]<mp[b[i]];
		}
		if(a.size()<=b.size())return true;
		return false;
	});
	for(auto i:v)
		cout<<i<<endl;
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