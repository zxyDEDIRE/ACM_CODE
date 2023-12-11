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
	int n;
	string s;
	vector<char>a;
	vector<char>b;
	multiset<char>st;
	cin>>s;
	n=s.size();
	for(auto i:s)
		st.insert(i);
	// cout<<*st.begin()<<endl;
	while(st.size()>=2)
	{
		char x=*st.begin();st.erase(st.find(x));
		char y=*st.begin();st.erase(st.find(y));
		if(x!=y){
			b.push_back(min(x,y));
			a.push_back(max(x,y));
			break;
		}
		else{
			a.push_back(x);
			b.push_back(x);
		}
	}
	reverse(b.begin(),b.end());
	for(auto i:a)
		cout<<i;
	for(auto i:st)
		cout<<i;
	for(auto i:b)
		cout<<i;
	cout<<endl;
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
/*
abbba
aaabbb
abbaba

bba
bab
*/