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
	cin>>n;
	vector<pii>s[5],t;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			char ch;
			cin>>ch;
			if(ch=='#')
				s[0].push_back({i,j});
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			char ch;
			cin>>ch;
			if(ch=='#')
				t.push_back({i,j});
		}
	sort(t.begin(),t.end());
	auto check=[&](int x)->bool{
		if(t.size()!=s[x].size())return 0;
		sort(s[x].begin(),s[x].end());
		int a=t[0].first-s[x][0].first;
		int b=t[0].second-s[x][0].second;
		for(int i=0;i<t.size();i++)
		{
			if(s[x][i].first+a!=t[i].first)return 0;
			if(s[x][i].second+b!=t[i].second)return 0;
		}
		return 1;
	};
	for(int i=1;i<4;i++)
	{
		for(auto [x,y]:s[i-1])
			s[i].push_back({y,-x});
	}
	for(int i=0;i<4;i++)
		if(check(i)){
			cout<<"Yes"<<endl;
			return ;
		}
	cout<<"No"<<endl;
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
3
.#.
###
...
...
.#.
###
*/